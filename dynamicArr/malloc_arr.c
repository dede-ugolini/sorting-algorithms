#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

int i, j, count_c, count_t;
int main() {
	clock_t tempo;
	tempo = clock();	
	srand(time(NULL));
	int *ptr_arr = NULL;
	int size = 24;
 	ptr_arr	= (int*) malloc(size * (sizeof(int)));
 		
  for(i = 0; i < size; i++){
		ptr_arr[i] = size - i;
	} 

	for(i = 0; i < size; i++){
		printf("%d\n", ptr_arr[i]);
	} 
	printf("\n");
	bubble_sort_ascending(ptr_arr,size);
	
	for(i = 0; i < size; i++){
		printf("%d\n", ptr_arr[i]);
	}
	tempo = clock() - tempo;
	printf("Tempo de execucao %fms\n",((float)tempo) / CLOCKS_PER_SEC);
	printf("Numero de comparacoes %d\nNumero de trocas %d\n", count_c, count_t);
	free(ptr_arr);
	return 0;
}
