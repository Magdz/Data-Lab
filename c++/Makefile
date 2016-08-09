all: DataLab

edit:

compile:

DataLab: main.o inputReader.o DFT.o DCT.o
	g++ main.o inputReader.o DFT.o DCT.o -o DataLab

main.o: main.cpp
	g++ -c main.cpp

inputReader.o: inputReader.cpp
	g++ -c inputReader.cpp

DFT.o: DFT.cpp
	g++ -c DFT.cpp

DCT.o: DCT.cpp
	g++ -c DCT.cpp

clean:
	rm -rf *o DataLab