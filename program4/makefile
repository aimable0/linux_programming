CC = gcc
CFLAGS = -Wextra -g

monitor_service: monitor_service.o
	$(CC) $(CFLAGS) monitor_service.o -o monitor_service

monitor_service.o: monitor_service.c
	$(CC) $(CFLAGS) monitor_service.c -c

clean:
	rm -rf monitor_service.o monitor_service

