#include <stdio.h>
#include <stdlib.h>

void arrayAddition(int *v3, int*v1, int*v2, int num) {
    int i;
    for (i = 0; i < num; i++) v3[i] = v1[i] + v2[i];
}
    
int main() {
    int *v1, *v2, *v3, n, i;
    // Input: numero de elementos
    printf("Defina o numero de elementos: ");
    scanf("%d", &n);
    // Allocando vetores
    v1 = (int*)malloc(n*sizeof(int));
    v2 = (int*)malloc(n*sizeof(int));
    v3 = (int*)malloc(n*sizeof(int));
    // Input: elementos dos vetores
    for (i = 0; i < n; i++) scanf("%d", &v1[i]);
    for (i = 0; i < n; i++) scanf("%d", &v2[i]);
    // Soma os elementos dos vetores
    arrayAddition(v3, v1, v2, n);
    // Imprimindo o primeiro elemento do array 
    printf("Output: [%d", v3[0]);
    // Imprimindo o resto do array 
    for (i = 1; i < n; i++) printf(", %d", v3[i]);
    // Terminando a impressão do vetor e pulando a linha
    printf("]\n");
    //Libera os vetores
    free(v1);
    free(v2);
    free(v3);

    return 0;
}