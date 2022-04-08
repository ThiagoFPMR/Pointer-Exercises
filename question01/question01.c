#include <stdio.h>

int main()
{
    int i=3, j=5;
    int *p, *q;
    p = &i;
    q = &j;

    // a) True
    printf("%d (1 - True; 0 - False)\n", p == &i);
    // b) -2
    printf("%d\n", *p - *q); // -2
    // c) 3
    printf("%d\n", **&p); // 3
    // d) 10
    printf("%d\n", 3 - *p/(*q) + 7);

    return 0;
}