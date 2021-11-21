#include <stdio.h>
#include <stdlib.h>

typedef struct dnode
{
	int data;
	struct dnode *next;
	struct dnode *prev;

}dnode;

dnode *create_list (void)
{
	dnode *nnode, *left=NULL, *right=NULL;
	int num;

	
	do
	{
		printf ("enter num to push list or -999 to terminate\t");
		scanf ("%d", &num);

		nnode = (dnode *)malloc (sizeof (dnode));
		if (nnode == NULL)
		{
			printf ("Out of space");
			return NULL;
		}
		else if (num != -999)
		{
			
			if (left == NULL)
			{
				nnode->data = num;
				nnode->next = NULL;
				nnode->prev = NULL;

				left = nnode;
				right = nnode;	
			}
			else
			{
				nnode->data = num;
				right->next = nnode;
				nnode->prev = right;

				nnode->next = NULL;

				right = nnode;
			}
		}
	}while (num != -999);

	return left;
}

void print_list (dnode *head)
{
	int i;
	dnode *tmp = NULL;
	
	tmp = (dnode *)head;
	while(tmp->next != NULL)
	{
		printf ("%d <=> ", tmp->data);
		tmp = tmp->next;
	}
	printf ("%d\n", tmp->data);
}

dnode *find_list (dnode *head, int f)
{
	dnode *tmp;

	tmp = head;

	while ((tmp->data != f) && (tmp->next != NULL))
	{
		tmp = tmp->next;
	}
	return tmp;
}

dnode *insert (dnode *left)
{
	dnode *tmp, *find, *ins, *right=NULL;
	int n, a;

	printf ("\nenter the num to insert\t");
	scanf ("%d", &n);
	printf ("\nafter which num want to insert ?\t");
	scanf ("%d", &a);

	ins = (dnode *)malloc (sizeof (dnode));
	if (ins == NULL)
	{
		printf ("out of space");
		return NULL;
	}
	else
	{
		ins->data = n;
		ins->next = NULL;
		ins->prev = NULL;
	}
	
	find = find_list (left, a);
	if ((find->data != a) && (find->next == NULL))
	{
		printf ("inserting at last position\n");
		
		find->next = ins;
		ins->prev = find;

		ins = right;
	}
	else if (find->next == NULL)
	{
		find->next = ins;
		ins = right;
	}
	else	
	{
		right = find->next;

		ins->next = right;
		right->prev = ins;

		find->next = ins;
		ins->prev = find;
	}
	return left;
}

dnode *delete_node (dnode *left)
{
	dnode *tmp=NULL, *find=NULL, *n=NULL, *p=NULL;
	int del;	

	tmp = left;
	
	printf ("enter the num to delete\t");
	scanf ("%d", &del);

	find = find_list (tmp, del);
	if (find->prev == NULL)
	{
		left = find->next;
		left->prev = NULL;
		free (find);
	}	
	else if (find->next == NULL)
	{
		p = find->prev;
		p->next = NULL;
		free (find);
	}
	else
	{
		n = find->next;
		p = find->prev;

		p->next = n;
		n->prev = p;

		free (find);
	}

	return left;
}

main()
{
	dnode *h, *find;
	int n;

	h = create_list (); 
	print_list (h);
	
	printf ("enter num to find\t");
	scanf ("%d", &n);
	
	find = find_list (h, n);
	if (find->data == n)
	{
		printf ("\n% is in the list", n);
	} 
	else
	{
		printf ("\ngiven num is not in the list");
	}

	h = insert (h);
	print_list (h);

	h = delete_node (h);
	print_list (h);

 
}
