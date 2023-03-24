#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, i, j;

    // 사용자로부터 행과 열을 입력 받음
    printf("행과 열의 크기를 입력하세요: ");
    scanf_s("%d %d", &rows, &cols);

    // 입력 받은 행과 열 크기에 따라 2차원 배열을 동적으로 할당함
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // 사용자로부터 행렬의 요소들을 입력 받음
    printf("행렬의 요소들을 입력하세요:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }

    // 전치 행렬을 계산하여 출력함
    printf("전치 행렬은 다음과 같습니다:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    // 할당한 메모리를 해제함
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
