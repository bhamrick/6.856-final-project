CC=g++
LD=g++

CCFLAGS=-O2 -I. 
LDFLAGS=-O2 

TARGETS=ballwalk ballwalk_adaptive hitandrun
SHARED_OBJECTS=shared.o main.o
BALLWALK_OBJECTS=ballwalk.o
BALLWALK_ADAPTIVE_OBJECTS=ballwalk_adaptive.o
HITANDRUN_OBJECTS=hitandrun.o

all: $(TARGETS)

ballwalk: $(SHARED_OBJECTS) $(BALLWALK_OBJECTS)
	$(LD) -o ballwalk $(LDFLAGS) $(SHARED_OBJECTS) $(BALLWALK_OBJECTS)

ballwalk_adaptive: $(SHARED_OBJECTS) $(BALLWALK_ADAPTIVE_OBJECTS)
	$(LD) -o ballwalk_adaptive $(LDFLAGS) $(SHARED_OBJECTS) $(BALLWALK_ADAPTIVE_OBJECTS)

hitandrun: $(SHARED_OBJECTS) $(HITANDRUN_OBJECTS)
	$(LD) -o hitandrun $(LDFLAGS) $(SHARED_OBJECTS) $(HITANDRUN_OBJECTS)

clean:
	rm -f $(TARGETS) $(SHARED_OBJECTS) $(BALLWALK_OBJECTS) $(HITANDRUN_OBJECTS)

%.o: %.cpp
	$(CC) -c $(CCFLAGS) $<
