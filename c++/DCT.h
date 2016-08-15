#include <iostream>
#include <vector>
#define M_PI 3.14159265358979323846
#include <cmath>
#include<complex>
using namespace std;

void computeDCT(vector<double> &in, vector<double> &out)
{
    int N = in.size();
    double sum = 0.0;
    double angle;
    double c = sqrt(1.0/(double)N);
    float cs;
    for(int u=0; u<N; u++)
    {
        sum = 0.0;
        for (int x=0; x<N; x++)
        {
            angle = (M_PI*(2.0*(double)x+1.0)*(double)u)/(2.0*(double)N);
            cs = cos(angle);
            sum += in[x]*cs;
        }
        out.push_back(c*sum);
        c = sqrt(2.0/(double)N);
    }
}

void computeIDCT(vector<double> &in, vector<double> &out)
{
    int N = in.size();
    long double sum;
    long double angle;
    long double cs;
    long double c;
    for(int u=0; u<N; u++)
    {
        sum = 0.0;
        c = sqrt(1/(double)N);
        for (int x=0; x<N; x++)
        {
            angle = (M_PI*(2*(double)u+1)*(double)x)/(2*(double)N);
            cs = cos(angle);
            sum += c*in[x]*cs;
            c = sqrt(2.0/(double)N);
        }
        out.push_back(sum);
    }

}

void getSubset (double per, vector<double> &in, vector<double> &out)
{
    int N = in.size()*per;
    for(int i=0; i<N; i++)
    {
        out.push_back(in[i]);
    }
    for(int i=0; i<(in.size()-N); i++)
    {
        out.push_back(0.0);
    }
}
void printDCT(vector<double> &in)
{
    for(int unsigned i=0; i<in.size(); i++)
    {
        cout << in[i] << endl;
    }
}
