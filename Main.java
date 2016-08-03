/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author dinan
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        csvReader csv = new csvReader();
        Scanner input = new Scanner(System.in);
        
        String filename = input.nextLine();
        
        List<List<Double>> read = csv.read(filename);
        DCT compress = new DCT(read);
        compress.computeDCT();
        compress.printDCT();
    }
    
    public static void test(){
//        double dctIn[][] =
//        { {75,76,75,75,69,66,77,71},
//          {73,74,73,74,63,64,68,69},
//          {69,68,71,72,67,58,48,41},
//          {59,55,56,52,47,40,24,9},
//          {51,50,45,41,33,22,7,-5},
//          {43,37,32,24,15,5,-6,-25},
//          {29,21,9,-2,-10,-21,-44,-69},
//          {9,-4,-17,-35,-52,-61,-57,-35}
//        }, out[][];
//        
//        DCT compress = new DCT(dctIn);
//        out = compress.computeDCT();
//        
//        double dftIn[][] = {{2.0, 0},
//        {3.0, 0},
//        {-1.0, 0},
//        {1.0, 0},};
//        double outreal[][] = new double[dftIn.length][dftIn[0].length];
//        double outimag[][] = new double[dftIn.length][dftIn[0].length];
//
//        DFT compress2 = new DFT(dftIn, outreal, outimag);
//        compress2.computeDFT();
//        compress2.printDFT();
    }
}
