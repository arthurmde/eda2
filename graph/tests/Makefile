CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LFLAGS=-lcppunit
EXECUTABLE=test
OBJ_DIR = obj
SRC_DIR = src
BIN_DIR = bin
INC_DIR = include
SOURCES = ../Graph.cpp ../Node.cpp $(SRC_DIR)/*.cpp
OBJECTS = $(OBJ_DIR)/graphtest.o $(OBJ_DIR)/main.o $(OBJ_DIR)/Graph.o $(OBJ_DIR)/Node.o


executable:$(OBJECTS)
	$(CC) -o $(BIN_DIR)/$(EXECUTABLE) -I$(INC_DIR) $(OBJECTS) -I.. $(LFLAGS)

all: clean executable

OBJECTS: $(OBJ_DIR)/graphtest.o $(OBJ_DIR)/main.o $(OBJ_DIR)/Graph.o $(OBJ_DIR)/Node.o

$(OBJ_DIR)/graphtest.o: $(SRC_DIR)/graphtests.cpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -I.. $(LFLAGS) -o $@ $<

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -I.. $(LFLAGS) -o $@ $<

$(OBJ_DIR)/Graph.o: ../Graph.cpp ../Graph.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -I.. $(LFLAGS) -o $@ $<

$(OBJ_DIR)/Node.o: ../Node.cpp ../Node.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -I.. $(LFLAGS) -o $@ $<

clean:
	rm -rf obj/* bin/*
