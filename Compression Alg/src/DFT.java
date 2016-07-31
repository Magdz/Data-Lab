/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dft;

/**
 *
 * @author dinan
 */
public class DFT {

    double inreal[][],outreal[][],outimag[][];
    public DFT(double inreal[][], double outreal[][],double outimag[][]){
        this.inreal = inreal;
        this.outreal = outreal;
        this.outimag = outimag;
    }
    
    public void computeDFT() 
    {    
        int n = inreal.length;
        int m = inreal[0].length;
        
        for (int k = 0; k < n; k++) {  // For each output element
            for(int p=0;p<m;p++)
            {
                double sumreal = 0;
            double sumimag = 0;
            for (int t = 0; t < n; t++) {  // For each input element
                for (int i = 0; i < m; i++) {
                    double angle = 2 * Math.PI * t * k / n;
                    sumreal += inreal[t][i] * Math.cos(angle);
                    sumimag += -inreal[t][i] * Math.sin(angle);
                }
            }
            outreal[k][p] = sumreal;
            outimag[k][p] = sumimag;
            }
        }        
    }
    
    public void printDFT()
    {
        for (int i = 0; i < outreal.length; i++) {
            for (int j = 0; j < outreal[i].length; j++) {
                if (Math.round(outreal[i][j]) != 0) {
                    System.out.print(Math.round(outreal[i][j]));
                }
                if (Math.round(outimag[i][j]) != 0) {
                    if (Math.round(outimag[i][j]) > 0)
                        System.out.print("+");
                    System.out.print(Math.round(outimag[i][j]));
                    System.out.print("j");
                }
                System.out.print(" ");
            }
            System.out.println("\n");
        }
    }
    
    public double[][] getReal()
    {
        return outreal;
    }
    public double[][] getImag()
    {
        return outimag;
    }
    
}
