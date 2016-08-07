#include <iostream>
#include "DFT.cpp"
#include "DCT.cpp"
#include "inputReader.cpp"
using namespace std;

int main()
{
    std::vector<complex<double>> matrix = {4.0,3.0,2.0};
    std::vector<complex<double>> out(matrix.capacity());
    std::vector<double> matrixDCT = {4.0,3.0,2.0};
    std::vector<double> outDCT(matrixDCT.capacity());
    computeDFT(matrix,out);
    cout << "DFT: " <<endl;
    printDFT(out);
    cout << "DCT: " <<endl;
    computeDCT(matrixDCT,outDCT);
    printDCT(outDCT);

    std::vector<vector<double>> inputMatrix;
    readInput("Sample.csv",inputMatrix);
    printMat(inputMatrix);

    std::vector<vector<double>> reversedMatrix;
    reversedMatrix = transMatrix(inputMatrix);
    printMat(reversedMatrix);

    return 0;
}
