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

    // Variáveis para os atributos escolhidos
    int atributoEscolhido1, atributoEscolhido2;

    // Menu interativo para escolha dos dois atributos
    printf("\nEscolha o primeiro atributo que deseja comparar:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n6. Sair\n");
    printf("Digite sua escolha (1-6): ");
    scanf("%d", &atributoEscolhido1);
    
    // Se o usuário escolher sair, encerra o programa.
    if (atributoEscolhido1 == 6) {
        printf("Saindo do programa. Até logo!\n");
        return 0;
    }

    // Excluir a escolha para o segundo atributo
    printf("\nEscolha o segundo atributo que deseja comparar:\n");
    for (int i = 1; i <= 6; i++) {
        if (i != atributoEscolhido1) {
            if (i == 6) {
                printf("6. Sair\n");
            } else {
                printf("%d. ", i);
                if (i == 1) printf("População\n");
                else if (i == 2) printf("Área\n");
                else if (i == 3) printf("PIB\n");
                else if (i == 4) printf("Número de Pontos Turísticos\n");
                else if (i == 5) printf("Densidade Demográfica\n");
            }
        }
    }
    printf("Digite sua escolha (1-6): ");
    scanf("%d", &atributoEscolhido2);

    // Verifica se o usuário escolheu sair
    if (atributoEscolhido2 == 6) {
        printf("Saindo do programa. Até logo!\n");
        return 0;
    }

    // Variáveis para armazenar os resultados da comparação
    float valor1, valor2;

    // Comparações com base nos atributos escolhidos
    for (int j = 0; j < 2; j++) {
        int atributoAtual = (j == 0) ? atributoEscolhido1 : atributoEscolhido2;
        
        switch (atributoAtual) {
            case 1: // Comparação de População
                valor1 = populacao1;
                valor2 = populacao2;
                printf("\nComparacao de cartas (Atributo: População):\n");
                printf("Carta 1 - %s: %lu\n", nomePais1, populacao1);
                printf("Carta 2 - %s: %lu\n", nomePais2, populacao2);
                break;

            case 2: // Comparação de Área
                valor1 = area1;
                valor2 = area2;
                printf("\nComparacao de cartas (Atributo: Área):\n");
                printf("Carta 1 - %s: %.2f km²\n", nomePais1, area1);
                printf("Carta 2 - %s: %.2f km²\n", nomePais2, area2);
                break;

            case 3: // Comparação de PIB
                valor1 = pib1;
                valor2 = pib2;
                printf("\nComparacao de cartas (Atributo: PIB):\n");
                printf("Carta 1 - %s: %.2f bilhões de reais\n", nomePais1, pib1);
                printf("Carta 2 - %s: %.2f bilhões de reais\n", nomePais2, pib2);
                break;

            case 4: // Comparação de Número de Pontos Turísticos
                valor1 = pontosTuristicos1;
                valor2 = pontosTuristicos2;
                printf("\nComparacao de cartas (Atributo: Número de Pontos Turísticos):\n");
                printf("Carta 1 - %s: %d\n", nomePais1, pontosTuristicos1);
                printf("Carta 2 - %s: %d\n", nomePais2, pontosTuristicos2);
                break;

            case 5: // Comparação de Densidade Demográfica
                valor1 = (float) populacao1 / area1;
                valor2 = (float) populacao2 / area2;
                printf("\nComparacao de cartas (Atributo: Densidade Demográfica):\n");
                printf("Carta 1 - %s: %.2f hab/km²\n", nomePais1, valor1);
                printf("Carta 2 - %s: %.2f hab/km²\n", nomePais2, valor2);
                break;

            default:
                printf("Opção inválida! Por favor, escolha um número entre 1 e 6.\n");
                continue; // Pula para a próxima iteração se a opção for inválida
        }
        
        // Lógica de comparação
        if (atributoAtual == 5) { // Densidade Demográfica
            printf("Resultado: Carta %d (%s) venceu!\n", (valor1 < valor2) ? 1 : 2, (valor1 < valor2) ? nomePais1 : nomePais2);
        } else {
            printf("Resultado: Carta %d (%s) venceu!\n", (valor1 > valor2) ? 1 : (valor1 < valor2) ? 2 : 0, (valor1 > valor2) ? nomePais1 : (valor1 < valor2) ? nomePais2 : "Empate!");
        }
    }

    // Cálculo da soma dos atributos
    float soma1 = 0, soma2 = 0;

    // Soma dos valores
    soma1 = (atributoEscolhido1 == 1 ? populacao1 : atributoEscolhido1 == 2 ? area1 : atributoEscolhido1 == 3 ? pib1 * 1e9 : atributoEscolhido1 == 4 ? pontosTuristicos1 : (float) populacao1 / area1) +
            (atributoEscolhido2 == 1 ? populacao1 : atributoEscolhido2 == 2 ? area1 : atributoEscolhido2 == 3 ? pib1 * 1e9 : atributoEscolhido2 == 4 ? pontosTuristicos1 : (float) populacao1 / area1);

    soma2 = (atributoEscolhido1 == 1 ? populacao2 : atributoEscolhido1 == 2 ? area2 : atributoEscolhido1 == 3 ? pib2 * 1e9 : atributoEscolhido1 == 4 ? pontosTuristicos2 : (float) populacao2 / area2) +
            (atributoEscolhido2 == 1 ? populacao2 : atributoEscolhido2 == 2 ? area2 : atributoEscolhido2 == 3 ? pib2 * 1e9 : atributoEscolhido2 == 4 ? pontosTuristicos2 : (float) populacao2 / area2);

    // Resultado da soma dos atributos
    printf("\nSoma dos atributos:\n");
    printf("Carta 1 - %s: %.2f\n", nomePais1, soma1);
    printf("Carta 2 - %s: %.2f\n", nomePais2, soma2);
    
    // Verificando a carta com maior soma
    if (soma1 > soma2) {
        printf("Resultado Final: Carta 1 (%s) venceu!\n", nomePais1);
    } else if (soma1 < soma2) {
        printf("Resultado Final: Carta 2 (%s) venceu!\n", nomePais2);
    } else {
        printf("Resultado Final: Empate!\n");
    }

    return 0;
}