#pragma once
typedef struct Tree {

	int value;
	struct Tree *prox;
}Tree;

Tree *insertNode(Tree *node, int value);
void printNode(Tree *node);
Tree *deleteNode(Tree *node, int value);
Tree *searchNode(Tree *node, int value);
void freeTree(Tree *node);
int getLenght(Tree *node);
Tree *bubbleSortAscending(Tree *node);
Tree *bubbleSortDescending(Tree *node);
void hello();