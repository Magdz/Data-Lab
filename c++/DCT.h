#include <iostream>
#include <vector>
#define M_PI 3.14159265358979323846
#include <cmath>
#include<complex>
using namespace std;

void computeDCT(vector<long double> &in, vector<long double> &out)
{
    int N = in.size();
    __float128 sum = 0.0;
    long double angle;
    long double c = sqrt(1.0/(long double)N);
    long double cs;
    for(int u=0; u<N; u++)
    {
        sum = 0.0;
        for (int x=0; x<N; x++)
        {
            angle = (M_PI*(2.0*(long double)x+1.0)*(long double)u)/(2.0*(long double)N);
            cs = cos((long double)angle);
            sum += in[x]*cs;
        }
        out.push_back(c*sum);
        c = sqrt(2.0/(long double)N);
    }
}

void computeIDCT(vector<long double> &in, vector<long double> &out)
{
    int N = in.size();
    __float128 sum;
    long double angle;
    long double cs;
    long double c;
    for(int u=0; u<N; u++)
    {
        sum = 0.0;
        c = sqrt(1/(long double)N);
        for (int x=0; x<N; x++)
        {
            angle = (M_PI*(2*(long double)u+1)*(long double)x)/(2*(long double)N);
            cs = cos((long double)angle);
            sum += c*in[x]*cs;
            c = sqrt(2.0/(long double)N);
        }
        out.push_back(sum);
    }

}

void getSubset (long double per, vector<long double> &in, vector<long double> &out)
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
void printDCT(vector<long double> &in)
{
    for(int unsigned i=0; i<in.size(); i++)
    {
        cout << in[i] << endl ;
    }
}
