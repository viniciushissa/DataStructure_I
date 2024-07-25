#include <stdio.h>
#include <stdlib.h>
#include "poli.h"

struct no* novoNo(int coeficiente, int expoente) {
    struct no* temp = (struct no*)malloc(sizeof(struct no));
    temp->coeficiente = coeficiente;
    temp->expoente = expoente;
    temp->proximo = NULL;
    return temp;
}

void inserirNo(struct no** cabeca, int coeficiente, int expoente) {
    struct no* temp = novoNo(coeficiente, expoente);
    struct no* atual = *cabeca;
    if (*cabeca == NULL || expoente > (*cabeca)->expoente) {
        temp->proximo = *cabeca;
        *cabeca = temp;
    } else {
        while (atual->proximo != NULL && atual->proximo->expoente > expoente) {
            atual = atual->proximo;
        }
        temp->proximo = atual->proximo;
        atual->proximo = temp;
    }
}

struct no* somarPolinomios(struct no* poli1, struct no* poli2) {
    struct no* resultado = NULL;
    while (poli1 != NULL || poli2 != NULL) {
        if (poli1 == NULL) {
            inserirNo(&resultado, poli2->coeficiente, poli2->expoente);
            poli2 = poli2->proximo;
        } else if (poli2 == NULL) {
            inserirNo(&resultado, poli1->coeficiente, poli1->expoente);
            poli1 = poli1->proximo;
        } else {
            if (poli1->expoente > poli2->expoente) {
                inserirNo(&resultado, poli1->coeficiente, poli1->expoente);
                poli1 = poli1->proximo;
            } else if (poli1->expoente < poli2->expoente) {
                inserirNo(&resultado, poli2->coeficiente, poli2->expoente);
                poli2 = poli2->proximo;
            } else {
                inserirNo(&resultado, poli1->coeficiente + poli2->coeficiente, poli1->expoente);
                poli1 = poli1->proximo;
                poli2 = poli2->proximo;
            }
        }
    }
    return resultado;
}

void imprimirPolinomio(struct no* poli) {
    while (poli != NULL) {
        printf("%dx^%d ", poli->coeficiente, poli->expoente);
        if (poli->proximo != NULL) {
            printf("+ ");
        }
        poli = poli->proximo;
    }
    printf("\n");
}
