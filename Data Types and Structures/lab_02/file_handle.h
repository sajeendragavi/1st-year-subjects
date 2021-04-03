#ifndef _FILE_HANDLE_H
#define _FILE_HANDLE_H

#include "allstructs.h"

#define SUCCESS 0
#define ERROR_OPENING_FILE -2
#define INPUT_ERROR -3
#define EMPTY_ARRAY -4
#define MEMORY_ALLOCATION_ERROR -5

#define MAX_LEN_STR 25

int read_info(const char *const argv, struct stud **p, int *const n);
int write_file(const char *const argv, const struct stud *const array, const int n);
char* read_word(FILE *f);

#endif