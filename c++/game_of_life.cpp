#include <iostream>
using namespace std;


/*
ccording to Wikipedia's article: "The Game of Life, 
also known simply as Life, is a cellular automaton devised 
by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each 
cell has an initial state: live (represented by a 1) or dead 
(represented by a 0). Each cell interacts with its eight neighbors 
(horizontal, vertical, diagonal) using the following four rules
(taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as
  if caused by under-population.
Any live cell with two or three live neighbors lives on 
  to the next generation.
Any live cell with more than three live neighbors dies, as 
  if by over-population.
Any dead cell with exactly three live neighbors becomes a 
  live cell, as if by reproduction.
The next state of the board is determined by applying the 
above rules simultaneously to every cell in the current
state of the m x n grid board. In this process, births and 
deaths occur simultaneously.
*/

int count_neighbouring_live_cells(int matrix[][10], int n, int m, int x, int y){
  int count = 0;
  
  for(int i = x-1; i <= x+1; i++){
    if(i < 0 || i >= n){
      continue;
    }
    
    for(int j = y-1; j <= y+1; j++){
      if(j < 0 || j >= m){
        continue;
      }
      
      count += matrix[i][j];
    }
  }
  
  return count - matrix[x][y];
}

int main() 
{
  int n = 4, m = 3;
  int matrix[10][10] = {{ 0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
  int result[10][10];
  int num_steps = 10;
  
  while(num_steps > 0){
    int result[10][10];
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        int count = count_neighbouring_live_cells(matrix, n, m, i, j);
        
        if(matrix[i][j]==1){
          if(count < 2 || count > 3){
            result[i][j] = 0;
          } else {
            result[i][j] = 1;
          }
        } else {
          if(count == 3){
            result[i][j] = 1;
          } else {
            result[i][j] = 0;
          }
        }
        
      }
      
    }
    
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        printf("%d ", result[i][j]);
        matrix[i][j] = result[i][j];
      }
      printf("\n");
    }
    printf("\n");
    
    num_steps--;
  }
  
}