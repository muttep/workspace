#include <stdio.h>
#include <stdlib.h>

int addition(int a, int b)
{
    int c;

    c = a+b;

    return c;
}

int main()
{
    int x, y, z;

    x = 10;
    y = 20;

    z = addition(x, y);

    printf("Addition : %d", z);

    //printf("Hello world!\n");
    return 0;
}
