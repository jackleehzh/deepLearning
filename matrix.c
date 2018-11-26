#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define true  1
#define false 0
typedef int bool;

// 定义矩阵结构体。矩阵中的元素用分数表示，方便矩阵运算（尤其是除法和求逆）是比较大小，保留精度。分数由分子、分母两个整数组成。isInt标识用于简化矩阵元素全为整数时的运算。
struct Matrix{
    bool isInt;
    int ***arr;
};

//初始化矩阵。这里要注意指针的层级关系，并对isInt初始化。y还有一点需要强调：memset的单位是char，如memset(matrix->arr[i][j], 1, n * sizeof(int));，则每一个int值将被设置成00000001000000010000000100000001（16843009）
struct Matrix* initMatrix(int m, int n){
    int i = 0, j = 0;
    struct Matrix *matrix = NULL;
    
    matrix = (struct Matrix *)malloc(sizeof(struct Matrix));
    matrix->arr = (int ***)malloc(sizeof(int **) * 2);
    for(i = 0; i < 2; i++){
        matrix->arr[i] = (int **)malloc(sizeof(int *) * m);
        for(j = 0; j < m; j++){
            matrix->arr[i][j] = (int *)malloc(sizeof(int *) * n);
            memset(matrix->arr[i][j], 0, n * sizeof(int));
        }
    }
    
    for(i = 0; i < m; i++){
        for(j =0; j < n; j++){
            matrix->arr[1][i][j] = 1;
        }
    }
    
    matrix->isInt = true;
    
    return matrix;
}

void freeMatrix(struct Matrix *matrix, int m){
    int i = 0, j = 0;
    
    for(i = 0; i < 2; i++){
        for(j = 0; j < m; j++){
            free(matrix->arr[i][j]);
        }
        free(matrix->arr[i]);
    }
    free(matrix->arr);
    free(matrix);
}

//矩阵转置
struct Matrix * transpose(struct Matrix *matrix, int m, int n, bool isInt){
    int i = 0, j = 0;
    struct Matrix *newMatrix = NULL;
    
    newMatrix = initMatrix(n, m);
    
    if(isInt){
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                newMatrix->arr[0][j][i] = matrix->arr[0][i][j];
            }
        }
    }else{
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                newMatrix->arr[0][j][i] = matrix->arr[0][i][j];
                newMatrix->arr[1][j][i] = matrix->arr[1][i][j];
            }
        }
    }
    newMatrix->isInt = matrix->isInt;
    
    return newMatrix;
}
//矩阵乘法只有在第一个矩阵的列数（column）和第二个矩阵的行数（row）相同时才有意义。
//结果矩阵的行数等于矩阵matrix的行数，列数等于matrix2的列数。
//结果矩阵的第m行第n列的元素等于矩阵matrix的第m行的元素与矩阵matrix2的第n列对应元素乘积之和。
struct Matrix *multiply(struct Matrix *matrix, struct Matrix *matrix2, int m, int n, int p){
    int i = 0, j = 0, k = 0;
    int a = 0, b = 0;
    struct Matrix *newMatrix = NULL;
    
    newMatrix = initMatrix(m, p);
    if(matrix->isInt && matrix2->isInt){
        for(i = 0; i < m; i++){
            for(j = 0; j < p; j++){
                for(k = 0; k < n; k++){
                    newMatrix->arr[0][i][j] += matrix->arr[0][i][k] * matrix2->arr[0][k][j];
                }
            }
        }
    }
//如果矩阵元素存在分数，则先对两个分数做乘法，再对两个分数做加法（需要统分）
    else if(!matrix->isInt && !matrix2->isInt){
        for(i = 0; i < m; i++){
            for(j = 0; j < p; j++){
                for(k = 0; k < n; k++){
                    a = matrix->arr[0][i][k] * matrix2->arr[0][k][j];
                    b = matrix->arr[1][i][k] * matrix2->arr[1][k][j];
                    newMatrix->arr[0][i][j] += newMatrix->arr[0][i][j] * b + a * newMatrix->arr[1][i][j];
                    newMatrix->arr[1][i][j] *= b;
                }
            }
        }
    }else if(!matrix->isInt && matrix2->isInt){
        for(i = 0; i < m; i++){
            for(j = 0; j < p; j++){
                for(k = 0; k < n; k++){
                    a = matrix->arr[0][i][k] * matrix2->arr[0][k][j];
                    b = matrix->arr[1][i][k];
                    newMatrix->arr[0][i][j] += newMatrix->arr[0][i][j] * b + a * newMatrix->arr[1][i][j];
                    newMatrix->arr[1][i][j] *= b;
                }
            }
        }
    }else{
        for(i = 0; i < m; i++){
            for(j = 0; j < p; j++){
                for(k = 0; k < n; k++){
                    a = matrix->arr[0][i][k] * matrix2->arr[0][k][j];
                    b = matrix2->arr[1][k][j];
                    newMatrix->arr[0][i][j] += newMatrix->arr[0][i][j] * b + a * newMatrix->arr[1][i][j];
                    newMatrix->arr[1][i][j] *= b;
                }
            }
        }
    }
    newMatrix->isInt = matrix->isInt & matrix2->isInt;
    
    return newMatrix;
}

int main(int argc, const char * argv[]) {
    int m = 0, n = 0, i = 0, j = 0;
    struct Matrix *matrix;
    scanf("%d %d", &m, &n);
    
    matrix = initMatrix(m, n);
    matrix->arr[0][2][3] = 6;
    matrix->arr[1][2][3] = 5;
    matrix->isInt = false;
    
    if(matrix->isInt){
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                printf("%-10d ", matrix->arr[0][i][j]);
            }
            printf("\n");
        }
    }else{
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(matrix->arr[1][i][j] == 1 || matrix->arr[0][i][j] % matrix->arr[1][i][j] == 0){
                    printf("%-10d ", matrix->arr[0][i][j]);
                }else{
                    printf("%-7.2f ", ((float)matrix->arr[0][i][j]) / matrix->arr[1][i][j]);
                }
            }
            printf("\n");
        }
    }
    matrix = multiply(matrix, transpose(matrix, m, n, matrix->isInt), m, n, m);
    
    if(matrix->isInt){
        for(i = 0; i < m; i++){
            for(j = 0; j < m; j++){
                printf("%-10d ", matrix->arr[0][i][j]);
            }
            printf("\n");
        }
    }else{
        for(i = 0; i < m; i++){
            for(j = 0; j < m; j++){
                if(matrix->arr[1][i][j] == 1 || matrix->arr[0][i][j] % matrix->arr[1][i][j] == 0){
                    printf("%-10d ", matrix->arr[0][i][j]);
                }else{
                    printf("%-7.2f ", ((float)matrix->arr[0][i][j]) / matrix->arr[1][i][j]);
                }            }
            printf("\n");
        }
    }
    free(matrix);
    
    return 0;
}
