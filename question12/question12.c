#include <stdio.h>

void say_hello() {
    printf("Hello World!\n");
    return;
}

int main() {
    void (*f_ptr)() = say_hello;    

    f_ptr();

    return 0;
}