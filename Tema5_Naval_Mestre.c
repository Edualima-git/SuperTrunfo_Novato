#include <stdio.h>

#define TamanhoTabuleiro 10
#define TamanhoHabilidade 5

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro]) {
    for (int i = 0; i < TamanhoTabuleiro; i++) {
        for (int j = 0; j < TamanhoTabuleiro; j++) {
            tabuleiro[i][j] = 0; 
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro]) {
    for (int i = 0; i < TamanhoTabuleiro; i++) {
        for (int j = 0; j < TamanhoTabuleiro; j++) {
            // Água (0), Navio (3), Área afetada pela habilidade (5)
            if (tabuleiro[i][j] == 0) {
                printf("%2d ", tabuleiro[i][j]);
            } else if (tabuleiro[i][j] == 3) {
                printf("%2d ", tabuleiro[i][j]);
            } else if (tabuleiro[i][j] == 5) {
                printf(" * "); // Representa a área afetada
            }
        }
        printf("\n");
    }
}

// Função para posicionar o cone no tabuleiro
void adicionarHabilidadeCone(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro], int origemLinha, int origemColuna) {
    int i, j;
    for (i = 0; i < TamanhoHabilidade; i++) {
        for (j = 0; j <= i; j++) {
            if (origemLinha + i < TamanhoTabuleiro && origemColuna + j < TamanhoTabuleiro) {
                tabuleiro[origemLinha + i][origemColuna + j] = 5; // Marca a área afetada
            }
            if (origemLinha + i < TamanhoTabuleiro && origemColuna - j >= 0) {
                tabuleiro[origemLinha + i][origemColuna - j] = 5; // Marca a área afetada
            }
        }
    }
}

// Função para posicionar a cruz no tabuleiro
void adicionarHabilidadeCruz(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro], int origemLinha, int origemColuna) {
    int i, j;
    for (i = 0; i < TamanhoTabuleiro; i++) {
        for (j = 0; j < TamanhoTabuleiro; j++) {
            if (i == origemLinha || j == origemColuna) {
                if (i < TamanhoTabuleiro && j < TamanhoTabuleiro) {
                    tabuleiro[i][j] = 5; // Marca a área afetada
                }
            }
        }
    }
}

// Função para posicionar o octaedro no tabuleiro
void adicionarHabilidadeOctaedro(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro], int origemLinha, int origemColuna) {
    int i, j;
    for (i = -2; i <= 2; i++) {
        for (j = -2; j <= 2; j++) {
            // Formato de losango
            if ((i + j) <= 2) {
                if (origemLinha + i >= 0 && origemLinha + i < TamanhoTabuleiro &&
                    origemColuna + j >= 0 && origemColuna + j < TamanhoTabuleiro) {
                    tabuleiro[origemLinha + i][origemColuna + j] = 5; // Marca a área afetada
                }
            }
        }
    }
}

// Função principal
int main() {
    int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Define as coordenadas dos navios
    tabuleiro[1][1] = 3; // Navio horizontal
    tabuleiro[3][7] = 3; // Navio horizontal
    tabuleiro[5][2] = 3; // Navio vertical
    tabuleiro[0][0] = 3; // Navio diagonal

    // Adiciona as habilidades no tabuleiro
    adicionarHabilidadeCone(tabuleiro, 0, 3);  
    adicionarHabilidadeCruz(tabuleiro, 4, 4);   
    adicionarHabilidadeOctaedro(tabuleiro, 2, 2); 

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval com Habilidades:\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}