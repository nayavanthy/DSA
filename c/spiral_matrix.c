#include <stdio.h>
/*
Given a matrix mat[][] of size m x n, the task is to print all
elements of the matrix in spiral form.

Examples: 

Input: mat[][] = [[1,    2,   3,   4],
                  [5,    6,   7,   8],
                  [9,   10,  11,  12],
                  [13,  14,  15,  16]]
Output: [ 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10 ]
*/

int main()
{
  int matrix[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  int m = 4;
  int n = 4;
  
  int top = 0, right = n - 1, bottom = m - 1, left = 0;
  
  while(top<=bottom && left<=right){
    
    //print top row form left to right
    for(int i = left; i <= right; i++){
      printf("%d ", matrix[top][i]);
    }
    top++;
    
    //print right column from top to bottom
    for(int i = top; i <= bottom; i++){
      printf("%d ", matrix[i][right]);
    }
    right--;
    
    if(top <= bottom){
      //print bottom row from right to left
      for(int i = right; i >= left; i--){
        printf("%d ", matrix[bottom][i]);
      }
      bottom--;
    }
    
    if(left<=right){
      //print left column from bottom to top
      for(int i = bottom; i >= top; i--){
        printf("%d ", matrix[i][left]);
      }
      left++;
    }
  }
}