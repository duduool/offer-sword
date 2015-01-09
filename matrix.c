#include <stdio.h>

int find(int (*matrix)[4], int rows, int columns, int key)
{
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = columns - 1; j >= 0; j--) {
			if (matrix[i][j] == key) {
				printf("%d %d\n", i, j);
				return 1;
			}
			else if (matrix[i][j] > key)
				continue;
			else 
				break;	
		}
	}

	return 0;
}

int main(int argc, const char *argv[])
{
	int matrix[][4] = {
		{1, 2, 8, 9},
		{2, 4, 9, 12},
		{4, 7, 10, 13},
		{6, 8, 11, 15},
	};

	int ret = find(matrix, 4, 4, 7);
//	printf("%d\n", ret);

	return 0;
}
