#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "allstructs.h"

#define SUCCESS 0
#define INPUT_ERROR -3
#define MEMORY_ALLOCATION_ERROR -5

#define NOTHING_DELETED -6
#define NOTHING_FOUND -7

int add_stud(struct stud** info, int* const n);
int delete_stud(struct stud** info,const char* const deleteperson,int *const n);
void write(FILE *f, const struct stud* const array, const int n);
void print(const struct stud* const array, const int n);
int find_personbd(struct stud* array,const int n,int *month,int *date);

#endif