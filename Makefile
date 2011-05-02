CC=g++
LD=g++

CCFLAGS=-O2 -I. -fopenmp
LDFLAGS=-O2 -fopenmp

TARGETS=ballwalk hitandrun
SHARED_OBJECTS=shared.o main.o
BALLWALK_OBJECTS=ballwalk.o
HITANDRUN_OBJECTS=hitandrun.o

all: $(TARGETS)

ballwalk: $(SHARED_OBJECTS) $(BALLWALK_OBJECTS)
	$(LD) -o ballwalk $(LDFLAGS) $(SHARED_OBJECTS) $(BALLWALK_OBJECTS)

hitandrun: $(SHARED_OBJECTS) $(HITANDRUN_OBJECTS)
	$(LD) -o hitandrun $(LDFLAGS) $(SHARED_OBJECTS) $(HITANDRUN_OBJECTS)

clean:
	rm -f $(TARGETS) $(SHARED_OBJECTS) $(BALLWALK_OBJECTS) $(HITANDRUN_OBJECTS)

%.o: %.cpp
	$(CC) -c $(CCFLAGS) $<
