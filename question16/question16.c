#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(void *base, size_t num, size_t size, int (*compar)(const void*, const void*)) {
    unsigned int i, j, k, replaced = 1;
    // Cria um ponteiro de char a partir do vetor base para permitir operações que
    // envolvam navegar o vetor e copiar elementos
    char *iterator = base;
    // Roda o bubble sort
    for (i = 0; i < num; i++) {
        // Caso não tenha sido feita nenhuma substituição no ultimo loop, a ordenação é encerrada
        if (replaced == 0) break;
        // Reseta o a variavel de checagem
        replaced = 0;
        // Roda uma unica iteração de bubble sort
        for (j = 0; j < num-1; j++) {
            // Substitui o j-esimo valor pelo valor acima dele caso esse seja menor que o j-esimo valor
            if (compar((void*)&iterator[j*size], (void*)&iterator[(j+1)*size]) == 1) {
                // Copia os valores do j-esimo elemento de base para o vetor temporario tmp
                char *tmp = (char*)malloc(size*sizeof(char));
                for (k = 0; k < size; k++) tmp[k] = iterator[j*size+k];
                // Troca o j-esimo valor pelo valor acima dele com o auxilio de tmp
                for (k = 0; k < size; k++) iterator[j*size+k] = iterator[(j+1)*size+k];
                for (k = 0; k < size; k++) iterator[(j+1)*size+k] = tmp[k];
                // Declara que houve uma substituição através da variável 'replaced'
                replaced = 1;
                // Libera a memória alocada por tmp
                free(tmp);
            }
        }
    }
}

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
    clock_t start, t1, t2;
    // Definindo a variavel que armazena o tamanho do vetor
    // e a variavel de iteração i
    int n, i;
    // Definindo o ponteiro que a apontará para a primeira posição do vetor
    float *a;
    // Recebendo o tamanho do vetor a ser alocado
    printf("Defina o tamahno do vetor: ");
    scanf("%d", &n);
    // Alocando dinamicamente o vetor de tamanho n
    a = (float*)malloc(n*sizeof(float));
    // Preenchendo o vetor com os elementos digitados
    printf("Defina os elementos do vetor: ");
    for (i = 0; i < n; i++) scanf("%f", &a[i]);
    // Usando a função bubbleSort() para ordenar o vetor,
    start = clock();
    bubbleSort(a, n, sizeof(float), compareFloats);
    t1 = clock();
    // Usando a função bubbleSort() para ordenar o vetor,
    qsort(a, n, sizeof(float), compareFloats);
    t2 = clock();
    // Imprimindo o primeiro elemento do array ordenado
    printf("Output: [%f", a[0]);
    // Imprimindo o resto do array ordenado
    for (i = 1; i < n; i++) printf(", %f", a[i]);
    // Terminando a impressão do vetor e pulando a linha
    printf("]\n");

    printf("Tempo levado pelo bubbleSort: %f s\n", ((float)(t1-start))/CLOCKS_PER_SEC);
    printf("Tempo levado pelo qsort: %f s\n", ((float)(t2-t1))/CLOCKS_PER_SEC);

    free(a);

    return 0;
}