#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

vector<vector<double>> readInput(string filename)
{

    string line;
    fstream infile(filename);
    int rows = 1;
    int cols = 0;
    int i;

    getline(infile,line);
    stringstream ss(line);
    string cell;

    //Get row and column count
    while(getline(ss,cell,','))
        cols++;
    while(getline(infile, line))
        rows++;
    infile.close();

    vector<vector<double>> matrix(cols,vector<double>(rows));

    infile.open(filename);
    for(int i=0;i<rows;i++)
    {
        getline(infile,line);
        stringstream ss (line);
        for(int j=0;j<cols && getline(ss,cell,',');j++)
        {
            double vect = atof(cell.c_str());
            matrix[j][i] = vect;
        }
    }
    infile.close();
    return matrix;
}


vector<vector<double>> transMatrix(vector<vector<double>> &in)
{
    int row = in.size();
    int col = in[0].size();
    vector<vector<double>> out(col,vector<double>(row));

    for(size_t i=0;i<row;++i)
    {
        for(size_t j=0;j<col;++j)
        {
            out[j][i] = in [i][j];
        }
    }
    return out;

}


void printMat(vector<vector<double>>matrix)
{
    cout << endl;
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            cout << matrix[i][j] << "   ";

        }
        cout << endl;
    }
}
void printMat1D (vector<double> matrix)
{
   cout << "Printing Row: ";
   cout <<endl;
   int i;
   for(i=0;i<matrix.size()-1;i++)
   {   
      cout << matrix[i] << endl;
   }
   cout << matrix[i];
   cout <<endl;
}
