#include <stdio.h>
#include <stdlib.h>

void matrixMult(int **A, int al, int ac, int **B, int bc, int **C) {
    int i, j, k;
    // Implementando a multiplicação de matrizes
    for (i = 0; i < al; i++) {
        for (j = 0; j < bc; j++) {
            C[i][j] = 0;
            for (k = 0; k < ac; k++) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

void printMatrix(int **M, int ml, int mc) {
    int i, j;
    for (i = 0; i < ml; i++) {
        printf("[%d", M[i][0]);
        for (j = 1; j < mc; j++) 
            printf(", %d", M[i][j]);
        printf("]\n");
    }
}

void initialize(int **M, int ml, int mc) {
    int i, j;
    for (i = 0; i < ml; i++) {
        for (j = 0; j < mc; j++) {
            M[i][j] = i+j;
        }
    }
}

int main() {
    int **A, **B, **C, al, ac, bc, i;
    // Input
    printf("Defina o numero de linhas e colunas de A e o numero de colunas de B: ");
    scanf("%d %d %d", &al, &ac, &bc);
    // Alocando A
    A = (int**)malloc(al*sizeof(int*));
    A[0] = (int*)malloc(al*ac*sizeof(int));
    // Alocando B
    B = (int**)malloc(ac*sizeof(int*));
    B[0] = (int*)malloc(ac*bc*sizeof(int));
    // Alocando C
    C = (int**)malloc(al*sizeof(int*));
    C[0] = (int*)malloc(al*bc*sizeof(int));
    // Atribuindo indicies aos vetores auxiliares
    for (i = 1; i < al; i++) A[i] = A[i-1] + ac; 
    for (i = 1; i < ac; i++) B[i] = B[i-1] + bc; 
    for (i = 1; i < al; i++) C[i] = C[i-1] + bc; 
    // Inicializando os valores das matrizes
    initialize(A, al, ac);
    initialize(B, ac, bc);
    // Realizando a multiplicação
    matrixMult(A, al, ac, B, bc, C);
    // Imrpimindo C
    printf("A:\n");
    printMatrix(A, al, ac);
    printf("B:\n");
    printMatrix(B, ac, bc);
    printf("C:\n");
    printMatrix(C, al, bc);
    // Liberando a memoria alocada
    free(A[0]); free(A);  
    free(B[0]); free(B);
    free(C[0]); free(C);

    return 0;
}