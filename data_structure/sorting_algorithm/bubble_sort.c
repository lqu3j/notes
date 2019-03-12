#include <stdio.h>

void swap(int *src_a, int *src_b){
	int tmp = *src_a;
	*src_a = *src_b;
	*src_b = tmp;
}
void bubble_sort(int *src, int len){
	for (int i = 0; i < len; i++){
		for (int j = 1; j < len - i; j++){
			if (src[j - 1] > src[j]){
				swap(src + j - 1, src + j);
			}
		}
	}
}
int main(){
	int src[] = {3,1,2};
	int length = sizeof(src)/(sizeof(int));
	bubble_sort(src, length);
	for (int i = 0; i < length; i++){
		printf("%d,", src[i]);
	}
	printf("\n");
}
