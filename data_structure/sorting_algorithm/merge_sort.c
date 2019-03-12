#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(int *src, int index, int *a, int aLen, int *b, int bLen){
	int length = bLen + aLen;
	int aIndex =0;
	int bIndex = 0;
	for (int i = 0; i < length; i++){
		if (aIndex < aLen && bIndex < bLen){
			if (a[aIndex] < b[bIndex]){
				src[index + i]  = a[aIndex++];
			}else{
				src[index + i]  = b[bIndex++];
			}
			continue;
		}
		if (bIndex < bLen){
			src[index + i]  = b[bIndex++];
		}
		if (aIndex < aLen){
			src[index + i]  = a[aIndex++];
		}
	}
	printf("\n");
}

void merge_sort(int *src, int low, int high){
	int length = high - low + 1;
	if (length == 1){
		return;
	}
	int middle = low + (high - low) / 2;
	merge_sort(src, low, middle);

	int aLen = middle - low + 1;
	int *a = (int *)malloc(sizeof(int) * aLen);
	memcpy(a, src + low, sizeof(int) * aLen);


	merge_sort(src, middle + 1, high);

	int bLen = high - middle;
	int *b = (int *)malloc(sizeof(int) * bLen);
	memcpy(b, src + middle + 1, sizeof(int) * bLen);

	merge(src, low, a, aLen, b, bLen);
	free(a);
	free(b);
}

int main(){
	int src[] = {50,10,20,30,70,40,80,60};
	int length = sizeof(src)/(sizeof(int));
	merge_sort(src, 0, length - 1);

	for (int i = 0; i < length; i++){
		printf("%d,", src[i]);
	}
	printf("\n");

	return 0;
}
