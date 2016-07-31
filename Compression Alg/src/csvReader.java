/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dct;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author dinan
 */
public class csvReader {

    BufferedReader reader = null;

    public void print (List<List<Double>> input)
    { 
        int i, j;
        for(i=0;i<input.size();i++)
        {
            for(j=0;j<input.get(i).size();j++)
            {
                System.out.print(input.get(i).get(j));
                System.out.print(" ");
            }
            System.out.println("\n");
        }
    }
    
    public List<List<Double>> read(String filename) {
        List<List<Double>> matrix = new ArrayList<List<Double>>();
        try {
            File file = new File(filename);
            reader = new BufferedReader(new FileReader(file));
            String line;
            int k=0,i;
            
            while((line=reader.readLine()) != null)
            {
                String parts[] = line.split(",");                
                matrix.add(new ArrayList<Double>());
                for(i=0;i<parts.length;i++)
                {
                    double value = Double.parseDouble(parts[i]);
                    matrix.get(k).add(value);
                }
                k++;
            }
            
        } catch (IOException e) {
        };
        return matrix;
    }
}
