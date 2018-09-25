SRC-DIR=src/
SRC-DIR-GAME=src/game_process/
SRC-DIR-OBJECTS=src/objects/
BIN-DIR=bin/
TEX-DIR=tex/

CXX=g++
CXXFLAGS=-std=c++11 -pedantic -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wundef -Werror -Wno-unused

TEX=pdflatex
TEXFLAGS=--interaction=batchmode -output-directory=$(BIN-DIR)
TEXDEBUGFLAGS=-output-directory=$(BIN-DIR)

cpp: $(SRC-DIR-GAME)Map.cpp $(SRC-DIR-GAME)Place.cpp $(SRC-DIR-GAME)Player.cpp $(SRC-DIR-OBJECTS)Building.cpp $(SRC-DIR-OBJECTS)DestroyingObject.cpp $(SRC-DIR-OBJECTS)MovingObject.cpp $(SRC-DIR-OBJECTS)ResouceObject.cpp $(SRC-DIR-OBJECTS)SimpleObject.cpp $(SRC-DIR-OBJECTS)Terrain.cpp $(SRC-DIR-OBJECTS)Unit.cpp $(SRC-DIR-OBJECTS)Weapon.cpp $(SRC-DIR)main.cpp 
	$(CXX) $(CXXFLAGS) $(SRC-DIR-GAME)Map.cpp Place.cpp Player.cpp $(SRC-DIR-OBJECTS)Building.cpp DestroyingObject.cpp MovingObject.cpp ResouceObject.cpp SimpleObject.cpp Terrain.cpp Unit.cpp Weapon.cpp $(SRC-DIR)main.cpp  -o $(BIN-DIR)main.out

cpp-clean: $(BIN-DIR)main.out
	rm -f $(BIN-DIR)main.out

latex:
	$(TEX) $(TEXFLAGS) $(TEX-DIR)report.tex
	$(TEX) $(TEXFLAGS) $(TEX-DIR)report.tex

latex-debug:
	$(TEX) $(TEXDEBUGFLAGS) $(TEX-DIR)report.tex
	$(TEX) $(TEXDEBUGFLAGS) $(TEX-DIR)report.tex

latex-clean: $(BIN-DIR)report.pdf
	rm -f $(BIN-DIR)report.pdf

all: cpp latex

clean: cpp-clean latex-clean
