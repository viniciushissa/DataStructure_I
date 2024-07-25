#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    OrderedList* myList = createOrderedList();

    insert(myList, 5);
    insert(myList, 3);
    insert(myList, 8);
    insert(myList, 1);
	insert(myList, 7);
    insert(myList, 13);
    insert(myList, 4);
    insert(myList, 2);

    printList(myList);

    freeList(myList);

    return 0;
}

