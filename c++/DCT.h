#include <iostream>
#include <vector>
#define M_PI 3.14159265358979323846
#include <cmath>
#include<complex>
using namespace std;


void computeDCT(vector<double> &in, vector<double> &out)
{

    int N = in.size();
    double c = sqrt(1/(double)N);
    double sum = 0.0;
    for(int u=0;u<N;u++)
    {
        sum = 0.0;
        for (int x=0; x<N; x++)
        {
            double angle = (M_PI*(2*(double)x+1)*(double)u)/(2*(double)N);
            float cs = cos(angle);
            sum += in[x]*cs;
        }
        out.push_back(c*sum);
        c= sqrt(2/(double)N);
    }
}

void printDCT(vector<double> &in)
{
    for(int i=0;i<in.size();i++)
    {
        cout << in[i] << "   " ;
    }
}
