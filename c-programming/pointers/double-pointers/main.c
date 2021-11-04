#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var;
    int *sptr;

    var = 10;
    printf("Var : %d\n", var);
    printf("Address of Var : %p\n", &var);
/*
    *sptr = 20;
    printf("*sptr   : %p\n", *sptr);
    printf("sptr    : %p\n", sptr);
    printf("&sptr   : %p\n", &sptr);
    printf("*&sptr  : %p\n", *&sptr);
*/

/*
    *sptr = 10;
    printf("*sptr   : %d\n", *sptr);
    ++*sptr;
    printf("*sptr   : %d\n", *sptr);
    (*sptr)++;
    printf("*sptr   : %d\n", *sptr);

    sptr = &var;
    *sptr++;
    printf("sptr   : %p\n", sptr);
    printf("*sptr   : %d\n", *sptr);        // junk value
*/

    int **dptr = NULL;
    sptr = &var;
    printf("*sptr  : %d\n", *sptr);

    dptr = &sptr;
    printf("**dptr  : %d\n", **dptr);

    printf("*dptr   : %p\n", *dptr);
    printf("sptr    : %p\n", sptr);

    printf("&*dptr  : %p\n", &*dptr);
    printf("dptr    : %p\n", dptr);


/*
    int **dptr;
    dptr = 30;
    printf("**dptr : %d\n", **dptr);
*/

//    printf("Hello world!\n");
    return 0;
}
