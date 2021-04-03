#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define N 3
#define size 1

//enum {size = 0};

// structure represent a stack
typedef struct stack stack_t;
struct stack
{
	int top;
	unsigned capacity;
	int *arraystack;
	
};
//structure represent a linekd list
typedef struct Node stack_node;

struct Node 
{
	int data;
	stack_node* next;

};
unsigned long tick(void);
void delete_element(stack_node** head,int n,int *array2);
void insert_list(stack_node** head,int data);
void print_list(stack_node** head,int *array2);

stack_t* createstack(unsigned capacity);
int isempty(stack_t* stack);
int isfull(stack_t* stack);
void print_stack(stack_t* stack,int *array1);
int pop_element(stack_t* stack,int *array1);
void push_element(stack_t* stack,int ele);

//creation of stack array
stack_t* createstack(unsigned capacity)
{
	stack_t* stack = (stack_t*) malloc(sizeof(stack_t));
	stack->capacity=capacity;
	stack->top = -1;
	stack->arraystack = (int*)malloc((stack->capacity)*sizeof(int));
	return stack;
	
}


int main()
{
	
	
	int *array1= (int*)malloc(size*sizeof(int));
	int *array2 = (int*)malloc(size*sizeof(int));
	
	
	
	stack_node* head = NULL;
	int choisea = -1,inputval;
	int inputno,loc;
	unsigned sizearray;
	printf("implement stack method-> 1.using array\n       "
	"                  2.using linked list\n");
	printf("\nenter the method no: ");
	scanf("%d",&inputno);
	int flag1 = 8;
    //while(flag1 != 0)
	//{		// change to menu
	if(inputno == 1)
	{
		
		unsigned long tb1, te1, tb2, te2, tb3, te3;
		printf("stack linked array::\n\n");
		printf("\nenter the size of stack array: ");
		scanf("%d",&sizearray);
		stack_t* stack = createstack(sizearray);
		while(choisea != 0)
		{
			printf("\nMenu \n 1.add element\n 2.remove element\n 3.print stack array\n 4.exit(0)");
			printf("\nenter the operation no: ");
			scanf("%d",&choisea);
			if(choisea == 1)
			{
			
				printf("added the memory address as value");
				//printf("\nenter the value to stack:");
				//scanf("%d",&inputval);
				tb1 = tick();
				push_element(stack,inputval);
				te1 = tick();
				//printf("\nTime add = %lu\n", ((te1 - tb1) / N));
			}
			else if(choisea == 2)
			{
				tb2 = tick();
				pop_element(stack,array1);
				te2 = tick();	
			}
			else if(choisea == 3)
			{
				tb3 = tick();
				print_stack(stack,array1);
				te3 = tick();	
			}
			/*else
			{
				printf("input error..!!\n");
				
			}*/
		}
		printf("\nTime add = %lu\n", ((te1 - tb1) / N));
		printf("\nTime delete = %lu\n", ((te2 - tb2) / N));
		printf("\nTime print = %lu\n", ((te3 - tb3) / N));
		
	}
	
	else if(inputno == 2)
	{
		unsigned long tb1, te1, tb2, te2, tb3, te3;
		int element;
		printf("stack linked list::\n\n");
		int operation = 4;
		while(operation != 0)
		{
			printf("operatios-> 1.add element\n            2.delete element\n"
			"            3.print list\n");
			printf("\nchoose the operation:");
			scanf("%d",&operation);
			
			if(operation == 1)
			{
				printf("added the memory address as value");
				//printf("\ninput element to the list: ");
				//scanf("%d",&element);
				tb1 = tick();
				insert_list(&head,element);
				te1 = tick();
			}
			else if(operation == 2)
			{
				printf("enter deleting position:");
				scanf("%d",&loc);
				tb2 = tick();
				delete_element(&head,loc,array2);
				te2 = tick();
			}
			else if(operation == 3)
			{
				tb3 = tick();
				print_list(&head,array2);
				te3 = tick();
			}
			/*else
			{
				printf("\ninput error..!!");
			
			}*/
			
		}
		printf("\nTime add = %lu\n", ((te1 - tb1) / N));
		printf("\nTime delete = %lu\n", ((te2 - tb2) / N));
		printf("\nTime print = %lu\n", ((te3 - tb3) / N));
		
	}
	
	else
	{
		printf("input error..!!\n");
		
	}
	
	getch();
	return 0;
}

void push_element(stack_t* stack,int ele)
{
	//int *ad = &ele;
	//intptr_t adv = (intptr_t) ad;
	if(isfull(stack))
	{
		printf("\nstack is full..!!!\n");
		
	}
	else
	{
		stack->top = stack->top + 1;
		intptr_t poad = (intptr_t)(&(stack->arraystack[stack->top]));
		//stack->arraystack[stack->top] = ele;
		stack->arraystack[stack->top] = poad;
		//printf("\npushed element to the stack:%d\n",ele); 
		printf("\npushed element to the stack:%lu\n",poad);
	}
	
	
	
}

int pop_element(stack_t* stack,int *array1)
{
	int removeelement;
	if(isempty(stack))
	{
		printf("stack is empty..!!\n");
		
	}
	else
	{
		
		removeelement = stack->arraystack[stack->top];
		*array1 = removeelement;
		stack->top--;
		printf("\npoped the element from the stack..!!");
		return stack->top;	
	}	
}

void print_stack(stack_t* stack,int *array1)  // add remvalue 
{
	if(isempty(stack))
	{
		printf("\nempty stack array..!!\n");
		
	}
	else
	{
		for(int i = stack->top;i > -1;i--)
		{
			printf("%d\n",stack->arraystack[i]);
		}
		printf("remove element : %d\n",*array1);
	}
	
	
	
}

int isfull(stack_t* stack)
{
	if(stack->top == stack->capacity-1)
	{
		return 1;
		
	}
	else
	{
		return 0;
		
	}	
}

int isempty(stack_t* stack)
{
	if(stack->top == -1)
	{
		return 1;
		
	}
	else
	{
		return 0;
	}
	
}

void insert_list(stack_node** head,int data)
{
	stack_node* newnode = (stack_node*)malloc(sizeof(stack_node));
	
	//intptr_t poad = (intptr_t)(*newnode);
	
	//newnode->data = poad;
	newnode->next = NULL;
	if(*head == NULL)
	{
		
		*head = newnode;
		 intptr_t poad = (intptr_t)(*head); //change
		 newnode->data = poad;
	}
	else
	{
		stack_node* current;
		current = *head;
		while(current->next != NULL)
		{
			intptr_t poad = (intptr_t)(current->next); //change
			newnode->data = poad;
			current = current->next;
			
		}
		current->next = newnode;	
	}
	printf("added element to the list \n\n");
}

void delete_element(stack_node** head,int n,int *array2)  // get array2 
{
	if(*head != NULL)
	{
		stack_node* temp1 = *head;
		if(n == 1)
		{
			*head = temp1->next;
			free(temp1);
			*array2 = temp1->data;
		}
		else
		{
			int i;
			for(i = 0;i<n-2;i++)//change n-2
			{
				temp1 = temp1->next;
				
			}
			stack_node* temp2 = temp1->next;
			temp1->next = temp2->next;
			*array2 = temp2->data;
			free(temp2);
			
		}
		printf("deleting %d locating element..!!\n",n);
	}
	else
	{
		printf("empty list");
		
	}
	
	
	
}

void print_list(stack_node** head,int *array2)
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
unsigned long tick(void)
{
  unsigned long d;
  __asm__ __volatile__ ("rdtsc" : "=A" (d) );
  return d;
}
