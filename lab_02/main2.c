#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "file_handle.h"
#include "functions.h"
#include "allstructs.h"
#include "func_sort.h"

#define WRONG_COMMAND_LINE -1

struct stud *array = NULL;

int main(int argc,char *argv[])
{
	int n = 0;
	int status;
	int menu;
	int *key_array = NULL;
	int t_time_bubble,t_time_qsort= 0;
	int k_time_bubble,k_time_qsort= 0;
	int month [25];
	int finddate;
	int *date;
	date = &finddate;
	
	if(argc != 2)
	{
		printf("wrong parameters..!!");
			return WRONG_COMMAND_LINE;
	}
	status = read_info(argv[1],&array,&n);
	if (status == ERROR_OPENING_FILE){
		printf("Error opening input file: %s\n", strerror(errno));
		return ERROR_OPENING_FILE;
	}
	else if (status == INPUT_ERROR){
		printf("Input error1\n");
		return INPUT_ERROR;
	}
	else if (status == EMPTY_ARRAY){
		printf("Empty array\n");
		return EMPTY_ARRAY;
	}
	else if (status == MEMORY_ALLOCATION_ERROR){
		printf("Memory allocation error\n");
		return MEMORY_ALLOCATION_ERROR;
	}
	
	//create menu
	while(1)
	{
		printf("          MENU:\n           0. Find country"
		"\n           1.print table\n         "
		"  2. Add a person\n           3.Delete a person\n       "
		"    4.sort table\n           5.sort and print key array\n           6.print table by key array\n"
    "           7.efficiency\n           8.save add data in file\n           9.exit \n   "
		
		
		"enter op no ->");
		
		//prove the inputs
		if (scanf("%d", &menu) != 1 || menu < 0 || menu > 9)
		{
			free(array);
			free(key_array);
			printf("Input error\n");
			return INPUT_ERROR;
		}
		//find student
		else if(menu == 0)
		{
			printf("enter the month :");
			if(scanf("%d",month)==1)
			{ 
				printf("enter the date that in this week :");
				if(scanf("%d",date)==1)
				{
					if(find_personbd(array,n,month,date))
					{
						printf("Nothing found\n");
						
					}
					else	
					{
						printf("Input error\n");
					}
				}
				else	
				{
						printf("Input error\n");
				}	
				
			}
			else
			{
                printf("Input error\n");	

			}
			
			
		}
		// print table
		else if(menu == 1)
		{
			printf("\n");
				print(array,n);
			
			
		}
		// add a person 
		else if(menu == 2)
		{
			
			status = add_stud(&array, &n);
			
			if (status == MEMORY_ALLOCATION_ERROR){
				printf("\nMemory allocation error\n");
				free(key_array);
				return status;
			}
			else if (status == INPUT_ERROR)
			{
				printf("\nInput error..!!\n");
			}
			else
			{   
			    printf("Record was added\n");
			} 
			t_time_bubble = 0;
			t_time_qsort = 0;
			k_time_bubble = 0;
			k_time_qsort = 0;
		}
		// delete a person
		else if(menu == 3)
		{
			int deleteperson;
			printf("to delete a person input last name:");
			scanf("%d",&deleteperson);
			status = delete_stud(&array,read_word(stdin),&n);
			if (status == MEMORY_ALLOCATION_ERROR){
				printf("Memory allocation error\n");
				free(key_array);
				return status;
			}
			else if (status == NOTHING_DELETED)
				printf("Nothing deleted\n");
			else
				printf("Done\n");
			
			t_time_bubble = 0;
			t_time_qsort = 0;
			k_time_bubble = 0;
			k_time_qsort = 0;
		}
		else if(menu == 4)
		{
			if(sort_table(array, n, &t_time_bubble, &t_time_qsort) == MEMORY_ALLOCATION_ERROR)
			{
				printf("Memory allocation error.!!\n");
				
			}
			else
			{
				printf("\n""Bubble sort: %d tacts\nQsort: %d tacts\n", t_time_bubble, t_time_qsort);
				
			}
			
		}
		else if(menu == 5)
		{
			sort_keyarray(array, n, &key_array, &k_time_bubble, &k_time_qsort);
			
			printf("Bubble sort: %d tacts\nQsort: %d tacts\n", k_time_bubble, k_time_qsort);
			
			for (int i = 0; i < n; i++)
			{
				printf("%2d) %-2d %s\n", i + 1, key_array[i],array[key_array[i]].last_Name);
			        
			}
			
		}
		else if (menu == 6)
		{
			if (!k_time_bubble)
				sort_keyarray(array, n, &key_array, &k_time_bubble,
			        &k_time_qsort);
	
			
			for (int i, j = 0; j < n; j++){
				i = key_array[j];
				
		        printf("%-16s %-20s %-14d %-14s %-24s %-6d %-4d %-2d \n", 
				array[i].last_Name, array[i].first_Name, array[i].telephone_no,
				array[i].address,array[i].position,array[i].date,array[i].month,array[i].year);
		
		    }
			
		}
		else if(menu == 7)
		{
			
			if (!k_time_bubble)
				sort_keyarray(array, n, &key_array, &k_time_bubble,
			        &k_time_qsort);
			
			if (!t_time_bubble) sort_table(array, n, &t_time_bubble, &t_time_qsort);				
			
            printf("\nEfficiency\n\nTime:\n              Table   Key-array\n"
			"Bubble sort:  100%%    %f%%\nQuick sort:   100%%    %f%%",
			(float)k_time_bubble / t_time_bubble * 100, (float)k_time_qsort
			/ t_time_qsort * 100);
			
			printf("\nMemory:\n              Table   Key-array\n"
			"              100%%    %f%%",
			(float)sizeof(key_array[0]) / sizeof(array[0]) * 100 + 100);
			
			
			
		}
		else if(menu == 8)
		{
			write_file(argv[1],array,n);
			printf("\nsaved in file ..!!\n");
			
		}
		else if(menu == 9)
		{
			break;
		}
	}
	
	free(array);
	getch();
	return SUCCESS;
	
}