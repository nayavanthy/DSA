#include <iostream>
using namespace std;

/*
Given an integer array nums, return an array 
answer such that answer[i] is equal to the product
of all the elements of nums except nums[i].
*/

int* product_array(int* arr, int size) {
  int* result = new int[size];

  int* left = new int[size];
  int* right = new int[size];

  left[0] = 1;
  for (int i = 1; i < size; i++) {
    left[i] = left[i - 1] * arr[i - 1];
  }
  
  right[size - 1] = 1;
  for (int i = size - 2; i >= 0; i--) {
    right[i] = right[i + 1] * arr[i + 1];
  }
  
  for (int i = 0; i < size; i++) {
    result[i] = left[i] * right[i];
  }

  return result;
}

int main() 
{
  int arr[] = {1 , 2, 3};
  int size = sizeof(arr) / sizeof(arr[0]);
  int* answer;
  
  answer = product_array(arr, size);
  
  for(int i = 0; i < size; i++){
    printf("%d ", answer[i]);
  }
}