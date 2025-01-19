#include <stdio.h>
/*
Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum.
Note that the two subarrays must begin at different indices.

Return true if these subarrays exist, and false otherwise.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [4,2,4]
Output: true
Explanation: The subarrays with elements [4,2] and [2,4] have the same sum of 6.
Example 2:

Input: nums = [1,2,3,4,5]
Output: false
Explanation: No two subarrays of size 2 have the same sum.
*/

int check_equal_sum_subarray(int *arr, int size){
  int h[20] = {0};
  
  for(int i = 0; i < size-1; i++){
    
    if(h[arr[i] + arr[i+1]] == 1)
      return 1;
    
    h[arr[i] + arr[i+1]] = 1;
  }
  
  return 0;
}

int main()
{
  int nums[] = {4, 2, 3, 4};
  int size = sizeof(nums) / sizeof(nums[0]);
  
  int result = check_equal_sum_subarray(nums, size);
  
  if(result == 1){
    printf("True");
  } else {
    printf("False");
  }
}