SOURCES=Node.cpp Graph.cpp
MAIN=main.cpp
HEADERS=*.hpp
INCLUDES=-I.
COMPILER=g++
FLAGS=-W -Wall -ansi -pedantic
OUTPUT=prog

all: $(SOURCES) $(HEADERS)
	$(COMPILER) $(MAIN) $(SOURCES) -o $(OUTPUT) $(FLAGS) $(INCLUDES)
clean:
	rm -rf $(OUTPUT) *.o
