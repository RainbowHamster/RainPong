CC=gcc
CFLAGS=-g
LDFLAGS=-lSDL2 -lSDL2_mixer


%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

pong: main.o game.o config.o behaviors.o evhandler.o
	$(CC) -o pong game.c main.c config.c behaviors.c evhandler.c $(LDFLAGS) -g

clean:
	rm *.o
