CXX = g++

CXX_FLAGS 	= -std=c++11
OBJECTS		= main.o component.o
INCLUDE 	= -Iinclude/

all: build trash

build: $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(INCLUDE) -o main

main.o: main.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDE) -c main.cpp

component.o: component.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDE) -c component.cpp

trash:
	rm -rf *.o

clean:
	rm -rf *.o main.exe
