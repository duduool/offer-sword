#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int *b, int alen, int blen)
{
	int i = alen - 1, j = blen - 1;
	int cursor = alen + blen - 1;
	
	while (cursor) {
		if (a[i] > b[j]) {
			a[cursor--] = a[i];
			i--;
		} else {
			a[cursor--] = b[j];
			j--;
		}
	}
}

void print(int *a, int len) 
{
	int i = 0; 
	
	for (i = 0; i < len; i++) 
		printf("%d ", a[i]);
	printf("\n");
}

int main(int argc, const char *argv[])
{
	int a[10] = {1, 3, 5, 7};
	int b[] = {2, 3, 4, 9};
	print(a, 4);
	print(b, 4);
	merge(a, b, 4, 4);
	print(a, 8);
	return 0;
}


