#include <stdio.h>

void swap(int *src_a, int *src_b){
	int tmp = *src_a;
	*src_a = *src_b;
	*src_b = tmp;
}

void selection_sort(int *src, int len){
	for (int i = 0; i < len; i++){
		int minIndex = i;
		for (int j = i + 1; j < len; j++){
			if (src[j] < src[minIndex]){
				minIndex = j;
			}
		}
		swap(src + i, src + minIndex);
	}
}
int main(){
	int src[] = {3,1,2};
	int length = sizeof(src)/(sizeof(int));
	selection_sort(src, length);
	for (int i = 0; i < length; i++){
		printf("%d,", src[i]);
	}
	printf("\n");
}
