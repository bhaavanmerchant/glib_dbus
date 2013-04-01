CC=gcc
INCLUDE=\
	`pkg-config --cflags dbus-glib-1` \
	`pkg-config --cflags dbus-1` \
	`pkg-config --cflags glib-2.0`
LIBS=\
	`pkg-config --libs dbus-glib-1` \
	`pkg-config --libs dbus-1` \
	`pkg-config --libs glib-2.0`
all:
	$(CC) -o receiverg $(INCLUDE) receiver.c $(LIBS)
	$(CC) -o sender $(INCLUDE) sender.c $(LIBS)
