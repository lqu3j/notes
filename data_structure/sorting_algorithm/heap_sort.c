#include <stdio.h>
void swap(int *src_a, int *src_b){
	int tmp = *src_a;
	*src_a = *src_b;
	*src_b = tmp;
}
void adjust_heap(int *src, int length, int parent){
	int son = 2 * parent +1;

	if (son >= length)
		return;

	if (son + 1 < length && src[son] < src[son + 1])
		son = son + 1;

	if (src[parent] > src[son]){
		return;
	}
	swap(src+parent, src + son);
	adjust_heap(src, length, son);
}
void heap_sort(int *src, int length){
	for (int i = (length / 2) - 1; i >= 0; i--){
		adjust_heap(src, length, i);
	}

	for (int i = 1; i < length; i++){
		swap(src, src + length - i);
		adjust_heap(src, length - i, 0);
	}
}
int main(){
	int src[] = {3,4,1,2};
	int length = sizeof(src)/(sizeof(int));
	heap_sort(src, length);

	for (int i = 0; i < length; i++){
		printf("%d,", src[i]);
	}
	printf("\n");

	return 0;
}
