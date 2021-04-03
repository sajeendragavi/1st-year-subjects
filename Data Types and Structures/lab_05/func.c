#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "head.h"

#define INIT_SIZE 1

/*INITIATE LIST*/
node *init_node(void)
{
	node *a = (node *)malloc(sizeof(node));
	if (a == NULL)
		exit(EXIT_FAILURE);
    a->len = 0;
    a->allocated = 0;
    a->data = NULL;
	return a;
}

/*CREATE LIST*/
int append(node *head, int item)
{
    if (!head->data)
    {
        head->data = malloc(INIT_SIZE * sizeof(int));

        if (!head->data)
		{
			printf("!!! Memory has not enough to allocate !!!");
            return -1;
		}

        head->allocated = INIT_SIZE;
    }
    else
        if (head->len >= head->allocated)
        {
            int *tmp = realloc(head->data, head->allocated * 2 * sizeof(int));

            if (!tmp)
			{
				printf("!!! Memory has not enough to allocate !!!");
                return -1;
			}

            head->data = tmp;
            head->allocated *= 2;
        }

    head->data[head->len] = item;
    head->len++;

    return 0;
}
void removee(node *head, int i)
{
	if (i < 0 || i > head->len)
		printf("!!! Position is wrong ! Try again !!!");
	else
	{
		memmove(head->data + i, head->data + i + 1, (head->len - i - 1) * sizeof(int));
		head->len--;
	}
}

int find(node *head, int item)
{
	for (int i = 0; i < head->len; i++)
		if (head->data[i] == item)
		{
			printf("*****************\n");
			printf("Number %d in positon %d", item, i+1);
			printf("*****************\n");
			return 1;
			break;
		}
	return 0;
}

void print(const node *head)
{
	printf("*****LIST*******\n");
	
    for (int i = 0; i < head->len; i++)
	{
        printf("%d ", head->data[i]);
	}
	
	printf("\n");
	printf("*****************\n");
}