#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    float *a, d;
    // Alocando dinamicamente o vetor de tamanho n
    scanf("%d", &n);
    a = (float*)malloc(n*sizeof(float));
    // É feito o uso de insertion sort na hora de preencher o vetor
    scanf("%f", &d);
    a[0] = d;
    for (i = 1; i < n; i++) {
        scanf("%f", &d);
        int insertion_pos = 0;
        // Encontrando a posição alocada onde colocar o novo valor d
        for (j = i-1; j >= 0; j--) {
            if (d > a[j]) {
                insertion_pos = j+1;
                break;
            }
        }
        // Movend os outros valores a fim de manter o vetor ordenado
        for (j = i-1; j >= insertion_pos; j--) a[j+1] = a[j];
        // Adicionando o novo valor na posição encontrada
        a[insertion_pos] = d;
    }
    // Imprimindo o array ordenado
    printf("[%f", a[0]);
    for (i = 1; i < n; i++) printf(", %f", a[i]);
    printf("]\n");

    return 0;
}