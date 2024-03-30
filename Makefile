CC = gcc
CFLAGS  = -Wall -g
OBJ = shell.o main.o command.o signal_handle.o

all: shell

shell: $(OBJ)
	$(CC) $(CFLAGS) -o shell $(OBJ) 

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

clean: 
	rm *.o shell