#include <stdio.h>
void quick_sort (int *src, int low, int high){
	if(low >= high){
		return;
	}
	int first = low;
	int last = high;
	int key = src[first];

	while(first < last){
		while(first < last && src[last] >= key){
			--last;
		}

		src[first] = src[last];

		while(first < last && src[first] <= key){
			++first;
		}

		src[last] = src[first];

	}
	src[first] = key;
	quick_sort(src, low, first-1);
	quick_sort(src, first+1, high);
}
int main(){
	int src[] = {3,1,2};
	int length = sizeof(src)/(sizeof(int));
	quick_sort(src, 0, length - 1);

	for (int i = 0; i < length; i++){
		printf("%d,", src[i]);
	}
	printf("\n");

	return 0;
}
