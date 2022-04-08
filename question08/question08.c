#include <stdio.h>

void m1()
{
    int vet[] = {4,9,13};
    int i;
    for(i=0;i<3;i++)
    {
        printf("%d ",*(vet+i));
    }
    printf("\n");
}

void m2()
{
    int vet[] = {4,9,13};
    int i;
    for(i=0;i<3;i++)
    {
        printf("%X ",vet+i);
    }
    printf("\n");
}

int main()
{
    m1();
    m2();
    return 0;
}