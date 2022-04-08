#include <stdio.h>

int main(void)
{
    float vet[5] = {1.1,2.2,3.3,4.4,5.5};
    float *f;
    int i;
    f = vet;
    printf("contador/valor/valor/endereco/endereco");
    for(i = 0 ; i <= 4 ; i++)
    {
        // Imprime o número da iteração
        printf("\ni = %d",i);
        /* As duas de baixo imprimem o iésimo elemento
           do vetor */
        printf("vet[%d] = %.1f",i, vet[i]);
        printf("*(f + %d) = %.1f",i, *(f+i));
        /* As duas de baixo imprimem o endereço de
           memória do iésimo elemento do vetor */
        printf("&vet[%d] = %X",i, &vet[i]);
        printf("(f + %d) = %X",i, f+i);
    }
    printf("\n");
    return 0;
}
