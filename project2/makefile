CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

program: program.o
	$(CC) $(CFLAGS) program.o -o program

program.o: program.c
	$(CC) $(CFLAGS) program.c -c

clean:
	rm -rf program.o program app.log
