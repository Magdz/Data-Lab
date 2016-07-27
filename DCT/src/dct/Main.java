/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dct;

/**
 *
 * @author dinan
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        double in[][] =
        { {75,76,75,75,69,66,77,71},
          {73,74,73,74,63,64,68,69},
          {69,68,71,72,67,58,48,41},
          {59,55,56,52,47,40,24,9},
          {51,50,45,41,33,22,7,-5},
          {43,37,32,24,15,5,-6,-25},
          {29,21,9,-2,-10,-21,-44,-69},
          {9,-4,-17,-35,-52,-61,-57,-35}
        }, out[][];
        
        DCT compress = new DCT(in);
        
        out = compress.computeDCT();
        int i,j;
        for(i=0;i<out.length;i++)
        {
            for(j=0;j<out[i].length;j++)
            {
                System.out.print(out[i][j]);
                System.out.print(" ");
            }
            System.out.println("\n");
            
        }
    }
}