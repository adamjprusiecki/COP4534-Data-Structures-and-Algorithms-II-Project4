CC = g++
DEBUG = -g
CFLAGS = $(DEBUG) -c -Wall -std=c++11
LDLIBS =

TARGET = run

SOURCES = \
SimulationChip.cpp \
SimulationReading.cpp \
Driver.cpp \
main.cpp 

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LDLIBS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ 

.PHONY : all $(TARGET)

clean: 
	rm -f $(OBJECTS)
	rm $../Outputs/*
	rm run

clobber: clean
	rm -f $(TARGET) 
