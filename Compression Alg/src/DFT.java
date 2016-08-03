/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dft;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author dinan
 */
public class DFT {

    List<List<Double>> inreal,outreal,outimag;
    public DFT(List<List<Double>> inreal, List<List<Double>> outreal,List<List<Double>> outimag){
        this.inreal = inreal;
        this.outreal = outreal;
        this.outimag = outimag;
    }
    
    public void computeDFT() 
    {    
        int n = inreal.size();
        int m = inreal.get(0).size();
        
        for (int k = 0; k < n; k++) {
            outreal.add(new ArrayList<Double>());
            outimag.add(new ArrayList<Double>());// For each output element
            for(int p=0;p<m;p++)
            {
                double sumreal = 0;
            double sumimag = 0;
            for (int t = 0; t < n; t++) {  // For each input element
                for (int i = 0; i < m; i++) {
                    double angle = 2 * Math.PI * t * k / n;
                    sumreal += inreal.get(t).get(i) * Math.cos(angle);
                    sumimag += -inreal.get(t).get(i) * Math.sin(angle);
                }
            }
            outreal.get(k).add(sumreal);
            outimag.get(k).add(sumimag);
            }
        }        
    }
    
    public void printDFT()
    {
        for (int i = 0; i < outreal.size(); i++) {
            for (int j = 0; j < outreal.get(i).size(); j++) {
                if (Math.round(outreal.get(i).get(j)) != 0) {
                    System.out.print(Math.round(outreal.get(i).get(j)));
                }
                if (Math.round(outimag.get(i).get(j)) != 0) {
                    if (Math.round(outimag.get(i).get(j)) > 0)
                        System.out.print("+");
                    System.out.print(Math.round(outimag.get(i).get(j)));
                    System.out.print("j");
                }
                System.out.print(" ");
            }
            System.out.println("\n");
        }
    }
    
    public List<List<Double>> getReal()
    {
        return outreal;
    }
    public List<List<Double>> getImag()
    {
        return outimag;
    }
    
}
