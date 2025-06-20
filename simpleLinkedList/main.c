#include <stdio.h>
#include <stdlib.h>
#include "utilstree.h"

int main() {
    Tree *node = NULL;
    for (int i = 1; i < 6; i++){
        node = insertNode(node, rand() % 99);
    }
	printNode(node);
    node = bubbleSortDescending(node);
    printf("\n");
    printNode(node);
    freeTree(node);

    return 0;
}
