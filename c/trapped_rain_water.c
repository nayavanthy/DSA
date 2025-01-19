#include <stdio.h>
/*
Given n non-negative integers representing an elevation map
where the width of each bar is 1, compute how much water 
it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is 
represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 
6 units of rain water (blue section) are being trapped.

https://leetcode.com/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150
*/

int min(int a, int b){
  if(a>b){
    return b;
  } else {
    return a;
  }
}

int rainwater_volume(int* arr, int size){
  int rainwater_volume = 0;
  
  for(int i = 0; i<size; i++){
    int left = arr[i];
    
    for(int j = 0; j<i; j++){
      if(arr[j]>left){
        left = arr[j];
      }
    }
    
    int right = arr[i];
    for(int j = i; j < size; j++){
      if(arr[j]>right){
        right = arr[j];
      }
    }
    
    rainwater_volume += min(left, right) - arr[i];
  }
  
  return rainwater_volume;
}

int main()
{
  int arr[] = {3, 0, 1, 0, 4, 0, 2};
  int size = sizeof(arr) / sizeof(arr[0]);
  int volume;
  volume = rainwater_volume(arr, size);
  
  printf("volume of trapped rainwater is - %d", volume);
}