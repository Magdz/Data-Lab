/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dct;

import static java.lang.Math.*;

/**
 *
 * @author dinan
 */
public class DCT {

    double in[][], out[][];
    //Matrix dimensions
    int N, M;
    //coefecients
    double coefU, coefV;
    //iterators
    int x, y, u, v;    
    
    public DCT(double in[][])
    {
        this.in = in;
        N = in.length;
        M = in[0].length;
        this.out = new double[N][M];
    }

    public double[][] computeDCT ()
    {
        double s = 1/N;
        for (u=0;u<N;u++)
        {
            for(v=0;v<M;v++)
            {
                if(u == 0 && v==0)
                    coefU = sqrt(1/(double)N);
                else 
                    coefU = sqrt (2/(double)N); 
                coefV = coefU;
                
                for(x=0;x<N;x++)
                {
                    for(y=0;y<M;y++)
                    {
                        out[u][v] += (int)round(coefU*coefV*(in[x][y] *
                                cos((PI*u*((2*x)+1))/(2*(double)N))*
                                cos((PI*v*((2*y)+1))/(2*(double)N))));
                    }
                }
                
            }
        }
        return out;
    }
}
