#include <stdio.h>
#include <stdlib.h>

//#pragma pack(1)
struct node {
    int data;
    struct node *next;
}__attribute__((packed));

typedef struct node nptr;


nptr* create_head(void) {
    nptr *head = NULL;

    head = (nptr *)malloc(sizeof(nptr));
    if(head == NULL) {
        printf("Out of pace for head\n");
        return NULL;
    } else {
        head->next = NULL;
        return head;
    }
}

nptr* find_last_node(nptr *head) {
    nptr *temp = NULL;

    temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    return temp;
}

nptr* create_list(void) {
    nptr *head = NULL, *new_node = NULL, *last_node = NULL;
    int num = 0;

    head = create_head();

    while(1) {
        printf("Enter the number to input or -999 to exit : ");
        scanf("%d", &num);

        if(num == -999) {
            break;
        } else {
            new_node = (nptr *)malloc(sizeof(nptr));
            if(new_node == NULL) {
                printf("Out of space for new_node\n");
                return NULL;
            } else {
                new_node->data = num;
                last_node = find_last_node(head);           // find last node
                last_node->next = new_node;
                new_node->next = NULL;
            }
        }
    }
    return head;
}

void print_list(nptr *head) {
    nptr *temp = NULL;

    temp = head->next;
#if 1
    while (temp->next != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\t", temp->data);
#else
    do {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp->next != NULL);
    printf("%d\t", temp->data);
#endif

    printf("\n");
}

void find_element_in_list(nptr *head, int find) {
    nptr *temp = NULL;

    temp = head->next;

    while(temp->next != NULL) {
        if(temp->data == find) {
            printf("%d Element is found in the list\n", find);
            break;
        } else {
            temp = temp->next;
        }
    }

    if(temp->next == NULL) {
        printf("%d Element is not found in the list\n", find);
    }
}

nptr* insert_at_end(nptr *head, int insert) {
    nptr *last = NULL, *insert_node = NULL;

    insert_node = (nptr *)malloc(sizeof(nptr));
    if(insert_node == NULL) {
        printf("Out of memory to insert node\n");
        return NULL;
    } else {
        insert_node->data = insert;
        last = find_last_node(head);
        last->next = insert_node;
        insert_node->next = NULL;
    }
    return head;
}

int main()
{
    int choise = 0, find_element = 0, insert_element = 0;
    nptr *head = NULL;

    while(1) {
        printf("1 - Create the list\n");
        printf("2 - Print the list\n");
        printf("3 - Find the element in list\n");
        printf("4 - Insert element at end of the list\n");
        printf("0 - Exit\n");
        scanf("%d", &choise);

        switch(choise) {
            case 0  :   return 0;
            case 1  :   head = create_list();
                        break;
            case 2  :   if(head == NULL) {
                            printf("List is empty\n");
                        } else {
                            print_list(head);
                        }
                        break;
            case 3  :   if(head == NULL) {
                            printf("List is empty\n");
                        } else {
                            printf("Enter the number to find the list : ");
                            scanf("%d", &find_element);
                            find_element_in_list(head, find_element);
                        }
                        break;
            case 4  :   printf("Enter the number to insert in the list : ");
                        scanf("%d", &insert_element);
                        insert_at_end(head, insert_element);
                        break;
            default :   printf("Enter your correct choice : \n");
        }
    }

    return 0;
}
