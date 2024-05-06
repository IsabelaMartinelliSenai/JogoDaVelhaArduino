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
  bool entradaValida = false;
  if (entrada.length() == 3) {
    if (entrada[0] == '0' || entrada[0] == '1' || entrada[0] == '2') {
      if (entrada[2] == '0' || entrada[2] == '1' || entrada[2] == '2') {
        entradaValida = true;
      }
    }
  }
  return entradaValida;
}

void setup() {
  Serial.begin(115200);
  for (int i = 0; i <= 8; i++) {
    tabuleiro[i] = 0;
  }

  for (int i = 0; i <= 8; i++) {
    if (i == 3 || i == 6) {
      Serial.println("");
    }
    Serial.print(tabuleiro[i]);
  }
}

void loop() {
  velha = 1;
  do {
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
    Serial.print("Digite a posição da sua peça JOGADOR");
    Serial.println(jogadorDaVez);
    String ler = Serial.readString();
    if (validaPosicao(jogada)) {
      linha = int(jogada[0]);
      coluna = int(jogada[2]);
      Serial.print("Linha: ");
      Serial.print(linha);
      Serial.print("Coluna: ");
      Serial.println(coluna);
      if (tabuleiro[3 * linha + coluna] == 0) {
        tabuleiro[3 * linha + coluna] = jogadorDaVez;

        if (tabuleiro[0] == jogadorDaVez && tabuleiro[1] == jogadorDaVez && tabuleiro[2] == jogadorDaVez || tabuleiro[3] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[5] == jogadorDaVez || tabuleiro[6] == jogadorDaVez && tabuleiro[7] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
          haVencedor = true;
        } else {
          if (tabuleiro[0] == jogadorDaVez && tabuleiro[3] == jogadorDaVez && tabuleiro[6] == jogadorDaVez || tabuleiro[1] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[7] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[5] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
            haVencedor = true;
          } else {
            if (tabuleiro[0] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[8] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[6] == jogadorDaVez) {
              haVencedor = true;
            } else {
              if (jogadorDaVez == 1) {
                jogadorDaVez = 2;
              } else {
                jogadorDaVez = 1;
              }
            }
          }
        }

      } else {
        Serial.println("Posição ocupada, jogue novamente!!!");
      }
    } else {
      Serial.println("Jogada inválida!!!");
      velha = velha + 1;
    }
  } while (!haVencedor && velha <= 9);
  if (haVencedor) {
    Serial.println("Parabéns pela vitória, jogador" && jogadorDaVez);
  } else {
    Serial.println("Deu VELHA!!!");
  }
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