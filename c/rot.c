#include <stdio.h>
/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, 
or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
*/

int mod_binary_search(int *arr, int target, int low, int high){
  int mid= (high+low)/2;
  
  //printf("%d %d %d\n", high, low, mid);
  
  if(arr[mid]==target)
    return mid;
    
  if(high<=low)
    return -1;
    
  if(arr[low]<=arr[mid]){
    
    if(arr[low]<=target && arr[mid]>target)
      return mod_binary_search(arr, target, low, mid-1);
    else
      return mod_binary_search(arr, target, mid+1, high);
      
  } else{
    
    if(arr[mid]<target && target<= arr[high])
      return mod_binary_search(arr, target, mid+1, high);
    else
      return mod_binary_search(arr, target, low, mid-1);
      
  }
}
int main()
{
  int arr[8] = {4, 5, 6, 7, 0, 1, 2, 3};
  int target = 0;
  
  //printf("%d", mod_binary_search(arr, target, 0, 7));
  for(int i=0; i<10; i++){
    printf("found %d at %d\n", i ,mod_binary_search(arr, i, 0, 7));
  }
  
}