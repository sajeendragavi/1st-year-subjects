#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "file_handle.h"
#include "functions.h"
#include "allstructs.h"


//Returns the read to the first space or \ n string
char* read_word(FILE *f){
	char *str = malloc(MAX_LEN_STR * sizeof(char));
	char temp;
	int n = 0;
	
	while (fscanf(f, "%c", &temp) == 1){
		if (temp == ' ' || temp == '\n'){ if (n != 0) break;}
		else *(str + n++) = temp;
	}
	
	if (n == 0) return NULL;
	
	*(str + n) = '\0';
	str = realloc(str, (n+1) * sizeof(char));
	
	return str;
}

//Reads the table in an array of structures
int read_info(const char *const argv,struct stud **p,int *const n)
{

	FILE *f;
	char temp;
	struct stud *array;

	f = fopen(argv, "r");
    if (f == NULL) return ERROR_OPENING_FILE;

    while (fscanf(f, "%c", &temp) == 1) if (temp == '\n') (*n)++;

    if (feof(f) == 0){ fclose(f); return INPUT_ERROR; }
    if (*n == 0){ fclose(f); return EMPTY_ARRAY;}
    
	rewind(f);

    array = malloc(*n * sizeof(struct stud));
	*p = array;
    if (array == NULL){ fclose(f); return MEMORY_ALLOCATION_ERROR; }
	
	//Filling the array of structures
	for (int i = 0; i < *n; i++){
	    if (
			(array[i].last_Name = read_word(f)) == NULL ||
			(array[i].first_Name = read_word(f)) == NULL ||
			(fscanf(f, "%d", &(array[i].telephone_no))) != 1||
			(array[i].address = read_word(f)) == NULL ||
			(array[i].position = read_word(f)) == NULL || fscanf(f, "%d", &(array[i].date)) != 1 
			||fscanf(f, "%d", &(array[i].month)) != 1 || fscanf(f, "%d", &(array[i].year)) != 1  ){ 	
            fclose(f);
			free(array);
			return INPUT_ERROR;
		}
	} 
	
	while (fscanf(f, "%c", &temp) == 1)
	    if (!(temp == '\n' || temp == ' ' || temp == 'I'))
		{
			fclose(f);
			free(array);
		    return INPUT_ERROR;
		}
	
	if (feof(f) == 0)
	{
		fclose(f);
		free(array);
        return INPUT_ERROR;
	}
	
	fclose(f);
	return SUCCESS;
	
}

int write_file(const char *const argv,const struct stud *const array,const int n)
{
	FILE *f;
	f = fopen(argv,"w");
	if(f == NULL)
	{
		return ERROR_OPENING_FILE;
		
	}
	else
	{
		write(f,array,n);
		
	}
	fclose(f);
	return SUCCESS;
}

