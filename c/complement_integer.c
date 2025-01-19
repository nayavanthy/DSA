#include <stdio.h>
#include <math.h>
/*
The complement of an integer is the integer you get when you
flip all the 0's to 1's and all the 1's to 0's in its binary 
representation.

For example, The integer 5 is "101" in binary and its complement 
is "010" which is the integer 2.
Given an integer n, return its complement.
*/
int find_complement(int num){
  int i = 0, complement = 0;
  
  while(num > 0){
    int lsb = num % 2;
    
    if(lsb == 0)
      complement += pow(2, i);
      
    num = num / 2;
    i++;
  }
  
  return complement;
}

int main()
{
  int n = 5;
  int result;
  
  result = find_complement(n);
  
  printf("%d", result);
}