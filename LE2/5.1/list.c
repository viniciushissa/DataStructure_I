#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode;
}

OrderedList* createOrderedList() { 
    OrderedList* list = (OrderedList*)malloc(sizeof(OrderedList));
    if (list != NULL) {
    	list->head = NULL;
    }
    return list;
}

void insert(OrderedList* list, int value) {
    Node* newNode = createNode(value);
    if (newNode == NULL) {
        printf("Erro: Memória insuficiente para alocar o nó.\n");
        return;
    }

    Node** current = &(list->head);
    while (*current != NULL && (*current)->data < value) {
        current = &((*current)->next);
    }

    newNode->next = *current;
    *current = newNode;
}

void printList(OrderedList* list) {
    Node* current = list->head;
    printf("Lista ordenada: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(OrderedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
