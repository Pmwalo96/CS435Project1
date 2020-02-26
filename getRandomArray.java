import java.util.Scanner;
import java.lang.Math;
import java.io.*; 
import java.util.*; 


public class getRandomArray{

   public static int[] getRandomArray (int n) {

      ArrayList<Integer> list = new ArrayList<>(100);
      for (int i = 0; i <= 99; i++){
         list.add(i);
      }
      int[] a = new int[n];

      for (int count = 0; count < n; count++) {
        a[count] = list.remove((int)(Math.random() * list.size()));  
      }

      for (int i = 0; i < a.length; i++) {
        System.out.print(a[i]+" ");
      }
    System.out.println();
    return a;
   }

     public static void main(String []args){
        getRandomArray(6);
     }
}