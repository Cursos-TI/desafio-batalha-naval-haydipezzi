#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar o tabuleiro 10x10 inicializado com 0
void gerarTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // Inicializa todas as posições com 0 (água)
        }
    }
}

// Função para verificar se a posição é válida (não há navio e dentro dos limites)
int posicaoValida(int tabuleiro[10][10], int linha, int coluna) {
    return linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && tabuleiro[linha][coluna] == 0;
}

// Função para posicionar navio na diagonal
int posicionarNavioDiagonal(int tabuleiro[10][10], int tipo) {
    for (int i = 0; i < 10; i++) {
        if (tabuleiro[i][i] == 0) {
            tabuleiro[i][i] = tipo;  // Coloca o navio na posição diagonal (i, i)
            return 1; // Sucesso
        }
    }
    return 0; // Não foi possível posicionar
}

// Função para posicionar um navio aleatório no tabuleiro
int posicionarNavioAleatorio(int tabuleiro[10][10], int tipo) {
    for (int tentativas = 0; tentativas < 100; tentativas++) {  // Limite de tentativas
        int linha = rand() % 10;
        int coluna = rand() % 10;
        if (posicaoValida(tabuleiro, linha, coluna)) {
            tabuleiro[linha][coluna] = tipo;  // Posiciona o navio
            return 1;  // Sucesso
        }
    }
    return 0;  // Não foi possível posicionar
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);  // Exibe cada célula
        }
        printf("\n");
    }
}

// Função principal para simular o jogo
int main() {
    int tabuleiro[10][10];

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Gera o tabuleiro
    gerarTabuleiro(tabuleiro);

    // Posiciona dois navios na diagonal
    posicionarNavioDiagonal(tabuleiro, 3);  // Navio tipo 3 na diagonal
    posicionarNavioDiagonal(tabuleiro, 3);  // Outro navio tipo 3 na diagonal

    // Posiciona dois navios aleatórios
    posicionarNavioAleatorio(tabuleiro, 3);
    posicionarNavioAleatorio(tabuleiro, 3);

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
