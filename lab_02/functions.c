#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_handle.h"
#include "functions.h"
#include "allstructs.h"

//Reads data and adds an entry to an array of structures
int add_stud(struct stud** info, int* const n)
{
	struct stud new;
	if (
	    (printf("last Name: "), (new.last_Name = read_word(stdin)) == NULL) ||
		(printf("first Name: "), (new.first_Name = read_word(stdin)) == NULL)
		|| (printf("telephone no: "), scanf("%d", &(new.telephone_no)) != 1) || 
		(printf("address: "), (new.address = read_word(stdin)) == NULL) || 
		(printf("position: "), (new.position = read_word(stdin)) == NULL)||
		(printf("date : "), scanf("%d", &(new.date)) != 1) || 
		(printf("month: "), scanf("%d", &(new.month)) != 1) || 
		(printf("year: "), scanf("%d", &(new.year)) != 1) )

        return INPUT_ERROR;
		
	*info = realloc(*info, (*n + 1) * sizeof((*info)[0]));
    if (*info == NULL)
	{
		return MEMORY_ALLOCATION_ERROR;
	}			
	
	(*info)[*n] = new;
	*n = *n + 1;
	
	return SUCCESS;
	
}
//function to delete a person 
int delete_stud(struct stud** info,const char* const deleteperson,int *const n)
{
	int deletedV = 0;
	int lastchecked = 0;
	
	while(lastchecked != *n)
	{
		for(int i = lastchecked ;i < *n; i++)
		{
			if(strcmp((*info)[i].last_Name, deleteperson) == 0)
			{
				memmove(*info + i,*info + i + 1,(*n - i - 1)*sizeof((*info)[0]));
				*info = realloc(*info,(*n-1) * sizeof((*info)[0]));
				if(*info == NULL)
				{
					return MEMORY_ALLOCATION_ERROR;		
				}
				*n = *n -1;
				deletedV = 1;
				break;
			}
			
			lastchecked = i + 1;
		}
		
		
	}
	if(!deletedV)
	{
		return NOTHING_DELETED;
	}
	else
	{
		return SUCCESS;	
	}
}

// write data in table  and file 
void write(FILE *f, const struct stud* const array, const int n)
{
    for (int i = 0; i < n; i++)
	{
		fprintf(f,"%-16s %-20s %-14d %-14s %-24s %-6d %-4d %-2d \n", 
		    array[i].last_Name, array[i].first_Name, array[i].telephone_no,
			array[i].address,array[i].position,array[i].date,array[i].month,array[i].year);
	  
    }		
}

// print table in screen  
void print(const struct stud* const array, const int n)
{
	printf("---------------------------------------------------------------------------------------------------\n"
	    
		"\nlast Name      first Name         telephone no        address       position     BirthDay->  "  
		"Date  Month  Year  "
		"\n-----------------------------------------------------------------------------------------------------\n");
	write(stdout, array, n);
	printf("-----------------------------------------------------------------------------------------------------\n\n");
}
int  find_personbd(struct stud* array,const int n,int *month,int *date)
{
	int flag = 0;
	printf("\n i have to wish HBD these friends this week ...\n\n");  
	for (int i = 0; i < n; i++){
		if (array[i].month == *month && array[i].date  > *date && array[i].date  < *date + 7)
		{
			if (flag == 0){
				flag = 1;
                
			}
			                                                                                         
			
			printf("%-16s %-20s %-14d %-14s %-24s %-6d %-4d %-2d \n", 
		    array[i].last_Name, array[i].first_Name, array[i].telephone_no,
			array[i].address,array[i].position,array[i].date,array[i].month,array[i].year);
			
	    }	
	}
	printf("   \n");
	if (flag == 0)
		return NOTHING_FOUND;
	return SUCCESS;
	
	
}