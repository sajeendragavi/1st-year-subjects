#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main(void)
{
	int x, i, n, res;
	int rc = 0, choice;
	node *head = init_node();
	
	while(1)
	{
		printf("\n***********************************************************\n");
		printf("Menu:\n\t"
		   "1 - Add to end element;\n\t"
		   "2 - Delete element;\n\t"
		   "3 - Find element;\n\t"
		   "4 - Exit;\n");
		printf("Input choice: ");
		if (scanf("%d", &choice) != 1)
			printf("Input number from 1 to 5");
		else
		{
			switch(choice)
			{
				printf("\n");
				case 1:
					printf("Input number: ");
					scanf("%d", &x);
					rc = append(head, x);
					printf("\n");
					print(head);
					break;
				case 2:
					printf("Input element's position: ");
					scanf("%d", &i);
					removee(head, i-1);
					printf("\n");
					print(head);
					break;
				case 3:
					printf("Input number: ");
					scanf("%d", &n);
					res = find(head, n);
					if (res == 0)
					{
						printf("*****************\n");
						printf("Can't find number %d in list\n", n);
						printf("*****************\n");
						rc = append(head, n);
						print(head);
					}
					printf("\n");
					break;
				case 4:
					exit(0);
					free(head);
					free(head->data);
					break;
				default:
					printf("UNKNOWN CHOISE!\n");
					break;
			}
		}
	}
	return rc;
}