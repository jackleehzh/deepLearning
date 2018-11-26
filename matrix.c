#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int** mallocMatrix(int **matrix, int m, int n){
    int i = 0;
    matrix = (int **)malloc(sizeof(int *) * m);
    for(i = 0; i < m; i++){
        matrix[i] = (int *)malloc(sizeof(int *) * n);
        memset(matrix[i], 0, n * sizeof(int));
    }

    return matrix;
}

void freeMatrix(int **matrix, int m){
    int i = 0;
    for(i = 0; i < m; i++){
        free(matrix[i]);
    }
    free(matrix);
}

int** transpose(int **matrix, int m, int n){
    int i = 0, j = 0;
    int **newMatrix = NULL;
    newMatrix = (int **)malloc(sizeof(int *) * n);
    for(i = 0; i < n; i++){
        newMatrix[i] = (int *)malloc(sizeof(int *) * m);
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            newMatrix[j][i] = matrix[i][j];
        }
    }

    return newMatrix;
}

int** multiply(int **matrix, int **matrix2, int m, int n, int p){
    int i = 0, j = 0, k = 0;
    int **newMatrix = NULL;
    newMatrix = (int **)malloc(sizeof(int *) * m);
    for(i = 0; i < m; i++){
        newMatrix[i] = (int *)malloc(sizeof(int *) * p);
        memset(newMatrix[i], 0, p * sizeof(int));
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < p; j++){
            for(k = 0; k < n; k++){
                newMatrix[i][j] += matrix[i][k] * matrix2[k][j];
            }
        }
    }

    return newMatrix;
}

int main(int argc, const char * argv[]) {
    int m = 0, n = 0, i = 0, j = 0;
    int **matrix = NULL;

    scanf("%d %d", &m, &n);

    matrix = mallocMatrix(matrix, m, n);
    matrix[2][3] = 6;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    matrix = multiply(matrix, transpose(matrix, m, n), m, n, m);
    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    free(matrix);

    return 0;
}
