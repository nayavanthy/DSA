import java.util.*;

/*
You are given an n * m grid where each position can contain one of the three values:
Cell Value Represents
0 Empty Cell
1 Fresh Apple
2 Rotten Apple
Every day, all fresh apples which are adjacent to any rotten apple become rotten.
Two cells are adjacent if they have a common edge, i.e., each cell can have upto four adjacent
cells.
*/

public class Main {
  public static int[][] increment_day(int[][] in_matrix){
    int[][] out_matrix = new int[in_matrix.length][in_matrix[0].length];
    for (int i = 0; i < in_matrix.length; i++) {
      for (int j = 0; j < in_matrix[i].length; j++) {
        if(in_matrix[i][j] == 2){
          if(i-1 > 0){
            if(in_matrix[i-1][j] == 1){
              out_matrix[i-1][j] = 2;
            }
          }
          if(j-1 > 0){
            if(in_matrix[i][j-1] == 1){
              out_matrix[i][j-1] = 2;
            }
          }
          if(i+1 < in_matrix.length){
            if(in_matrix[i+1][j] == 1){
              out_matrix[i+1][j] = 2;
            }
          }
          if(j+1 < in_matrix[i].length){
            if(in_matrix[i][j+1] == 1){
              out_matrix[i][j+1] = 2;
            }
          }
          
          out_matrix[i][j] = 2;
        }
        
        if(in_matrix[i][j] == 1 && out_matrix[i][j] != 2){
          out_matrix[i][j] = 1;
        }
        
        if(in_matrix[i][j] == 0){
          out_matrix[i][j] = 0;
        }
      }
    }
    
    return out_matrix;
  }
  
  public static int num_fresh_days(int[][] in_matrix){
    int[][] curr = in_matrix;
    int day = 1;
    
    while(true){
      
      int[][] next = increment_day(curr);
      boolean no_fresh = true;
      boolean no_change = true;
      
      for (int i = 0; i < in_matrix.length; i++){
        for (int j = 0; j < in_matrix[i].length; j++){
          if(next[i][j] != curr[i][j]){
            no_change = false;
          }
          if(next[i][j] == 1){
            no_fresh = false;
          }
        }
      }
      
      if(no_fresh){
        return day;
      }
      if(no_change){
        return -1;
      }
      
      curr = next;
      day++;
    }
    
  }
  
    public static void main(String[] args) {
      int[][] matrix = {
        {2, 1, 0},
        {1, 1, 0},
        {0, 1, 1}
      };
      
      int days = num_fresh_days(matrix);
      
      System.out.println(days);
  }
}