#include <stdio.h>

/*
You are given an integer array nums. You are initially positioned 
at the array's first index, and each element in the array represents 
your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum 
jump length is 0, which makes it impossible to reach the last index.
*/

int reach_last_index(int* nums, int size){
  int max_reach = nums[0];
  
  for(int i = 0; i < size; i++){
    if(i > max_reach){
      return 0;
    }
    
    if(i + nums[i] > max_reach){
      max_reach = i + nums[i];
    }
    
    if(max_reach > size - 1){
      return 1;
    }
  }
}
int main()
{
  int arr[] = {2,3,1,1,4};
  int size = sizeof(arr) / sizeof(arr[0]);
  
  if(reach_last_index(arr, size)){
    printf("Can reach the last index\n");
  } else {
    printf("Can't reach the last index\n");
  }
  
  int arr2[] = {3,2,1,0,4};
  int size2 = sizeof(arr2) / sizeof(arr2[0]);
  
  if(reach_last_index(arr2, size2)){
    printf("Can reach the last index\n");
  } else {
    printf("Can't reach the last index\n");
  }
}