#include <vector>
#define M_PI 3.14159265358979323846
#include <cmath>
#include<complex>
using namespace std;

void computeDFT (vector<complex<double>> &in, vector<complex<double>> &out)
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
            sumreal += real(in[k])*cos(angle) + imag(in[k])*sin(angle);
            sumimag += -real(in[k])*sin(angle) + imag(in[k])*cos(angle);
        }
        out[i].real(sumreal);
        out[i].imag(sumimag);
    }
}

void printDFT(vector<complex<double>> &in)
{
    for(int i=0;i<in.capacity();i++)
    {
        cout << real(in[i]);
        cout << " ";
        if (imag(in[i]) >= 0)
            cout << "+";
        else
            cout << "-";
        cout << " ";
        cout << abs(imag(in[i])) << "i" <<endl;
    }
}
