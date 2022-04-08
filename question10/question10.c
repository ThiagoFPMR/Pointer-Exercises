#include <stdio.h>

typedef struct {
    char a;
    char b;
} h_int;

/* Chars já ocupam 1 byte, floats ocupam 4 bytes e 
   doubles ocupam 8 bytes. Ou seja, apenas foi necessario
   criar um tipo para o nosso int hipotetico (h_int) */

int main()
{
    char vc[4];
    h_int vi[4];
    float vf[4];
    double vd[4];
    int start = 4092, bytevalues[4] = {1, 2, 4, 8};

    printf("------------------Exemplo Ideal------------------\n");
    printf("%d, %d, %d | Char   -  %d byte(s)\n", start+1*bytevalues[0], start+2*bytevalues[0], start+3*bytevalues[0], bytevalues[0]);
    printf("%d, %d, %d | Int    -  %d byte(s)\n", start+1*bytevalues[1], start+2*bytevalues[1], start+3*bytevalues[1], bytevalues[1]);
    printf("%d, %d, %d | Float  -  %d byte(s)\n", start+1*bytevalues[2], start+2*bytevalues[2], start+3*bytevalues[2], bytevalues[2]);
    printf("%d, %d, %d | Double -  %d byte(s)\n", start+1*bytevalues[3], start+2*bytevalues[3], start+3*bytevalues[3], bytevalues[3]);

    printf("\n------------------Exemplo Real------------------\n");
    printf("%X, %X, %X | Char   -  %d byte(s)\n", vc+1, vc+2, vc+3, sizeof(char));
    printf("%X, %X, %X | Int    -  %d byte(s)\n", vi+1, vi+2, vi+3, sizeof(h_int));
    printf("%X, %X, %X | Float  -  %d byte(s)\n", vf+1, vf+2, vf+3, sizeof(float));
    printf("%X, %X, %X | Double -  %d byte(s)\n", vd+1, vd+2, vd+3, sizeof(double));

    return 0;
}