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

    public DCT(double in[][]) {
        this.in = in;
        N = in.length;
        M = in[0].length;
        this.out = new double[N][M];
    }

    public double[][] computeDCT() {
        for (u = 0; u < N; u++) {
            for (v = 0; v < M; v++) {
                if (u == 0) {
                    coefU = sqrt(1 / (double) N);
                } else {
                    coefU = sqrt(2 / (double) N);
                }

                if (v == 0) {
                    coefV = sqrt(1 / (double) M);
                } else {
                    coefV = sqrt(2 / (double) M);
                }

                double sum = 0.0;

                for (x = 0; x < N; x++) {
                    for (y = 0; y < M; y++) {
                        sum += (in[x][y]
                                * cos((PI * u * (2 * x + 1)) / (2.0 * N))
                                * cos((PI * v * (2 * y + 1)) / (2.0 * M)));

                    }
                }

                out[u][v] = round(coefU * coefV * sum);

            }
        }
        return out;
    }

    public void printDCT() {
        for (int i = 0; i < out.length; i++) {
            for (int j = 0; j < out[i].length; j++) {
                System.out.print(out[i][j]);
                System.out.print(" ");
            }
            System.out.println("\n");

        }
    }
    
}
