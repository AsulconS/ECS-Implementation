CXX = g++

CXX_FLAGS 	= -std=c++11
OBJECTS		= main.o componentManager.o
INCLUDE 	= -Iinclude/

all: build trash

build: $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(INCLUDE) -o main

main.o: main.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDE) -c main.cpp

componentManager.o: componentManager.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDE) -c componentManager.cpp

trash:
	rm -rf *.o

clean:
	rm -rf *.o main.exe
