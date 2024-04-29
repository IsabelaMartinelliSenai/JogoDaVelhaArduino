function main() {
    // Criar o tabuleiro e jogadores, zerar as variaveis.
    // 
    // 0: Posição vazia
    // 1: Jogada na posição do jogador 1
    // 2: Jogada na posição do jogador 2
    var velha;
    var haVencedor;

    haVencedor = false;
    var tabuleiro = Array(9);

    // Zerar o tabuleiro
    var index;

    for (index = 0; index <= 8; index++) {
        tabuleiro[index] = 0;
    }
    var jogador1;

    jogador1 = "Jogador1";
    var jogador2;

    jogador2 = "Jogador2";
    var jogada;

    // Iniciar o jogo, definir quem joga primeiro
    var jogadorDaVez;

    jogadorDaVez = 1;

    // Anotar/Registrar a jogada do primeiro jogador
    var linha;
    var coluna;

    velha = 1;
    var texto;

    texto = "";
    do {
         console.log(tabuleiro[0].toString() + tabuleiro[1] + tabuleiro[2]);
         console.log(tabuleiro[3].toString() + tabuleiro[4] + tabuleiro[5]);
         console.log(tabuleiro[6].toString() + tabuleiro[7] + tabuleiro[8]);
        jogada = "";
         console.log("Digite a posição da sua peça Jogador" + jogadorDaVez);
        jogada = window.prompt('Enter a value for jogada');
        if (validaPosicao(jogada)) {
            if (jogada.length == 3) {
                linha = parseInt(jogada.charAt(0));
                coluna = parseInt(jogada.charAt(2));
            } else {
                linha = parseInt(jogada.charAt(0));
                coluna = parseInt(jogada.charAt(2));
            }
             console.log("Linha: " + linha + "Coluna: " + coluna);

            // Verificar se a 'jogada' é valida
            // Converter a jogada texto em dois inteiros linha e coluna
            if (tabuleiro[3 * linha + coluna] == 0) {
                tabuleiro[3 * linha + coluna] = jogadorDaVez;
                tabuleiroValido = validaTabuleiro(jogadorDaVez, tabuleiro);
            } else {
                 console.log("Posição ocupada, jogue novamente");

                // Informar ao jogador 1 que a posição está preenchida, é inválida e ele precisa informar uma posição válida
            }
        } else {
             console.log("Posição invalida");
        }

        // Verificar o tabuleiro, se houve ganhador ou empate, finalizar o jogo
        // Verificar jogada vencedora nas linhas
    } while (tabuleiroValido == 0);
    if (tabuleiroValido < 9) {
         console.log("Vencedor: Jogador " + jogadorDaVez);
    } else {
         console.log("Empate");
    }
     console.log(tabuleiro[0].toString() + tabuleiro[1] + tabuleiro[2]);
     console.log(tabuleiro[3].toString() + tabuleiro[4] + tabuleiro[5]);
     console.log(tabuleiro[6].toString() + tabuleiro[7] + tabuleiro[8]);
}

function validaPosicao(entrada) {
    var entradaValida;

    entradaValida = false;
     console.log(entrada.length);
    if (entrada.length == 3) {
        if (entrada.charAt(0) == "0" || entrada.charAt(0) == "1" || entrada.charAt(0) == "2") {
            if (entrada.charAt(2) == "0" || entrada.charAt(2) == "1" || entrada.charAt(2) == "2") {
                entradaValida = true;
            }
        }
    } else {
        if (entrada.length == 2) {
            if (entrada.charAt(0) == "0" || entrada.charAt(0) == "1" || entrada.charAt(0) == "2") {
                if (entrada.charAt(1) == "0" || entrada.charAt(1) == "1" || entrada.charAt(1) == "2") {
                    entradaValida = true;
                }
            }
        }
    }
    
    return entradaValida;
}

function validaTabuleiro(jogadorDaVez, tabuleiro) {
    var resultado;

    resultado = 0;
    if (tabuleiro[0] == jogadorDaVez && tabuleiro[1] == jogadorDaVez && tabuleiro[2] == jogadorDaVez || tabuleiro[3] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[5] == jogadorDaVez || tabuleiro[6] == jogadorDaVez && tabuleiro[7] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
        HaVencedor = true;
    } else {

        // Verificar jogada vencedora nas colunas
        if (tabuleiro[0] == jogadorDaVez && tabuleiro[3] == jogadorDaVez && tabuleiro[6] == jogadorDaVez || tabuleiro[1] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[7] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[5] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
            HaVencedor = true;
        } else {

            // Verificar jogada vencedora nas diagonais
            if (tabuleiro[0] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[8] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[6] == jogadorDaVez) {
                HaVencedor = true;
            } else {
                if (jogadorDaVez == 1) {
                    jogadorDaVez = 2;
                } else {
                    jogadorDaVez = 1;
                }
            }
        }
    }
    velha = velha + 1;
    
    return resultado;
}
