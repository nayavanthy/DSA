#include <iostream>
#include <sstream>
using namespace std;

int two_sum(int* arr, int size){
  int hash_map[10] = {0};
  
  for(int i = 0; i < size; i++){
    if(hash_map[abs(arr[i])] > 0){
      return 1;
    }
    
    hash_map[abs(arr[i])]++;
  }
  
  return -1;
}

int main() 
{
  int arr[] = {-3, 1, 3, 4};
  int size = sizeof(arr) / sizeof(arr[0]);
  int return_value;
  
  return_value = two_sum(arr, size);
  
  if(return_value == 1){
    printf("True\n");
  } else {
    printf("False\n");
  }
  
  //multiline input as a string
  string input = R"(
2
4
-3 1 3 4
4
-2 1 3 4
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
    
    return_value = two_sum(a1, s1);
    
    if(return_value == 1){
      printf("True\n");
    } else {
      printf("False\n");
    }
    
    num_test_cases--;
  }
}