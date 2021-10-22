CC = gcc
CFLAGS = -Wall -ansi -pedantic -Werror
OBJ = tvGuide.o fileIO.o linkedList.o interface.o
EXEC = program

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

tvGuide.o : tvGuide.c fileIO.h linkedList.h interface.h
	$(CC) -c tvGuide.c $(CFLAGS)

interface.o : interface.c interface.h
	$(CC) -c interface.c $(CFLAGS) 

fileIO.o : fileIO.c fileIO.h linkedList.h data.h
	$(CC) -c fileIO.c $(CFLAGS)

linkedList.o : linkedList.c linkedList.h
	$(CC) -c linkedList.c $(CLFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
