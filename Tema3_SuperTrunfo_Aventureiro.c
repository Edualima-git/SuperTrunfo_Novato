#include <stdio.h>
#include <string.h>

int main() {
    // Declaração das variáveis para a primeira carta
    char estado1;
    char codigo1[5];
    char nomePais1[30];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // Declaração das variáveis para a segunda carta
    char estado2;
    char codigo2[5];
    char nomePais2[30];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // Leitura dos dados da primeira carta
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: ");
    scanf(" %c", &estado1);
    printf("Codigo da Carta: ");
    scanf("%s", codigo1);
    printf("Nome do País: ");
    scanf(" %[^\n]", nomePais1);
    printf("Populacao: ");
    scanf("%lu", &populacao1);  // Leitura como unsigned long int
    printf("Area (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // Leitura dos dados da segunda carta
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: ");
    scanf(" %c", &estado2);
    printf("Codigo da Carta: ");
    scanf("%s", codigo2);
    printf("Nome do País: ");
    scanf(" %[^\n]", nomePais2);
    printf("Populacao: ");
    scanf("%lu", &populacao2);  // Leitura como unsigned long int
    printf("Area (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // Variável para o critério de comparação
    int atributoEscolhido;

    // Menu interativo
    printf("\nEscolha o atributo que deseja comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("6. Sair\n");
    printf("Digite sua escolha (1-6): ");
    scanf("%d", &atributoEscolhido);

    // Comparação com base no atributo escolhido
    switch (atributoEscolhido) {
        case 1: // Comparação de População
            printf("\nComparacao de cartas (Atributo: População):\n");
            printf("Carta 1 - %s: %lu\n", nomePais1, populacao1);
            printf("Carta 2 - %s: %lu\n", nomePais2, populacao2);

            if (populacao1 > populacao2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nomePais1);
            } else if (populacao1 < populacao2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        
        case 2: // Comparação de Área
            printf("\nComparacao de cartas (Atributo: Área):\n");
            printf("Carta 1 - %s: %.2f km²\n", nomePais1, area1);
            printf("Carta 2 - %s: %.2f km²\n", nomePais2, area2);

            if (area1 > area2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nomePais1);
            } else if (area1 < area2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // Comparação de PIB
            printf("\nComparacao de cartas (Atributo: PIB):\n");
            printf("Carta 1 - %s: %.2f bilhões de reais\n", nomePais1, pib1);
            printf("Carta 2 - %s: %.2f bilhões de reais\n", nomePais2, pib2);

            if (pib1 * 1e9 > pib2 * 1e9) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nomePais1);
            } else if (pib1 * 1e9 < pib2 * 1e9) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Comparação de Número de Pontos Turísticos
            printf("\nComparacao de cartas (Atributo: Número de Pontos Turísticos):\n");
            printf("Carta 1 - %s: %d\n", nomePais1, pontosTuristicos1);
            printf("Carta 2 - %s: %d\n", nomePais2, pontosTuristicos2);

            if (pontosTuristicos1 > pontosTuristicos2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nomePais1);
            } else if (pontosTuristicos1 < pontosTuristicos2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Comparação de Densidade Demográfica
            float densidadeDemografica1 = (float) populacao1 / area1;
            float densidadeDemografica2 = (float) populacao2 / area2;

            printf("\nComparacao de cartas (Atributo: Densidade Demográfica):\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", nomePais1, densidadeDemografica1);
            printf("Carta 2 - %s: %.2f hab/km²\n", nomePais2, densidadeDemografica2);

            if (densidadeDemografica1 < densidadeDemografica2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nomePais1);
            } else if (densidadeDemografica1 > densidadeDemografica2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Por favor, escolha um número entre 1 e 5.\n");
            break;
    }

    return 0;
}