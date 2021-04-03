#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


struct Node
{
	int data;
	struct Node *next;
	
};

void add_data(int x);
void delete_data(int x);
void print_list(struct Node** head);

int main()
{
	int a;
	struct Node* front = NULL;
	struct Node* rear = NULL;
	printf("input value:");
	scanf("%d",&a);
	add_data(a,front,rear);
	print_list(front);
	
	
}
void creat_list()
{
	
	
	
}

void add_data(int x,struct Node *front,struct Node *rear)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct node*));
	temp->data = x;
	temp->next = NULL;
	if(front == NULL && rear == NULL)
	{
		front = rear = temp;
		return;
			
	}
	rear->next = temp;
	rear = temp;
	
}

void delete_data(int x)
{
	struct Node* temp = front;
	if(front == NULL) return;
	if(front == rear)
	{
		front = rear = NULL;
		
	}
	else
	{
		front = front-> next;
		
	}
	free(temp);
}

void print_list(struct Node** head)
{
	if(*head != NULL)
	{
		stack_node* temp = *head;
		printf("\nlist is:\n");
		while(temp != NULL)
		{
			printf(" %d",temp->data);
			temp=temp->next;
		
		}
		printf("\n");
		printf("remove element : %d\n",*array2);
	}
	else
	{
		printf("empty list..!!\n");
		
	}
	
	
}