import java.util.*;

//Given a matrix, if any of the cells in the matrix is 0,
//set all the elements in its row and column to 0.

public class Main {
    public static void main(String[] args) {
      int[][] matrix = {{ 1, 1, 1}, {0, 0, 1}, {1, 1, 1}};
      int m = 3, n = 3;
      boolean first_col_zero = false;
      
      for(int i = 0; i < m; i++){
        if(matrix[i][0] == 0){
          first_col_zero = true;
        }
      }
      
      for(int i = 0; i<m; i++){
        for(int j = 1; j<m; j++){
          if(matrix[i][j] == 0){
            matrix[0][j] = 0;
            matrix[i][0] = 0;
          }
        }
      }
      
      for(int i = 1; i<m; i++){
        if(matrix[i][0] == 0){
          for(int j = 1; j < n; j++){
            matrix[i][j] = 0;
          }
        }
      }
      
      for(int j = 1; j<n; j++){
        if(matrix[0][j] == 0){
          for(int i = 1; i < m; i++){
            matrix[i][j] = 0;
          }
        }
      }
      
      if(matrix[0][0] == 0){
        for(int j = 0; j < n; j++){
          matrix[0][j] = 0;
        }
      }
      
      if(first_col_zero){
        for(int i = 0; i < m; i++){
          matrix[i][0] = 0;
        }
      }
      
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          System.out.print(matrix[i][j] + " ");
        }
        System.out.println();
      }
  }
}