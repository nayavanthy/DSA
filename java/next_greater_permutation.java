import java.util.*;

/*
Given an array, rearrange it to its next greater permutation. Do it in-place with extra constant
memory only

Array: [1, 2, 3, 4]
Next Greater Permutation: [1, 2, 4, 3]

*/


public class Main {
    
    public static int[] get_next_greater_permutation(int[] in_arr) {
      int n = in_arr.length;
      int i = n - 2;
      
      while (i >= 0 && in_arr[i] >= in_arr[i + 1]) {
        i--;
      }
      
      if (i >= 0) {
        int j = n - 1;
        
        while (in_arr[j] <= in_arr[i]) {
          j--;
        }
        
        int temp = in_arr[i];
        in_arr[i] = in_arr[j];
        in_arr[j] = temp;
      }
      
      int left = i + 1, right = n - 1;
      while (left < right) {
        int temp = in_arr[left];
        in_arr[left] = in_arr[right];
        in_arr[right] = temp;
        left++;
        right--;
      }
      
      return in_arr;
    }
    
    public static void main(String[] args) {
      int[] array = { 1, 2, 3, 4};
      
      int count = 0;
      
      while(count<25){
        array = get_next_greater_permutation(array);
        
        for(int i : array){
          System.out.print(i + " ");
        }
        
        System.out.println();
        
        count++;
      }
  }
}