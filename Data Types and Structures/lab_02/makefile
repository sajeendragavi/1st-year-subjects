CC := gcc
CFLAGS := -std=c99 -Wall -Werror -ggdb

main2.exe : main2.o file_handle.o functions.o func_sort.o
	$(CC) -o $@ $^
	
main2.o : main2.c allstructs.h file_handle.h functions.h func_sort.h
	$(CC) $(CFLAGS) -c $<
	
file_handle.o : file_handle.c file_handle.h allstructs.h functions.h
	$(CC) $(CFLAGS) -c $<
	
%.o : %.c %.h allstructs.h
	$(CC) $(CFLAGS) -c $<
	
clean :
	$(RM) *.o *.exe
