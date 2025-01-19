#include <stdio.h>
/*
Given an m x n integer matrix matrix, if an element is 0, 
set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/

void print_matrix(int *matrix, int m, int n){
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      printf("%d ", matrix[i * n + j]);
    }
    printf("\n");
  }
}

int main()
{
  int m = 3, n = 4;
  int matrix[3][4] = {{0, 1, 1, 0}, {1, 4, 0, 1}, {1, 1, 1, 5}};
  
  print_matrix((int *) matrix, m, n);
  
  for(int i = 0; i < m; i++){
    for( int j = 0; j < n; j++){
      if(matrix[i][j] == 0){
        matrix[0][j] = 0;
        matrix[i][0] = 0;
      }
    }
  }
  
  printf("\n");
  print_matrix((int *)matrix, m, n);
  for(int i = 1; i < m; i++){
    if(matrix[i][0] == 0){
      for(int j = 0; j < n; j++){
        matrix[i][j] = 0;
      }
    }
  }
  
  for(int j = 1; j < n; j++){
    if(matrix[0][j] == 0){
      for(int i = 0; i < m; i++){
        matrix[i][j] = 0;
      }
    }
  }
  
  if(matrix[0][0] == 0){
    for(int i = 0; i < m; i++){
      matrix[i][0] = 0;
    }
    
    for(int j = 0; j < n; j++){
      matrix[0][j] = 0;
    }
  }
  
  printf("\n");
  print_matrix((int *)matrix, m, n);
}