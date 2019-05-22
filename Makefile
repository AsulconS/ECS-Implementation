CXX = g++

CXX_FLAGS 	= -std=c++11
INCLUDE 	= -Iinclude/

C_OS	:=
OBJECTS :=
ifeq ($(OS),Windows_NT)
	C_OS	+= Windows
	OBJECTS += main.o componentManager.o
else
	C_OS	+= Linux
	OBJECTS += componentManager.o main.o
endif

all: os build trash

os:
	@echo $(C_OS)

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
