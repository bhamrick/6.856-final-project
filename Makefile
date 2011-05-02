CC=g++
LD=g++

CCFLAGS=-O2 -I.
LDFLAGS=-O2

TARGETS=main
OBJECTS=shared.o

all: $(TARGETS)

main: $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS)

clean:
	rm -f $(TARGETS) $(OBJECTS)

%.o: %.cpp
	$(CC) -c $(CCFLAGS) $<
