flags = -std=c++11
post = -static-stdlibc++ -o

all: DataLab

edit:

compile:

DataLab: main.o inputReader.o DFT.o DCT.o
	g++ main.o inputReader.o DFT.o DCT.o $(post) DataLab

main.o: main.cpp
	g++ $(flags) main.cpp

inputReader.o: inputReader.h
	g++ $(flags) inputReader.h

DFT.o: DFT.h
	g++ $(flags) DFT.h

DCT.o: DCT.h
	g++ $(flags) DCT.h

clean:
	rm -rf *o DataLab