#include <stdio.h>
#include <stdlib.h>
#include "utilstree.h"

Tree *insertNode(Tree *node, int value){
	Tree *new = malloc(sizeof(Tree));
	new->value = value;
	new->prox = node;
	return new;
}

void printNode(Tree *node){
	while(node != NULL){
		printf("%d\n", node->value);
		node = node->prox;
	};
}

Tree *searchNode(Tree *node, int value) {
	for(node; node != NULL; node = node->prox) {
		if (node->value == value) {
			return node;
		}
	}
	printf("searchNode:Value not found\n");
	return NULL;
}

Tree *deleteNode(Tree *node, int value) {
	Tree *temp = searchNode(node, value);
	if(temp != NULL) {
		temp->prox = node->prox;
		return temp;
	}
	else {
		printf("deleteNode: This value dont exist in node\n");
		return node;
	}
}

void freeTree(Tree *node){
	while (node != NULL) {
		Tree *temp = node->prox;
		free(node);
		node = temp;
	}
}

int getLenght(Tree *node) {
	int len = 0;
	while (node != NULL) {
		len++;
		node = node->prox;
	}
	return len;
}

Tree *bubbleSortAscending(Tree *node) {
	int len = getLenght(node);
	int itr = 0;
	int swapped;
	while (itr < len) {
		Tree *cross_node = node;
		Tree *prevNode = node;
		swapped = 0;

		while (cross_node->prox != NULL) {
			Tree *next_node = cross_node->prox;
			if (cross_node->value > next_node->value) {
				swapped = 1;
				if (cross_node == node) {
					cross_node->prox = next_node->prox;
					next_node->prox = cross_node;
					prevNode = next_node;
					node  = prevNode;
				}
				else {
					cross_node->prox = next_node->prox;
					next_node->prox = cross_node;
					prevNode->prox = next_node;
					prevNode = next_node;
				}
				continue;
			}
			prevNode = cross_node;
			cross_node = cross_node->prox;
		}
		if (!swapped) {
			break;
		}

		itr++;
	}
	return node;
}

Tree *bubbleSortDescending(Tree *node) {
	int len = getLenght(node);
	int itr = 0;
	int swapped;
	while (itr < len) {
		Tree *cross_node = node;
		Tree *prevNode = node;
		swapped = 0;

		while (cross_node->prox != NULL) {
			Tree *next_node = cross_node->prox;
			if (cross_node->value < next_node->value) {
				swapped = 1;
				if (cross_node == node) {
					cross_node->prox = next_node->prox;
					next_node->prox = cross_node;
					prevNode = next_node;
					node  = prevNode;
				}
				else {
					cross_node->prox = next_node->prox;
					next_node->prox = cross_node;
					prevNode->prox = next_node;
					prevNode = next_node;
				}
				continue;
			}
			prevNode = cross_node;
			cross_node = cross_node->prox;
		}
		if (!swapped) {
			break;
		}

		itr++;
	}
	return node;
}

void hello() {
	printf("hello world\n");
}