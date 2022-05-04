#include <stdio.h>
#include <stdlib.h>

// Função utilizada para comparar dois floats
int compareFloats(const void *p1, const void *p2) {
    // Se o float contido na posição que p1 aponta for menor
    // que o de p2 aponta, retorna -1
    if (*(float*)p1 < *(float*)p2) return -1;
    // Se o float contido na posição que p1 aponta for igual
    // ao que o de p2 aponta, retorna 0
    if (*(float*)p1 == *(float*)p2) return 0;
    // Se o float contido na posição que p1 aponta for maior
    // que o de p2 aponta, retorna 1
    if (*(float*)p1 > *(float*)p2) return 1;
}

int main() {
    // Definindo a variavel que armazena o tamanho do vetor
    // e a variavel de iteração i
    int n, i;
    // Definindo o ponteiro que a apontará para a primeira posição do vetor
    float *a;
    // Recebendo o tamanho do vetor a ser alocado
    printf("Defina o tamanho do vetor: ");
    scanf("%d", &n);
    // Alocando dinamicamente o vetor de tamanho n
    a = (float*)malloc(n*sizeof(float));
    // Preenchendo o vetor com os elementos digitados
    for (i = 0; i < n; i++) scanf("%f", &a[i]);
    // Usando a função qsort() para ordenar o vetor,
    // a qual chama a função compareFloats()
    qsort(a, n, sizeof(float), compareFloats);
    // Imprimindo o primeiro elemento do array ordenado
    printf("[%f", a[0]);
    // Imprimindo o resto do array ordenado
    for (i = 1; i < n; i++) printf(", %f", a[i]);
    // Terminando a impressão do vetor e pulando a linha
    printf("]\n");
    free(a);
    return 0;
}