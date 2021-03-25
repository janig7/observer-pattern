CC = g++
CFLAGS = -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.cpp

all: 
	weatherstation

weatherstation: 
		$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./weatherstation

clean:
	rm weatherstation

