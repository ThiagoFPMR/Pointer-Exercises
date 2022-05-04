#include <gc.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    float *a, d;
    GC_INIT();
    // Alocando dinamicamente o vetor de tamanho n
    printf("Defina o tamanho do vetor: ");
    scanf("%d", &n);
    a = (float*)GC_MALLOC(n*sizeof(float));
    for (i = 0; i < n; i++) a[i] = i;
    // Imprimindo o array ordenado
    printf("[%f", a[0]);
    for (i = 1; i < n; i++) printf(", %f", a[i]);
    printf("]\n");

    return 0;
}