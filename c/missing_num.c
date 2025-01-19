#include <stdio.h>
/*
Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 
  2 is the missing number in the range since it does not appear in nums.
*/

int get_missing_num(int *arr, int size){
  int xor = size;
  //xor of i and arr[i] will eventually cancel out for all i except for the one not found in arr
  for(int i=0; i<size; i++){
    xor = xor ^ i ^ arr[i];
  }
  
  return xor;
}

void print_arr(int *arr, int size){
  
  for(int i=0; i<size; i++){
    printf("%d ", arr[i]);
  }
  
  printf("\n");
}

int get_missing_num_cyclic_sort(int *arr, int size){
  int i=0;
  
  while(i<size){
    print_arr(arr, size);
    if(arr[i]<size && arr[i]!= arr[arr[i]]){
      int temp = arr[arr[i]];
      arr[arr[i]] = arr[i];
      arr[i] = temp;
    }
    else{
      i++;
    }
  }
  
  for(int i=0; i<size; i++){
    if(arr[i]!=i)
      return i;
  }
  
  return size;
}
int main()
{
  int arr[] = {9,6,4,2,3,5,7,0,1};
  int size = sizeof(arr) / sizeof(arr[0]);
  
  int missing_num = get_missing_num_cyclic_sort(arr, size);
  
  printf("%d", missing_num);
}