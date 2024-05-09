// Criar o tabuleiro e jogadores, zerar as variáveis
int velha = 0;
int linha = 0;
int coluna = 0;
bool haVencedor = false;
int tabuleiro[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

String jogador1 = "Jogador1";
String jogador2 = "Jogador2";
String jogada = "";
int jogadorDaVez = 1;

bool validaPosicao(String entrada) {
  /* Função para validar a entrada da jogada por meio de texto, o formato deve ser:
    Primeiro caracter: 0 ou 1 ou 2
    Segundo caracter: qualquer um
    Terceiro caracter: 0 ou 1 ou 2*/
  bool entradaValida = false;
  if (entrada.length() == 3) {
    if (entrada[0] == '0' || entrada[0] == '1' || entrada[0] == '2') {
      if (entrada[2] == '0' || entrada[2] == '1' || entrada[2] == '2') {
        entradaValida = true;
      }
    }
  }
  // Serial.print("validaPosicao() -> ");
  // Serial.println(entradaValida);
  return entradaValida;
}

void setup() {
  Serial.begin(115200); //Iniciar entrada serial
  for (int i = 0; i <= 8; i++) {
    tabuleiro[i] = 0;
  }
// Limpar/zerar o tabuleiro
  for (int i = 0; i <= 8; i++) {
    if (i == 3 || i == 6) {
      Serial.println("");
    }
    //Serial.print(tabuleiro[i]);
  }
}

void loop() {
  velha = 1;
  do {
    //imprime o tabuleiro inicial
    Serial.print(tabuleiro[0]);
    Serial.print(tabuleiro[1]);
    Serial.println(tabuleiro[2]);

    Serial.print(tabuleiro[3]);
    Serial.print(tabuleiro[4]);
    Serial.println(tabuleiro[5]);

    Serial.print(tabuleiro[6]);
    Serial.print(tabuleiro[7]);
    Serial.println(tabuleiro[8]);

    jogada = "";
    while (!Serial.available()); //espera a entrada de uma string 

    Serial.print("Digite a posição da sua peça JOGADOR");
    Serial.println(jogadorDaVez);
    jogada = Serial.readString();

    if (validaPosicao(jogada)) {
      
      linha = int(jogada[0]) - '0'; // Comverte a string em inteiro
      coluna = int(jogada[2]) - '0';

      Serial.print("Linha: ");
      Serial.print(linha);
      Serial.print(" Coluna: ");
      Serial.println(coluna);
       //Verifica se a jogada é valida

      if (tabuleiro[3 * linha + coluna] == 0) {
        tabuleiro[3 * linha + coluna] = jogadorDaVez;

        if ((tabuleiro[0] == jogadorDaVez && tabuleiro[1] == jogadorDaVez && tabuleiro[2] == jogadorDaVez) || (tabuleiro[3] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[5] == jogadorDaVez) || (tabuleiro[6] == jogadorDaVez && tabuleiro[7] == jogadorDaVez && tabuleiro[8] == jogadorDaVez)) {
          haVencedor = true; 
          // verifica jogada vencedora nas linhas

        } else {
          if ((tabuleiro[0] == jogadorDaVez && tabuleiro[3] == jogadorDaVez && tabuleiro[6] == jogadorDaVez) || (tabuleiro[1] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[7] == jogadorDaVez) || (tabuleiro[2] == jogadorDaVez && tabuleiro[5] == jogadorDaVez && tabuleiro[8] == jogadorDaVez)) {
            haVencedor = true;
            //verifica jogada vencedora nas colunas

          } else {
            if ((tabuleiro[0] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) || (tabuleiro[2] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[6] == jogadorDaVez)) {
              haVencedor = true;
              //verifica jogada vencedora nas diagonais

            } else {
              if (jogadorDaVez == 1) {
                jogadorDaVez = 2;
              } else {
                jogadorDaVez = 1;
                //muda de jogador
              }
            }
          }
        }

      } else {

        Serial.println("Posição ocupada, jogue novamente!!!");
        //informa o jogador que a posição está ocupada e ele precisa informar uma posição valida
      }
    } else {
      Serial.println("Jogada inválida!!!");
      velha = velha + 1;
    }
  } while (!haVencedor && velha <= 9);

  //verificar o tabuleiro, se houver ganhador ou empate, finalizar o jogo.
  if (haVencedor) {
    Serial.println("Parabéns pela vitória, jogador" && jogadorDaVez);
  } else {
    Serial.println("Deu VELHA!!!");
  }

  //imprime o tabuleiro final
  Serial.print(tabuleiro[0]);
  Serial.print(tabuleiro[1]);
  Serial.println(tabuleiro[2]);

  Serial.print(tabuleiro[3]);
  Serial.print(tabuleiro[4]);
  Serial.println(tabuleiro[5]);

  Serial.print(tabuleiro[6]);
  Serial.print(tabuleiro[7]);
  Serial.println(tabuleiro[8]);
}
