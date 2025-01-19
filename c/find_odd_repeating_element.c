#include <stdio.h>
/*
Given an array arr[] of positive integers where every element appears 
even times except for one. Find that number occurring an odd number 
of times.

Examples:

Input: arr[] = [1, 1, 2, 2, 2]
Output: 2
Explanation: In the given array all element appear two times except 
2 which appears thrice.

*/

int main()
{
  int arr[] = {1, 1, 2, 2, 2};
  int size = sizeof(arr) / sizeof(arr[0]);
  
  int xor_sum = 0;
  for(int i = 0; i < size; i++){
    xor_sum = xor_sum ^ arr[i];
  }
  
  printf("%d", xor_sum);
}