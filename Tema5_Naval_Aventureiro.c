#include <stdio.h>

#define TamanhoTabuleiro 10
#define TamanhoNavio 3

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro]) {
    for (int i = 0; i < TamanhoTabuleiro; i++) {
        for (int j = 0; j < TamanhoTabuleiro; j++) {
            tabuleiro[i][j] = 0;  // Representa água
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro]) {
    for (int i = 0; i < TamanhoTabuleiro; i++) {
        for (int j = 0; j < TamanhoTabuleiro; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro], int linha, int coluna) {
    if (coluna + TamanhoNavio > TamanhoTabuleiro) return 0; // Verifica se o navio está dentro dos limites

    // Verifica se as posições estão livres
    for (int j = 0; j < TamanhoNavio; j++) {
        if (tabuleiro[linha][coluna + j] != 0) return 0; // Verifica sobreposição
    }

    // Posiciona o navio
    for (int j = 0; j < TamanhoNavio; j++) {
        tabuleiro[linha][coluna + j] = 3;  // Representa parte do navio
    }
    return 1;
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro], int linha, int coluna) {
    if (linha + TamanhoNavio > TamanhoTabuleiro) return 0; // Verifica se o navio está dentro dos limites

    // Verifica se as posições estão livres
    for (int i = 0; i < TamanhoNavio; i++) {
        if (tabuleiro[linha + i][coluna] != 0) return 0; // Verifica sobreposição
    }

    // Posiciona o navio
    for (int i = 0; i < TamanhoNavio; i++) {
        tabuleiro[linha + i][coluna] = 3;  // Representa parte do navio
    }
    return 1;
}

// Função para posicionar um navio diagonalmente
int posicionarNavioDiagonal(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro], int linha, int coluna) {
    if (linha + TamanhoNavio > TamanhoTabuleiro || coluna + TamanhoNavio > TamanhoTabuleiro) return 0; // Verifica se o navio está dentro dos limites

    // Verifica se as posições estão livres
    for (int i = 0; i < TamanhoNavio; i++) {
        if (tabuleiro[linha + i][coluna + i] != 0) return 0; // Verifica sobreposição
    }

    // Posiciona o navio
    for (int i = 0; i < TamanhoNavio; i++) {
        tabuleiro[linha + i][coluna + i] = 3;  // Representa parte do navio
    }
    return 1;
}

int main() {
    int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Define as coordenadas para os navios
    int linhaNavioHorizontal1 = 1, colunaNavioHorizontal1 = 1;
    int linhaNavioHorizontal2 = 3, colunaNavioHorizontal2 = 7;
    int linhaNavioVertical1 = 5, colunaNavioVertical1 = 2; 
    int linhaNavioDiagonal1 = 0, colunaNavioDiagonal1 = 0; 
    int linhaNavioDiagonal2 = 0, colunaNavioDiagonal2 = 9;

    // Tenta posicionar os navios no tabuleiro
    if (!posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal1, colunaNavioHorizontal1)) {
        printf("Não foi possível posicionar o navio horizontal 1.\n");
    }
    if (!posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal2, colunaNavioHorizontal2)) {
        printf("Não foi possível posicionar o navio horizontal 2.\n");
    }
    if (!posicionarNavioVertical(tabuleiro, linhaNavioVertical1, colunaNavioVertical1)) {
        printf("Não foi possível posicionar o navio vertical 1.\n");
    }
    if (!posicionarNavioDiagonal(tabuleiro, linhaNavioDiagonal1, colunaNavioDiagonal1)) {
        printf("Não foi possível posicionar o navio diagonal 1.\n");
    }
    if (!posicionarNavioDiagonal(tabuleiro, linhaNavioDiagonal2, colunaNavioDiagonal2)) {
        printf("Não foi possível posicionar o navio diagonal 2.\n");
    }

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}