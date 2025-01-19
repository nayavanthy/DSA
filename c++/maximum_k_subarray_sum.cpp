#include <iostream>
#include <sstream>
using namespace std;

/*
Given an array and a number k, find the sum of the subarray that has the maximum sum among
all the subarrays of size k.
*/

int max(int a, int b){
  if(a > b){
    return a;
  } else {
    return b;
  }
}

int max_k_subarray_sum(int* arr, int size, int sub_array_size){
  int window_sum = 0;
  
  for(int i = 0; i < sub_array_size; i++){
    window_sum += arr[i];
  }
  
  int max_sum = window_sum;
  
  for(int i = sub_array_size; i < size; i++){
    window_sum = window_sum - arr[i - sub_array_size] + arr[i];
    max_sum = max(window_sum, max_sum);
  }
  
  return max_sum;
}

int main() 
{
  int arr[] = {3, 5, 6, 2, 4, 7, 8};
  int size = sizeof(arr) / sizeof(arr[0]);
  int sub_array_size = 3;
  int result;
  
  result = max_k_subarray_sum(arr, size, sub_array_size);
  
  printf("%d\n", result);
  
  //multiline input as a string
  string input = R"(
2
7 3
3 5 6 2 4 7 8
6 1
1 3 3 3 4 4
)";
  
  stringstream ss(input);
  
  int num_test_cases;
  ss >> num_test_cases;
  
  while(num_test_cases > 0){
    int s1;
    ss >> s1;
    
    ss >> sub_array_size;
    
    int a1[s1];
    for(int i = 0; i < s1; i++){
      ss >> a1[i];
    }
    
    result = max_k_subarray_sum(a1, s1, sub_array_size);
    
    printf("%d\n", result);
    
    num_test_cases--;
  }
}