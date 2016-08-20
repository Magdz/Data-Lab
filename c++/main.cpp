#include <iostream>
#include <string.h>
#include <map>
#include "DFT.h"
#include "DCT.h"
#include "inputReader.h"

using namespace std;

enum funct_value{
    dft, dct, print,
};

static std::map<std::string, funct_value> map_value;

static void Initialize();

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

    // First Step: Check the Existence of the file sent throw argv[1]

    std::vector<vector<double>> inputMatrix;

    try{
        inputMatrix = readInput(argv[1]);
    }catch(exception e){
        printf("The file you are trying to read does not exists");
        return 0;
    }

    std::vector<double> outReal;
    std::vector<double> outImag;

    // Second Step: Map the chosen compression function sent throw argv[2] with the enum

    Initialize();

    // Third Step: Scan the column number sent throw argv[3] which the compression will be applied on

    int column;
    sscanf(argv[3], "%i", &column);

    // Run the Process

    switch(map_value[argv[2]]){
        case dft:
            cout << "DFT: " << endl;
            computeDFT(inputMatrix[column], outReal, outImag);
            printDFT(outReal,outImag);
            break;
        case dct:
            cout << "DCT: " <<endl;
            computeDCT(inputMatrix[column], outReal);
            printDCT(outReal);
            break;
        case print:
            cout << "Printing Matrix: " <<endl;
            printMat1D(inputMatrix[column]);
            break;
        default:
            printf("Compression function is not correct");
            break;
    }

    return 0;
}

void Initialize(){
    map_value["dft"] = dft;
    map_value["dct"] = dct;
    map_value["print"] = print;
}
