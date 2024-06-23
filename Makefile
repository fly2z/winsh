.PHONY: build run

PROJECT_NAME = winsh
OUTPUT_DIR = build

INCLUDE_DIRS = 
LIB_DIRS = 

LIBS = 
SRC = $(wildcard src/*.c) $(wildcard src/core/*.c)

default: build run

build:
	gcc $(SRC) -o $(OUTPUT_DIR)/$(PROJECT_NAME) $(INCLUDE_DIRS) $(LIB_DIRS) $(LIBS)

run:
	.\$(OUTPUT_DIR)\${PROJECT_NAME}.exe