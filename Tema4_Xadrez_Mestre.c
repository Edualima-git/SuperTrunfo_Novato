#include <stdio.h>

// Função recursiva para mover a Torre
void moverTorre(int casas) {
    if (casas > 0) {
        printf("Direita\n");
        moverTorre(casas - 1);
    }
}

// Função recursiva para mover o Bispo
void moverBispo(int casasVertical, int casasHorizontal) {
    if (casasVertical > 0) {
        for (int i = 0; i < casasHorizontal; i++) {
            printf("Cima, Direita\n");
        }
        moverBispo(casasVertical - 1, casasHorizontal);
    }
}

// Função recursiva para mover a Rainha
void moverRainha(int casas) {
    if (casas > 0) {
        printf("Esquerda\n");
        moverRainha(casas - 1);
    }
}

// Função para mover o Cavalo com loops aninhados
void moverCavalo() {
    const int movimentoCavaloVertical = 2; // duas casas para cima
    const int movimentoCavaloHorizontal = 1; // uma casa para a direita

    for (int i = 0; i < movimentoCavaloVertical; i++) { // Controle do movimento vertical
        for (int j = 0; j < movimentoCavaloHorizontal; j++) { // Controle do movimento horizontal
            if (j == 0) { // Para garantir que "Direita" só seja impresso uma vez
                printf("Cima\n");
            }
        }
        if (i == movimentoCavaloVertical - 1) {
            printf("Direita\n");
        }
    }
}

int main() {
    // Definindo as constantes para o número de casas a serem movidas
    const int casasTorre = 5;
    const int casasBispoVertical = 5;
    const int casasBispoHorizontal = 5;
    const int casasRainha = 8;

    // Movimento da Torre
    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);
    printf("\n");

    // Movimento do Bispo
    printf("Movimento do Bispo:\n");
    moverBispo(casasBispoVertical, casasBispoHorizontal);
    printf("\n");

    // Movimento da Rainha
    printf("Movimento da Rainha:\n");
    moverRainha(casasRainha);
    printf("\n");

    // Movimento do Cavalo
    printf("Movimento do Cavalo:\n");
    moverCavalo();
    printf("\n");

    return 0;
}