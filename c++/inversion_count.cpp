#include <iostream>
#include <sstream>
using namespace std;
/*
The inversion count of an array denotes how far 
is the array from being sorted.
If the array is sorted, inversion count is 0. If
the array is sorted in reverse order, the inversion
count is maximum.
More formally, the inversion count of an array A 
is the number of pairs (i, j) such A[i] < A[j] and i > j.

*/

int inversion_count(int* arr, int size){
  
  int count = 0;
  
  for(int i=0; i<size; i++){
    for(int j=i; j<size; j++){
      if(arr[i]>arr[j]){
        count++;
      }
    }
  }
  
  return count;
}
int main() 
{
  int arr[] = {3, 1, 2};
  int size = sizeof(arr) / sizeof(arr[0]);
  int return_value = inversion_count(arr, size);
  
  printf("%d\n", return_value);
  
  //multiline input as a string
  string input = R"(
3
5
1 1 2 2 3
3
3 2 1
5
10 1 2 3 4
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
    
    return_value = inversion_count(a1, s1);
    
    printf("%d\n", return_value);
    
    num_test_cases--;
  }

}