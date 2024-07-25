#include <stdio.h>
#include <stdlib.h>
#include "poli.h"

int main() {
    struct no* poli1 = NULL;
    struct no* poli2 = NULL;

    int coeficiente, expoente;
    int opcao;

    printf("Insira o primeiro polinomio:\n");
    do {
        printf("Coeficiente: ");
        scanf("%d", &coeficiente);
        printf("Expoente: ");
        scanf("%d", &expoente);
        inserirNo(&poli1, coeficiente, expoente);
        printf("Deseja inserir outro termo? (1 - Sim, 0 - Nao): ");
        scanf("%d", &opcao);
    } while (opcao != 0);

    printf("Insira o segundo polinomio:\n");
    do {
        printf("Coeficiente: ");
        scanf("%d", &coeficiente);
        printf("Expoente: ");
        scanf("%d", &expoente);
        inserirNo(&poli2, coeficiente, expoente);
        printf("Deseja inserir outro termo? (1 - Sim, 0 - Nao): ");
        scanf("%d", &opcao);
    } while (opcao != 0);

    printf("Polinomio 1: ");
    imprimirPolinomio(poli1);
    printf("Polinomio 2: ");
    imprimirPolinomio(poli2);

    struct no* soma = somarPolinomios(poli1, poli2);

    printf("Soma dos polinomios: ");
    imprimirPolinomio(soma);

    return 0;
}

