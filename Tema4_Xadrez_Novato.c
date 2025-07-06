#include <stdio.h>

int main() {
    // Definindo as constantes para o número de casas a serem movidas
    const int casasTorre = 5;
    const int casasBispo = 5;
    const int casasRainha = 8;

    // Movimento da Torre - usando for
    printf("Movimento da Torre:\n");
    for (int i = 0; i < casasTorre; i++) {
        printf("Direita\n");
    }

    // Movimento do Bispo - usando while
    printf("\nMovimento do Bispo:\n");
    int j = 0;
    while (j < casasBispo) {
        printf("Cima, Direita\n");
        j++;
    }

    // Movimento da Rainha - usando do-while
    printf("\nMovimento da Rainha:\n");
    int k = 0;
    do {
        printf("Esquerda\n");
        k++;
    } while (k < casasRainha);

    return 0;
}