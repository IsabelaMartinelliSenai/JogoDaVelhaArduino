int velha = 0;
int linha = 0;
int coluna = 0;
bool haVencedor = false;
int tabuleiro[9];

String jogador1 = "Jogador1";
String jogador2 = "Jogador2";
String jogada = "";
int jogadorDaVez = 1;

bool validaPosicao (String entrada) {
  bool entradaValida = false;
  if (entrada.length() == 3) {
    if
  }
}

void setup() {
 Serial.begin(115200);
  	for(int i = 0; i <= 8; i++){
  		tabuleiro[i] = 0;
	}
  
  	for(int i = 0; i <= 8; i++){
      if( i == 3 || i == 6 ){
      	Serial.println("");
      }
  		Serial.print(tabuleiro[i]);
	}
}

void loop() {
  velha = 1;
  if (Serial.available() != 0 ){
    do {
    Serial.println (tabuleiro[0] + tabuleiro[1] + tabuleiro[2]);
    

    Serial.println (tabuleiro[3] + tabuleiro[4] + tabuleiro[5]);
    Serial.println (tabuleiro[6] + tabuleiro[7] + tabuleiro[8]);
    jogada = "";
    Serial.println ("Digite a posição da sua peça JOGADOR" && jogadorDaVez);
    Serial.readString(jogada);
    if (validaPosicao(jogada)) {
      linha = toInt(jogada[0]);
      coluna = toInt(jogada[2]);
      Serial.println ("Linha: " + linha + "Coluna: " + coluna);
      if(tabuleiro[3 * linha +coluna] == 0) {
        tabuleiro[3 * linha + coluna] = jogadorDaVez;
        if(tabuleiro[0] == jogadorDaVez && tabuleiro[1] == jogadorDaVez && tabuleiro[2] == jogadorDaVez)||(tabuleiro[3] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[5] == jogadorDaVez)||(tabuleiro[6] == jogadorDaVez && tabuleiro[7] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
        haVencedor = true;
      } else {
        if(tabuleiro[0] == jogadorDaVez && tabuleiro[3] == jogadorDaVez && tabuleiro[6] == jogadorDaVez)||(tabuleiro[1] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[7] == jogadorDaVez)||(tabuleiro[2] == jogadorDaVez && tabuleiro[5] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
          haVencedor = true;
        } else {
          if(tabuleiro[0] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[8] == jogadorDaVez)||(tabuleiro[2] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[6] == jogadorDaVez) {
            haVencedor = true;
      }  
     }
    }while()
  }
}  
   
