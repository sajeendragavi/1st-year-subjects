#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct dateOfBirth 
{
	int date;
	int  month;
	int year;
	
}; 
struct status 
{
	char position[10];
	struct dateOfBirth *dob;
		
};

struct stud
{
	int index;
	char lastName[10];
	char firstName[10];
	char telephone[10];
	char address[30];
	struct status *sts;
};

int  main ()
{
	struct stud *ptr;
	int i,n;	
	printf("Enter the number of student : ");
	scanf("%d",&n);
	
	ptr = (struct stud*)malloc(n*sizeof(struct stud));
	for(i = 0 ; i < n; i++)
	{
		printf("\nEnter the Index: ");
		scanf("%d",&(ptr+i)->index);
		printf("\nEnter the the last name :");
		scanf("%s",&(ptr+i)->lastName);
		printf("\nEnter the first name :");
		scanf("%s",&(ptr+i)->firstName);
		printf("\nEnter telephone number :");
		scanf("%s",&(ptr+i)->telephone);
		printf("\nEnter the address :");
		scanf("%s",&(ptr+i)->address);
		printf("\nEnter the status :");
		printf("\nEnter the status-position :");
		scanf("%s",&(ptr+i)->sts);
		printf("\nEnter the status-Date of Birth :");
		scanf("%d",&((ptr+i).sts)->dob);
	}
	printf("\nIndex\t last name \t\t first name\t\t telephone\t\t address\t\t Status-Position\t\t DOB\n\n");
	for(i = 0;i < n;i++)
	{
		printf("%2d %10s %25s %25s %20s %22s %24s\n",(ptr+i)->index,(ptr+i)->lastName,(ptr+i)->firstName,(ptr+i)->telephone,(ptr+i)->address,(ptr+i)->sts,((ptr+i).sts)->dob);
		
	}
	
	
	getch();
	return 0;
}