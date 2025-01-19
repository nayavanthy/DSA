#include <iostream>
#include <sstream>
using namespace std;

/*
Sort an array A where each of the elements belong to the set: {0, 1, 2}
*/

void sort_array(int* arr, int size){
  int low = 0, mid = 0, high = size-1;
  
  while(mid<=high){
    if(arr[mid] == 0){
      arr[mid] = arr[low];
      arr[low] = 0;
      
      low++;
      mid++;
      
    } else if(arr[mid] == 1){
      mid++;
      
    } else {
      arr[mid] = arr[high];
      arr[high] = 2;
      
      high--;
    }
  }
}

void print_arr(int* arr, int size){
  
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  
  printf("\n");
}

int main() 
{
  int arr[] = {2, 2, 1, 0, 2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  
  print_arr(arr, size);
  sort_array(arr, size);
  print_arr(arr, size);
  
  //multiline input as a string
  string input = R"(
2
5
1 0 1 2 2
4
1 0 0 0
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
    
    print_arr(a1, s1);
    sort_array(a1, s1);
    print_arr(a1, s1);
    
    num_test_cases--;
  }
}