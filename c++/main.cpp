#include <iostream>
#include <string.h>
#include <map>
#include "DFT.h"
#include "DCT.h"
#include "inputReader.h"

using namespace std;

enum funct_value{
    error ,dft, dct, processDCT, print,
};

static std::map<std::string, funct_value> map_value;
static std::vector<vector<long double>> inputMatrix;

static void Initialize();

static void RunDFT(int column);
static vector<long double> RunDCT(int column, bool print);
static void ProcessDCT(int column, long double percentage);

int main(int argc, char* argv[])
{
    //argv[0] filename used by system to compile
    //argv[1] the filename for the dataset to read
    //argv[2] the compression function to be used
    //argv[3] the index of the column to compress
    //argv[4] the percentage of the subset

    /*if( argc != 2 ){
        printf("usage: %s filename", argv[0]);
        return 0;
    }*/

    // First Step: Check the Existence of the file sent throw argv[1]

    try{
        inputMatrix = readInput(argv[1]);
    }catch(exception e){
        printf("The file you are trying to read does not exists");
        return 0;
    }



    // Second Step: Map the chosen compression function sent throw argv[2] with the enum

    Initialize();
    funct_value the_funct_value;
    try{
        the_funct_value = map_value[argv[2]];
    }catch(exception e){
        printf("Compression function is not defined");
        return 0;
    }

    // Third Step: Scan the column number sent throw argv[3] which the compression will be applied on

    int column;
    try{
        column = atoi(argv[3]);
        // No Error Exception in thrown in case of missing input error the default is 0
    }catch(exception e){
        printf("Error getting the column number to run the compression on");
        return 0;
    }

    // Fourth Step: Make sure that the sent percentage throw argv[4] is between 0 and 1

    long double percentage = atof(argv[4]);
    if(!(percentage >= 0 && percentage <= 1)){
        printf("Percentage error: the percentage must be between 0 and 1");
        return 0;
    }


    // Run the Process

    switch(the_funct_value){
        case dft:
            RunDFT(column);
            break;
        case dct:
            RunDCT(column, true);
            break;
        case processDCT:
            ProcessDCT(column, percentage);
            break;
        case print:
            cout << "Printing Matrix: " <<endl;
            printMat1D(inputMatrix[column]);
            break;
        default:
            printf("Compression function is not correct");
            break;
    }
    printf("Successfully computed\n");

    return 0;
}

void Initialize(){
    map_value["dft"] = dft;
    map_value["dct"] = dct;
    map_value["processDCT"] = processDCT;
    map_value["print"] = print;
}

void RunDFT(int column){
    std::vector<double> outReal;
    std::vector<double> outImag;
    cout << "DFT: " << endl;
    computeDFT(inputMatrix[column], outReal, outImag);
    printDFT(outReal,outImag);
}

vector<long double> RunDCT(int column, bool print){
    std::vector<long double> outReal;
    computeDCT(inputMatrix[column], outReal);
    if(print){
        cout << "DCT: " <<endl;
        printDCT(outReal);
    }
    return outReal;
}

void ProcessDCT(int column, long double percentage){
    vector<long double> outDCT = RunDCT(column, false);
    vector<long double> Subset;
    vector<long double> outIDCT;
    getSubset(percentage, outDCT, Subset);
    computeIDCT(Subset, outIDCT, percentage);
    printDCT(outIDCT);
}
