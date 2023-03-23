#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMatrix(int* array[], int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			printf("%d\t", array[i][j]);
		printf("\n");
	}
}

void transposeMbyN(int* original[], int* transposed[], int row, int col) {
	int i, j, count = 0;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			transposed[j][i] = original[i][j];
			count++;
		}
	}
	printf("%d개의 원소를 전치했습니다.\n", count);
}

int main() {
	const int row = 3;
	const int col = 4;
	int** original = NULL;
	int** transposed = NULL;
	int i, j;
	int array[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };

	original = (int**)calloc(row, sizeof(int*));
	for (i = 0; i < row; i++) {
		original[i] = (int*)calloc(col, sizeof(int));
		for (j = 0; j < col; j++)
			original[i][j] = array[i][j];
	}
	printMatrix(original, 3, 4);

	transposed = (int**)calloc(col, sizeof(int*));
	for (i = 0; i < col; i++)
		transposed[i] = (int*)calloc(row, sizeof(int));

	printf("-------------------------------\n");
	transposeMbyN(original, transposed, 3, 4);
	printMatrix(transposed, 4, 3);

	for (i = 0; i < row; i++)
		free(original[i]);
	free(original);

	for (i = 0; i < col; i++)
		free(transposed[i]);
	free(transposed);
	return 0;
}
