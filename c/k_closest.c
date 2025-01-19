#include <stdio.h>
#include<stdlib.h>
/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3

Output: [1,2,3,4]

Example 2:

Input: arr = [1,1,2,3,4,5], k = 4, x = -1

Output: [1,1,2,3]
*/
void get_k_closest(int *arr,int size, int k, int target, int *ret){
  int low = 0;
  int high = size; 
  int mid;
  
  while(low<high){
    mid = (high + low) / 2 ;
    
    if( abs( arr[mid] - target ) <= abs( arr[mid+k] - target ) ){ //Check if target is closer to mid or closer to arr[mid + k] 
      high = mid;
    }
    else{
      low = mid+1;
    }
  }
  
  for(int i=0; i<k; i++){
    ret[i] = arr[low+i];
  }
  
  return;
}

int main()
{
  int arr[] = {1,2,3,4,5};
  int k = 4, x= 3;
  int size = sizeof(arr)/sizeof(arr[0]);
  int ret[k];
  
  get_k_closest(arr, size, k, x, ret);
  
  for(int i =0; i<k; i++){
    printf("%d ", ret[i]);
  }
}