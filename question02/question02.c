#include <stdio.h>

int main() 
{
    int i = 5, *p;
    p = &i;
    // Se &i fosse 4094, teriamos: 4094 7 5 15 9
    printf("4094 %d %d %d %d\n", *p+2, **&p, 3**p, **&p+4);
    return 0;
}