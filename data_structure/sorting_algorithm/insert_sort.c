#include <stdio.h>

void swap(int *src_a, int *src_b){
	int tmp = *src_a;
	*src_a = *src_b;
	*src_b = tmp;
}

void insert_sort(int *src, int len){
	for (int i = 1; i < len; i++){
		for (int j = i - 1; j >= 0;j--){
			if (src[j] > src[j + 1]){
				swap(src + j, src + j + 1);
			}else{
				break;
			}
		}
	}
}
int main(){
	int src[] = {3,1,2};
	int length = sizeof(src)/(sizeof(int));
	insert_sort(src, length);
	for (int i = 0; i < length; i++){
		printf("%d,", src[i]);
	}
	printf("\n");
}
