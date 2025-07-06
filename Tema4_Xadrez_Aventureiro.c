#include <stdio.h>

int main() {
    // Definindo as constantes para o número de casas a serem movidas
    const int casasTorre = 5;
    const int casasBispo = 5;
    const int casasRainha = 8;
    
    // Movimento do Cavalo - duas casas para baixo e uma casa para a esquerda
    const int movimentoCavaloVertical = 2; // movimento para baixo
    const int movimentoCavaloHorizontal = 1; // movimento para a esquerda

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

    // Separação do movimento do Cavalo
    printf("\nMovimento do Cavalo:\n");

    // Usando loops aninhados para simular o movimento do Cavalo
    for (int m = 0; m < movimentoCavaloVertical; m++) {
        printf("Baixo\n");
    }
    
    // O loop for irá repetir o movimento horizontal para a esquerda uma vez
    int n = 0;
    do {
        if (n == 0) { // Para garantir que "Esquerda" só seja impresso uma vez
            printf("Esquerda\n");
        }
        n++;
    } while (n < movimentoCavaloHorizontal);

    return 0;
}