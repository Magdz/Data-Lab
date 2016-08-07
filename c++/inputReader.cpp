#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

void readInput(string filename, vector<vector<double>> &matrix)
{
    string line;
    fstream infile(filename);
    int rows = 1;
    int cols = 0;
    int i;

    getline(infile,line);
    stringstream ss(line);
    string cell;

    while(getline(ss,cell,','))
        cols++;

    while(getline(infile, line))
        rows++;

    infile.close();

    matrix.resize(rows);
    for(int k=0;k<rows;k++)
        matrix[k].resize(cols);

    infile.open(filename);
    for(int i=0;i<rows;i++)
    {
        getline(infile,line);
        stringstream ss (line);
        for(int j=0;j<cols && getline(ss,cell,',');j++)
        {
            double vect = atof(cell.c_str());
            matrix[i][j] = vect;
        }
    }
    infile.close();
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
