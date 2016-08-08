#include <iostream>
#include <string.h>
#include "DFT.cpp"
#include "DCT.cpp"
#include "inputReader.cpp"

using namespace std;

int main(int argc, char* argv[])
{
    //argv[0] filename used by system to compile
    //argv[1] the filename for the dataset to read
    //argv[2] the compression function to be used
    //argv[3] the index of the column to compress

    /*if( argc != 2 ){
        printf("usage: %s filename", argv[0]);
        return 0;
    }*/

    std::vector<vector<double>> inputMatrix;

    try{
        readInput(argv[1], inputMatrix);
    }catch(exception e){
        printf("The file you are trying to read does not exists");
        return 0;
    }

    std::vector<double> outputMatrix(inputMatrix.capacity());

    // strcmp returns 0 if the strings are equal
    if(!strcmp(argv[2], "dft")){
        cout << "DFT: " << endl;
        computeDFT(inputMatrix[0], outputMatrix);
        printDFT(outputMatrix);
    }else if(!strcmp(argv[2], "dct")){
        cout << "DCT: " <<endl;
        computeDCT(inputMatrix[0], outputMatrix);
        printDCT(outputMatrix);
    }else{
        printf("Compression function is not correct");
    }

    return 0;
}
