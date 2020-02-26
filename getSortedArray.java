import java.util.Scanner;
import java.lang.Math;
import java.io.*; 
import java.util.*; 
import java.util.Arrays;
import java.util.Collections;



public class getSortedArray{

   public static int[] getSortedArray (int n) {

      ArrayList<Integer> list = new ArrayList<>(100);
      for (int i = 0; i <= 99; i++){
         list.add(i);
      }
      int[] a = new int[n];

      

      for (int i = 0; i < a.length; i++) {
        a[i]=i+1;
        
      }
      
      
      for(int j=0; j<a.length/2;j++)
      {
        int t = a[j];
        a[j] = a[a.length - j - 1];
        a[a.length - j - 1] = t;
        System.out.print(a[j]+" ");
      }
      
    System.out.println();
    return a;
   }

     public static void main(String []args){
        getSortedArray(19);
     }
}