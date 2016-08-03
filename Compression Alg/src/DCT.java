/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dct;

import static java.lang.Math.*;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author dinan
 */
public class DCT {
    List<List<Double>> inmatrix = new ArrayList<List<Double>>();
    List<List<Double>> outmatrix = new ArrayList<List<Double>>();    
//double in[][], out[][];
    //Matrix dimensions
    int N, M;
    //coefecients
    double coefU, coefV;
    //iterators
    int x, y, u, v;

    public DCT(List<List<Double>> inmatrix) {
        this.inmatrix = inmatrix;
        N = inmatrix.size();
        M = inmatrix.get(0).size();
        
    }

    public List<List<Double>> computeDCT() {
        for (u = 0; u < N; u++) {
            outmatrix.add(new ArrayList<Double>());
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
                        sum += (inmatrix.get(x).get(y)
                                * cos((PI * u * (2 * x + 1)) / (2.0 * N))
                                * cos((PI * v * (2 * y + 1)) / (2.0 * M)));

                    }
                }
                outmatrix.get(u).add((double)round(coefU * coefV * sum)) ;
            }
        }
        return outmatrix;
    }

    public void printDCT() {
        for (int i = 0; i < outmatrix.size(); i++) {
            for (int j = 0; j < outmatrix.get(0).size(); j++) {
                System.out.print(outmatrix.get(i).get(j));
                System.out.print(" ");
            }
            System.out.println("\n");

        }
    }
    
}
