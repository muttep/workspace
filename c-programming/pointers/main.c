#include <stdio.h>
#include <stdlib.h>

#if 0
void foo(int *ptr) {

    int a = 5;
    printf("*ptr-1 : %d, ptr : %u\n", *ptr, ptr);
    ptr = &a;
    printf("   a-1 : %d, &a : %u\n", a, &a);
    printf("*ptr-2 : %d, ptr : %u\n", *ptr, ptr);
}

int main()
{
    int *ptr = NULL;

    ptr = (int *)malloc(sizeof(int));

    *ptr = 10;

    printf("*ptr-3 : %d, ptr : %u\n", *ptr, ptr);

    foo(ptr);

    printf("*ptr-4 : %d, ptr : %u\n", *ptr, ptr);

    return 0;
}
#endif

#if 0
void foo(int *ptr) {

    int a = 5;
    printf("*ptr-1 : %d, ptr : %u\n", *ptr, ptr);
    *ptr = a;
    printf("   a-1 : %d,  &a : %u\n", a, &a);
    printf("*ptr-2 : %d, ptr : %u\n", *ptr, ptr);
}

int main()
{
    int *ptr = NULL;

    ptr = (int *)malloc(sizeof(int));

    *ptr = 10;

    printf("*ptr-3 : %d, ptr : %u\n", *ptr, ptr);

    foo(ptr);

    printf("*ptr-4 : %d, ptr : %u\n", *ptr, ptr);

    return 0;
}
#endif

#if 0
void foo(int **ptr) {

    int a = 5;
    printf("*ptr-1 : %d, ptr : %u\n", **ptr, ptr);
    *ptr = &a;
    printf("   a-1 : %d,  &a : %u\n", a, &a);
    printf("*ptr-2 : %d, ptr : %u\n", **ptr, ptr);
}

int main()
{
    int *ptr = NULL;

    ptr = (int *)malloc(sizeof(int));

    *ptr = 10;

    printf("*ptr-3 : %d, ptr : %u\n", *ptr, ptr);

    foo(&ptr);

    printf("*ptr-4 : %d, ptr : %u\n", *ptr, ptr);

    return 0;
}
#endif


int main()
{
    int num = 222;
    int *sPtr = NULL;
    int **dPtr = NULL;

    sPtr = &num;
    dPtr = &sPtr;

    printf("value of num : %d\n", num);
    printf("value of num using single pointer : %d\n", *sPtr);
    printf("value of num using double pointer : %d\n", **dPtr);

    printf("Address of num : %p\n", &num);
    printf("Address of num using single pointer : %p\n", sPtr);
    printf("Address of num using double pointer : %p\n", *dPtr);

    return 0;
}
