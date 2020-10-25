CC?=gcc
CFLAGS?=-g
BINARIES=map limits

default:
	make map
	make limits

map:
	$(CC) $(CFLAGS) map.c recurse.c -o map

limits:
	$(CC) $(CFLAGS) limits.c -o limits

clean:
	rm -f $(BINARIES)
try:
	$(CC) -m32 -S -o map.S map.c
	$(CC) -m32 -S -o recurse.S recurse.c
	$(CC) -m32 -c map.S -o map.o
	$(CC) -m32 -c recurse.c -o recurse.o
	$(CC) -m32 map.o recurse.o -o map
