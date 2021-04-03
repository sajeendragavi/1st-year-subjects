#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func_sort.h"
#include "allstructs.h"

int sort_table(struct stud* array,int n,int *const time_bubblesort,int *const time_qsort)
{
	int *array_2 = malloc(n*sizeof(array[0]));
	if(array_2 == NULL)
		return MEMORY_ALLOCATION_ERROR;
	
	memcpy(array_2,array,n*sizeof(array[0]));
	
	*time_bubblesort = gettick();
	my_sort(array,n,sizeof(array[0]),cmpfunc);
	*time_bubblesort = gettick() - *time_bubblesort;
	
	*time_qsort = gettick();
	qsort(array_2, n, sizeof(array[0]), cmpfunc);
	*time_qsort = gettick() - *time_qsort;
	
	free(array_2);
	return SUCCESS;
}

void my_sort(void *base, size_t num, size_t size,int (*compare)(const void *, const void *)) 
{
    char *pbegin = base;
    char *pend = pbegin + (num - 1) * size; 
    char  *ptemp = pbegin;
    
    while (pbegin != pend){
        
        for (char *pi = pbegin; pi < pend; pi += size)
            
            (compare(pi, pi + size) > 0) ?
                  swap(pi, pi + size, size), ptemp = pi : 0;
        
        pend = ptemp;
        
       
        for (char *pi = pend - size; pi >= pbegin; pi -= size)
            
			(compare(pi, pi + size) > 0) ? 
                swap(pi, pi + size, size), ptemp = pi + size : 0;

        
        pbegin = ptemp;     
    }
	
}

int sort_keyarray(struct stud* array,int n,int **kp,int *const time_bubblesort,int *const time_qsort)
{
	int *kp_2 = malloc(n*sizeof(kp[0]));
	if(!*time_bubblesort)
		*kp = realloc(*kp,n*sizeof((*kp)[0]));
	
	for (int i = 0; i < n; i++) 
		(*kp)[i] = i;
	
	memcpy(kp_2,*kp,n*sizeof((*kp)[0]));
	
	//kp_2 = realloc(*kp,n*sizeof((*kp)[0]));
	
	*time_bubblesort = gettick();
	my_sort(*kp,n,sizeof((*kp)[0]),cmpfunc_key);
	*time_bubblesort = gettick() - *time_bubblesort;
	
	*time_qsort = gettick();
	qsort(*kp, n, sizeof((*kp)[0]), cmpfunc_key);
	*time_qsort = gettick() - *time_qsort;
	
	free(kp_2);
	return SUCCESS;
}

unsigned long long gettick(void){
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
	
    return d;
}
void swap(void *i, void *j, int size){
    int *temp = malloc(size);
    
    memmove(temp, i, size);
	memmove(i, j, size);
    memmove(j, temp, size);
	
	free(temp);
}
int cmpfunc (const void * a, const void * b)
{	
   return strcmp(((struct stud*)a)->last_Name , ((struct stud*)b)->last_Name);
}
int cmpfunc_key(const void *a, const void *b) 
{
	extern struct stud *array;
	
	return strcmp(array[*((int*)a)].last_Name ,array[*((int*)b)].last_Name); 
}


