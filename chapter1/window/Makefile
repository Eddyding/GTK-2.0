CC = gcc
all:
	$(CC) -o window window.c `pkg-config --cflags --libs gtk+-2.0`
.PNONY:clean
clean:
	rm window
