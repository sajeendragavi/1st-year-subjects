#ifndef FUNC_SORT_H
#define FUNC_SORT_H

#include "allstructs.h"

#define SUCCESS 0
#define MEMORY_ALLOCATION_ERROR -5 

int sort_table(struct stud* array, int n, int *const time_bubble, int *const time_qsort);
void my_sort(void *base, size_t num, size_t size,int (*compare)(const void *, const void *));
void swap(void *, void *, int);
unsigned long long gettick(void);
int cmpfunc(const void *a, const void *b);
int sort_keyarray(struct stud* array,int n,int **kp,int *const time_bubblesort,int *const time_qsort);
int cmpfunc_key(const void *a, const void *b);

#endif