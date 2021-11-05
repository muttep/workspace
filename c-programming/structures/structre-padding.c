#include <stdio.h>
#include <stdlib.h>


/*
struct node {
    char * word;
    int count;
    //int x;
    //int u;
    //struct node *left,*right;
};
*/

//#pragma pack(1)
struct node {
    int data;
    struct node *next;
};
//}__attribute__((packed));



int main()
{
    printf("sizeof node : %d\n", (int)sizeof(struct node));
    printf("sizeof int* : %d\n", (int)sizeof(int *));
    printf("sizeof int : %d\n", (int)sizeof(int));
    return 0;
}