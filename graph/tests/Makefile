CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LFLAGS=-lcppunit
EXECUTABLE=test
OBJ_DIR = obj
SRC_DIR = src
BIN_DIR = bin
INC_DIR = include
SOURCES = ../Graph.cpp ../Node.cpp ../Search.cpp $(SRC_DIR)/*.cpp
OBJECTS = $(OBJ_DIR)/graphtest.o $(OBJ_DIR)/nodetest.o $(OBJ_DIR)/main.o $(OBJ_DIR)/Graph.o $(OBJ_DIR)/Node.o $(OBJ_DIR)/Search.o

run: executable
	bin/test

executable:$(OBJECTS)
	$(CC) -o $(BIN_DIR)/$(EXECUTABLE) -I$(INC_DIR) $(OBJECTS) -I.. $(LFLAGS)

all: clean executable

OBJECTS: $(OBJ_DIR)/graphtest.o $(OBJ_DIR)/nodetest.o $(OBJ_DIR)/main.o $(OBJ_DIR)/Graph.o $(OBJ_DIR)/Node.o $(OBJ_DIR)/Search.o

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(OBJ_DIR)/graphtest.o $(OBJ_DIR)/nodetest.o
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -I.. $(LFLAGS) -o $@ $<

$(OBJ_DIR)/nodetest.o: $(SRC_DIR)/nodetests.cpp $(INC_DIR)/nodetests.hpp $(OBJ_DIR)/Node.o
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -I.. $(LFLAGS) -o $@ $<

$(OBJ_DIR)/graphtest.o: $(SRC_DIR)/graphtests.cpp $(INC_DIR)/graphtests.hpp $(OBJ_DIR)/Graph.o $(OBJ_DIR)/Node.o
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -I.. $(LFLAGS) -o $@ $<

$(OBJ_DIR)/Graph.o: ../Graph.cpp ../Graph.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -I.. $(LFLAGS) -o $@ $<

$(OBJ_DIR)/Node.o: ../Node.cpp ../Node.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -I.. $(LFLAGS) -o $@ $<

$(OBJ_DIR)/Search.o: ../Search.cpp ../Search.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -I.. $(LFLAGS) -o $@ $<

clean:
	rm -rf obj/* bin/*
