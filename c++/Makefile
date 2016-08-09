flags = -std=c++11

all: DataLab

edit:

compile:

DataLab: main.o inputReader.o DFT.o DCT.o
	g++ main.o inputReader.o DFT.o DCT.o -o DataLab

main.o: main.cpp
	g++ $(flags) main.cpp

inputReader.o: inputReader.cpp
	g++ $(flags) inputReader.cpp

DFT.o: DFT.cpp
	g++ $(flags) DFT.cpp

DCT.o: DCT.cpp
	g++ $(flags) DCT.cpp

clean:
	rm -rf *o DataLab