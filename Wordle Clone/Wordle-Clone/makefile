CC = g++
SRC = src/main.cpp
OUT = game.exe
INCLUDE = -I include
LIBS = -L lib -lraylib -lopengl32 -lgdi32 -lwinmm

build:
	$(CC) $(SRC) -o $(OUT) $(INCLUDE) $(LIBS)

run: build
	./game.exe