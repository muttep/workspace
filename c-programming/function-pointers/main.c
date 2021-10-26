#include <stdio.h>
#include <stdlib.h>

#if 0
int display(void);

int main()
{
    int (*func_ptr)();

    func_ptr = display;

    printf("Address of function display() : %p\n", func_ptr);

    (*func_ptr)();

    return 0;
}

int display(void)
{

    printf("Function pointer called.\n");
}
#endif


void function1(int);
void function2(int);

typedef void FuncType(int);

int main(void)
{
    FuncType *func_ptr = NULL;

    func_ptr = function1;
    (*func_ptr)(100);

    func_ptr = function2;
    (*func_ptr)(200);


    return 0;
}

void function1(int a)
{

    printf("value : %d\n", a);
}

void function2(int b)
{

    printf("Value : %d\n", b);
}
