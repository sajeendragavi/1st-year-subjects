#ifndef _ALLSTRUCTS_H
#define _ALLSTRUCTS_H

#pragma pack(push,1)

struct dateOfBirth 
{
	int date;
	int  month;
	int year;
	
}; 


struct stud
{
	char *last_Name;
	char *first_Name;
	int telephone_no;
	char *address;
	char *position;	
	
	union
	{
		struct  dateOfBirth;
		
	};
	
};

#pragma pack(pop)
#endif