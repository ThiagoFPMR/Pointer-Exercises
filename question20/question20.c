#include <gc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i;
    float *a, d;
    clock_t start, t1, t2;
    GC_INIT();
    printf("Defina o tamanho do vetor: ");
    scanf("%d", &n);
    start = clock();
    a = (float*)GC_MALLOC(n*sizeof(float));
    GC_FREE(a);
    t1 = clock();
    a = (float*)malloc(n*sizeof(float));
    free(a);
    t2 = clock();
    printf("Tempo levado pela libGC: %f s\n", ((float)(t1-start))/CLOCKS_PER_SEC);
    printf("Tempo levado pela stdlib: %f s\n", ((float)(t2-t1))/CLOCKS_PER_SEC);
    return 0;
}