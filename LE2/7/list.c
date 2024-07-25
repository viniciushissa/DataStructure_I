#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void readFile(const char *filename, Header *header) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir arquivo.");
        return;
    }

    char area[100];
    int censo2000, censo1990;

    while (fscanf(file, "%s %d %d", area, &censo2000, &censo1990) != EOF) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        strcpy(newNode->area, area);
        newNode->censo2000 = censo2000;
        newNode->censo1990 = censo1990;
        newNode->next2000 = NULL;
        newNode->next1990 = NULL;

        insertOrdered(header, newNode);
    }

    fclose(file);
}

void insertOrdered(Header *header, Node *newNode) {
    Node **current2000 = &header->head2000;
    while (*current2000 && (*current2000)->censo2000 < newNode->censo2000) {
        current2000 = &(*current2000)->next2000;
    }
    newNode->next2000 = *current2000;
    *current2000 = newNode;

    Node **current1990 = &header->head1990;
    while (*current1990 && (*current1990)->censo1990 < newNode->censo1990) {
        current1990 = &(*current1990)->next1990;
    }
    newNode->next1990 = *current1990;
    *current1990 = newNode;
}

void printList(Node *head, int year) {
	if (year == 2000){
	    printf("Censo 2000:\n");
	    while (head) {
	        printf("Area: %s, Populacao: %d\n", head->area, head->censo2000);
	        head = head->next2000;
	    }
	    printf("\n");
	} else
	if (year == 1990){
		printf("Censo 1990:\n");
	    while (head) {
	        printf("Area: %s, Populacao: %d\n", head->area, head->censo1990);
	        head = head->next1990;
	    }
	    printf("\n");
	}	
}
