CC=gcc
LIBS=\
	`pkg-config --cflags --libs gtk+-3.0`
all:
	$(CC) -o server server.c $(LIBS)
	$(CC) -o client client.c $(LIBS)
