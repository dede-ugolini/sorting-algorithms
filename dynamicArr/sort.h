int i, j;
int count_c = 0;
int count_t = 0;

extern int *bubble_sort_ascending(int ptr_arr[], int size){
	for(i = 0; i < size - 1; i++) {
		for(j = 0; j < size - i - 1; j++){
			if (ptr_arr[j] > ptr_arr[j + 1]){
				count_c += 1;
				count_t += 1;
				int temp = ptr_arr[j];
				ptr_arr[j] = ptr_arr[j +1];
				ptr_arr[j+1] = temp;
			}
			count_c +=1;
		}			
	}
	return ptr_arr,&count_c,&count_t;
}

extern int *bubble_sort_descending(int ptr_arr[], int size){
	for(i = 0; i < size - 1; i++) {
		for(j = 0; j < size - i - 1; j++){
			if (ptr_arr[j] < ptr_arr[j + 1]){ count_c += 1;
				count_c += 1;
				count_t += 1;
				int temp = ptr_arr[j];
				ptr_arr[j] = ptr_arr[j +1];
				ptr_arr[j+1] = temp;
			}
			count_c +=1;
		}			
	}
	return ptr_arr;
}

int *insertion_sort_ascending(int ptr_arr[], int size){
	for(i = 1; i < size; i++){
		int temp = ptr_arr[i];
		j = i - 1;

		while(j >= 0 && ptr_arr[j] > temp) {
			ptr_arr[j+1] = ptr_arr[j];
			j--;
		}
		ptr_arr[j+1] = temp;
	}
	return ptr_arr;	
}

int *insertion_sort_descending(int ptr_arr[], int size){
	for(i = 1; i < size; i++){
		int temp = ptr_arr[i];
		j = i - 1;

		while(j >= 0 && ptr_arr[j] < temp) {
			ptr_arr[j+1] = ptr_arr[j];
			j--;
		}
		ptr_arr[j+1] = temp;
	}
	return ptr_arr;	
}
