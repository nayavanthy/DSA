import java.util.*;

//largest contigous sum of a sub array

public class Main {
    private static int largest_contigous_sum(int[] a){
      int max_sum = a[0];
      int curr_sum = a[0];
      
      for(int i = 1; i < a.length; i++){
        curr_sum = Math.max(a[i], curr_sum + a[i]);
        max_sum = Math.max(curr_sum, max_sum);
        //System.out.println(i + ' ' + curr_sum + ' ' + max_sum);
      }
      
      return max_sum;
    }
  
    public static void main(String[] args) {
      int[] a = { 4, -6, 2, 3};
      
      int largest_sum;
      
      largest_sum = largest_contigous_sum(a);
      
      System.out.println(largest_sum);
  }
}