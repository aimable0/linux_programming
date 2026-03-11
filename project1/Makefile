CFLAGS = -Wall -Werror -Wextra -g
CC = gcc

file_sync: file_sync.o
		$(CC) $(CFLAGS) file_sync.o -o file_sync

file_sync.o: file_sync.c
		$(CC) $(CFLAGS) -c file_sync.c

clean:
	rm -rf file_sync.o file_sync
