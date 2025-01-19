#include <iostream>
#include <sstream>
using namespace std;

int rotated_binary_search(int* arr, int target, int high, int low){
  if(low > high){
    return -1;
  }
  
  int mid = (high + low) / 2;
  
  if(arr[mid] == target){
    return mid;
  }
  
  if(arr[mid] <= arr[high]){
    if(arr[mid] < target && target <= arr[high]){
      return rotated_binary_search(arr, target, high, mid+1);
    }
    else{
      return rotated_binary_search(arr, target, mid-1, low);
    }
  }
  else{
    if(arr[low] <= target && target < arr[mid]){
     return rotated_binary_search(arr, target, mid-1, low);
    }
    else{
      return rotated_binary_search(arr, target, high, mid+1);
    }
  }
}

int main() 
{
  int arr[] = {4, 5, 6, 7, 1, 2, 3};
  int target = 1;
  int size = sizeof(arr) / sizeof(arr[0]);
  int return_value;
  
  return_value = rotated_binary_search(arr, target, size-1, 0);
  
  printf("%d\n", return_value);
  
  //multiline input as a string
  string input = R"(
4
7
4 5 6 7 0 1 2
4
4
3 4 1 2
5
5
5 1 2 3 4
2
4
5 6 3 4
4
)";
  
  stringstream ss(input);
  
  int num_test_cases;
  ss >> num_test_cases;
  
  while(num_test_cases > 0){
    int s1;
    ss >> s1;
    
    int a1[s1];
    for(int i = 0; i < s1; i++){
      ss >> a1[i];
    }
    
    int target;
    ss >> target;
    
    return_value = rotated_binary_search(a1, target, s1-1, 0);
    
    printf("%d\n", return_value);
    
    num_test_cases--;
  }
}