#include <stdio.h>	
#include <time.h> /*Vou usar as funções srand e clock*/
#include <stdlib.h> /*Vou usar a função rand*/

#define N 1000 /*Vou usar uma constante para definir o tamanho do array*/

int i, j, tmp;
int count_trocas = 0;
int count_comparacoes = 0;

void print_array(int arr[], int size, float tempo){
	for(i = 0; i < size; i++){
		printf("%d\n",arr[i]);
	}
	printf("Numero de trocas: %d\nNumero de comparacoes: %d\n", count_trocas, count_comparacoes);
	printf("Tempo de execucao %fms\n",((float)tempo) / CLOCKS_PER_SEC); /*Faço cast de clock_t para flout e divido usando a constante para gerar o tempo em milisegundos */
}

void bubblesort_crescente(int arr[], int size) {

   for (i = 0; i < size - 1; i++) {
    for(j = 0; j < size - i - 1; j++) {
      if(arr[j] > arr[j + 1]) {
     	/* printf("i = %d j = %d [j:%d] = %d [i:%d] = %d\n", i, j, j ,arr[j], i,  arr[i]);*/ 
			/*Linha para debugar, se existe outra forma preciso aprender :( */
      tmp = arr[j];
      arr[j] = arr[j + 1];
      arr[j + 1] = tmp;
			count_comparacoes++;
			count_trocas++;
      }
			count_comparacoes++;
     }
   } 
}

void bubblesort_decrescente(int arr[], int size) {

   for (i = 0; i < size -1; i++) {
    for(j = 0; j < size - i - 1; j++){
      if(arr[j] < arr[j + 1]) {
				tmp = arr[j];
     		arr[j] = arr[j + 1];
      	arr[j + 1] = tmp;
				count_comparacoes++;
				count_trocas++;
      }
			count_comparacoes++;
     }
   } 
}
void insertion_sort_crescente(int arr[], int size){
	
	for(i = 1; i < size; ++i) {
		tmp = arr[i];
		j = i - 1;					
		
		while(j >= 0 && arr[j] > tmp){
			arr[j+1] = arr[j];
			j--;
			count_trocas++;
			count_comparacoes++;
		}
		if (j == 0) {
			count_comparacoes++;
		}
		arr[j + 1] = tmp;
	}

}
void insertion_sort_decrescente(int arr[], int size){
	
	for(i = 1; i < size; ++i) {
		tmp = arr[i];
		j = i - 1;					
		
		while(j >= 0 && arr[j] < tmp){
			arr[j+1] = arr[j];
			j--;
			count_trocas++;
			count_comparacoes++;
		}
		if (j == 0) {
			count_comparacoes++;
		}
		arr[j + 1] = tmp;
	}

}

void main() {
	int ordem;	
	clock_t tempo;
	tempo = clock();	
	int arr[N];
	int size = sizeof(arr) / sizeof(arr[0]);

	srand(time(NULL)); /*srand, parar gerar números mais aleatórios. Por mais que a constante NULL e 0 sejam a mesma coisa, utilizei NULL para o código ficar mais fácil de ler e entender*/

	for(i = 0 ;i < size; i++){ /* Preenchendo nosso array com números aleatórios*/
		arr[i] = rand() % 1000; 
	}
	printf("Digite 0 para bubble sort decrescente\n1 para buble sort crescente\n2 para insertion sort decrescente\n3 para insertion sort crescente\n");
	scanf("%d", &ordem);

	switch(ordem) {
		case 0:
			bubblesort_decrescente(arr,size);
			break;
		case 1:
			bubblesort_crescente(arr,size);
			break;
		case 2:
			insertion_sort_decrescente(arr,size);
			break;
		case 3:
			insertion_sort_crescente(arr,size);
			break;
	}
				
	tempo = clock() - tempo;
	print_array(arr,size,tempo);
}
