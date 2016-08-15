flags = -std=c++11
post = -static-libstdc++ -o

all: DataLab

edit:

compile:

DataLab: main.o inputReader.o DFT.o DCT.o
	g++ $(flags) main.cpp inputReader.h DFT.h DCT.h $(post) DataLab

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