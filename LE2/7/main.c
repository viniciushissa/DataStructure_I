#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
    Header header = {NULL, NULL};
    readFile("dados.txt", &header);

    printList(header.head2000, 2000);
    printList(header.head1990, 1990);

    return 0;
}

