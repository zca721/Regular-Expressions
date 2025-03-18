CC=gcc
CFLAGS=-pthread -I. -Wall


binaries=regex


all: $(binaries)


clean: $(RM) -f $(binaries) *.o
