#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    OrderedList list;
    list.head = NULL;
    list.compare = compareInt;

    int var1 = 5, var2 = 3, var3 = 11, var4= 6, var5 = 8;
    insert(&list, &var1);
    insert(&list, &var2);
    insert(&list, &var3);
    insert(&list, &var4);
    insert(&list, &var5);

    printf("Lista ordenada: ");
    printList(&list);

    return 0;
}

