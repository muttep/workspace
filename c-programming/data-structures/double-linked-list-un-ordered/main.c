#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
}__attribute__((packed));

typedef struct node dptr;

dptr* create_double_list(dptr *L, dptr* R) {
    dptr *new_node = NULL;
    int num = 0;

    while(1) {
        printf("Enter the number to input or -999 to exit : ");
        scanf("%d", &num);

        if(num == -999) {
            break;
        } else {
            new_node = (dptr *)malloc(sizeof(dptr));
            if(new_node == NULL) {
                printf("Out of space for new new_node\n");
                return NULL;
            } else {
                new_node->data = num;
                if(L == NULL) {
                    new_node->left = NULL;
                    new_node->right = NULL;
                    L = new_node;
                    R = new_node;
                } else {
                    new_node->right = NULL;
                    R->right = new_node;
                    new_node->left = R;
                    R = new_node;
                }
            }
        }

    }
    return L;
}

void print_double_list(dptr *L) {
    dptr *temp = NULL;
    temp = L;

    while(temp->right != NULL) {
        printf("%d\t", temp->data);
        temp = temp->right;
    }
    printf("%d\n", temp->data);
}

dptr* find_element(dptr *L, int num) {
    dptr *temp = NULL;

    temp = L;

    while((temp->right != NULL) && (temp->data != num)) {
        temp = temp->right;
    }
    return temp;
}

dptr* delete_element(dptr *L, dptr *R) {
    int num = 0;
    dptr *pos = NULL;

    printf("Enter the number to delete from the list : ");
    scanf("%d", &num);

    pos = find_element(L, num);
    printf("pos : %d\n", pos->data);
    if(pos->right == NULL) {
        printf("pos reached last\n");
    }

    printf("pos->right  : %p\n", pos->right);
    //printf("L->right    : %p\n", L->right);
    //printf("R->right    : %p\n", R->right);

    printf("pos : %p\n", pos);
    printf("L   : %p\n", L);
    printf("R   : %p\n", R);

    if(L == R) {
        printf("L == R\n");
        L = NULL;
        R = NULL;
    } else if(pos == L) {
        printf("pos == L\n");
        L = L->right;
        L->left = NULL;
    } else if(pos->right == R) {
        printf("pos == R-1\n");
        R = R->left;
        printf("pos == R-2\n");
        R->right = NULL;
        printf("pos == R-3\n");
    } else {
        printf("pos is in middle or some where\n");
        pos->left->right = pos->right;
        pos->right->left = pos->left;
    }
    printf("before free\n");
    free(pos);
    printf("after free\n");
    return L;
}

int main()
{
    dptr *L, *R;
    int choice = 0;

    L = NULL;
    R = NULL;

    while(1) {
        printf("1 - Create the double linked list\n");
        printf("2 - Print the double linked list\n");
        printf("3 - Delete the double linked list\n");
        printf("0 - Exit\n");
        scanf("%d", &choice);
        if(choice == 0) {
            break;
        } else {
            switch(choice) {
                case 1 :    L = create_double_list(L, R);
                            break;
                case 2 :    print_double_list(L);
                            break;
                case 3 :    delete_element(L, R);
                            break;

                default :   printf("Enter the right choice : ");
            }
        }
    }

    return 0;
}
