#include <stdio.h>
#include <string.h>
#ifndef __HEAD__H__
#define __HEAD__H__

struct node_
{
    int len;
    int allocated;
    int *data;
};

typedef struct node_ node;

node *init_node(void);

int append(node *head, int item);

void removee(node *head, int i);

int find(node *head, int item);

void print(const node *head);

#endif