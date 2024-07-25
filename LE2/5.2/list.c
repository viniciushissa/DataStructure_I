#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node *createNode(void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void insert(OrderedList *list, void *data) {
    Node *newNode = createNode(data);
    if (newNode == NULL) {
        printf("Erro ao alocar memória para novo nó.\n");
        return;
    }

    Node *current = list->head;
    Node *previous = NULL;

    while (current != NULL && list->compare(current->data, data) < 0) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        newNode->next = list->head;
        list->head = newNode;
    } else { 
        newNode->next = current;
        previous->next = newNode;
    }
}

int compareInt(void *a, void *b) {
    int *intA = (int *)a;
    int *intB = (int *)b;
    return (*intA - *intB);
}

void printList(OrderedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d ", *((int *)current->data));
        current = current->next;
    }
    printf("\n");
}
