#include <iostream>
#include <vector>
#define M_PI 3.14159265358979323846
#include <cmath>
#include<complex>
using namespace std;

void computeDFT (vector<double> &in, vector<double> &outReal, vector<double> &outImag)
{
    int n = in.size();
    double sumreal, sumimag;
    double angle;
    for(int i=0; i<n; i++)
    {
        sumreal = 0;
        sumimag = 0;
        for (int k=0;k<n;k++)
        {
            angle = (2* M_PI *k*i)/n;
            sumreal += in[k]*cos(angle);
            sumimag += -in[k]*sin(angle);
        }
        outReal[i] = sumreal;
        outImag[i] = sumimag;
    }
}

void printDFT(vector<double> &inReal, vector<double> &inImag)
{
    for(int i=0;i<inReal.capacity();i++)
    {
        cout << inReal[i];
        cout << " ";
        if (inImag[i] >= 0)
            cout << "+";
        else
            cout << "-";
        cout << " ";
        cout << abs(inImag[i]) << "i" <<endl;
    }
}
