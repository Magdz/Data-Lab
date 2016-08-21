#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

vector<vector<long double>> readInput(string filename)
{
    string filessss = filename;
    string line;
    fstream infile(filename);
    int rows = 1;
    int cols = 0;

    getline(infile,line);
    stringstream ss(line);
    string cell;

    //Get row and column count
    while(getline(ss,cell,','))
        cols++;
    while(getline(infile, line))
        rows++;
    infile.close();

    vector<vector<long double>> matrix(cols,vector<long double>(rows));

    infile.open(filename);
    for(int i=0;i<rows;i++)
    {
        getline(infile,line);
        stringstream ss (line);
        for(int j=0;j<cols && getline(ss,cell,',');j++)
        {
            long double vect = atof(cell.c_str());
            matrix[j][i] = vect;
        }
    }
    infile.close();
    return matrix;
}


vector<vector<long double>> transMatrix(vector<vector<long double>> &in)
{
    int unsigned row = in.size();
    int unsigned col = in[0].size();
    vector<vector<long double>> out(col,vector<long double>(row));

    for(size_t unsigned i=0;i<row;++i)
    {
        for(size_t unsigned j=0;j<col;++j)
        {
            out[j][i] = in [i][j];
        }
    }
    return out;

}


void printMat(vector<vector<long double>>matrix)
{
    cout << endl;
    for(int unsigned i=0;i<matrix.size();i++)
    {
        for(int unsigned j=0;j<matrix[0].size();j++)
        {
            cout << matrix[i][j] << "   ";

        }
        cout << endl;
    }
}

void printMat1D(vector<long double>matrix)
{
    cout << endl;

    for(int unsigned j=0;j<matrix.size();j++)
    {
        cout << matrix[j];
        cout << "   ";

    }

}
