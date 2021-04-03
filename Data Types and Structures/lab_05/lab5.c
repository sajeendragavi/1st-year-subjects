#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 3


//linked list node to queue entry
struct Qnode
{
	int data;
	struct Qnode *next;	
	struct Qnode *prev;
};
void deleteNode(struct Qnode** head_ref, struct Qnode* del);
void append(struct Qnode** head_ref, int value);
void printList(struct Qnode* node) ;



unsigned long tick(void)
{
  unsigned long d;
  __asm__ __volatile__ ("rdtsc" : "=A" (d) );
  return d;
}
void append(struct Qnode** head_ref, int value)
{	
	
    struct Qnode* new_node = (struct Qnode*)malloc(sizeof(struct Qnode)); 
  
    struct Qnode* last = *head_ref; 
  
    new_node->data = value; 
  
    new_node->next = NULL; 
  
    if (*head_ref == NULL) { 
        new_node->prev = NULL; 
        *head_ref = new_node; 
        return; 
    } 
  
    while (last->next != NULL) 
        last = last->next; 
  
    last->next = new_node; 
  
    new_node->prev = last; 
  
    return; 
	
}

void deleteNode(struct Qnode** head_ref, struct Qnode* del)
{
	
	
    if (*head_ref == NULL ) 
        return; 
  
     
    if (*head_ref == del) 
        *head_ref = del->next; 
  
   
    free(del); 
    return; 	
}

void printList(struct Qnode* node) 
{ 
    while (node != NULL) { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 

int main()
{
	
	unsigned long tb1, te1, tb2, te2, tb3, te3;
	struct Qnode* head = NULL;
	printf("implement Queue using linked list:\n exit->0");
	
	int choise = 4;
	int val;
	
	while(choise != 0)
	{
		printf("\nchoose:\n\n""1.input data \n 2.delete data\n"
                              " 3.print data\n 4.exit->0\n");
		scanf("%d",&choise);					  
		if(choise == 1)
		{
			
			printf("input value :");
			scanf("%d",&val);
			tb1 = tick();
			append(&head,val);
			te1 = tick();
			printf("added in eding list to %d\n",val);
			
			
		}			
		else if(choise == 2)
		{
			tb2 = tick();
			deleteNode(&head,head);
			te2 = tick();
			printf("deleted front elemnet in the list..!!\n");
		}
		else if(choise == 3)
		{
			tb3 = tick();
			printList(head);
			te3 = tick();
		}
		else
		{
			printf("input error...!!\n");
			
		}
	}
	
	printf("\nTime add = %lu\n", ((te1 - tb1) / N));
	printf("\nTime delete = %lu\n", ((te2 - tb2) / N));
	printf("\nTime print = %lu\n", ((te3 - tb3) / N));
	
	getch();
	return 0;
}