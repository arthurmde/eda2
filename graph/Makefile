SOURCES=Node.cpp Graph.cpp
MAIN=main.cpp
HEADERS=*.hpp
INCLUDES=-I.
COMPILER=g++
FLAGS=-W -Wall -ansi -pedantic
OUTPUT=prog
TEST_DIR=tests

all: $(SOURCES) $(HEADERS)
	$(COMPILER) $(MAIN) $(SOURCES) -o $(OUTPUT) $(FLAGS) $(INCLUDES)

test:
	${MAKE} -C ${TEST_DIR}

clean:
	rm -rf $(OUTPUT) *.o

