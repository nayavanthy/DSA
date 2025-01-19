#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

int max(int a, int b){
  if(a > b){
    return a;
  } else {
    return b;
  }
}

int is_vowel(char a){
  if(a == 'a' || a == 'e'
  || a == 'i' || a == 'u'
  || a == 'o'){
    return 1;
  } else {
    return 0;
  }
}

int max_vowels_substring(char* arr, int size, int sub_array_size){
  int window_count = 0;
  
  for(int i = 0; i < sub_array_size; i++){
    window_count += is_vowel(arr[i]);
  }
  
  int max_count = window_count;
  
  for(int i = sub_array_size; i < size; i++){
    window_count = window_count - is_vowel(arr[i - sub_array_size]) + is_vowel(arr[i]);
    max_count = max(window_count, max_count);
  }
  
  return max_count;
}

int main() 
{
  char arr[] = "workaattech";
  int size = strlen(arr);
  int sub_array_size = 3;
  int result = max_vowels_substring(arr, size, sub_array_size);
  printf("%d\n", result);

  // Multiline input
  string input = R"(
2
workaattech 3
substring 2
)";

  stringstream ss(input);

  int num_test_cases;
  ss >> num_test_cases;

  while (num_test_cases > 0) {
    char arr[100];
    int sub_array_size;
    string temp;
    
    // Read the string and sub-array size
    ss >> temp;
    strcpy(arr, temp.c_str());
    int size = strlen(arr);
    
    ss >> sub_array_size;
    
    result = max_vowels_substring(arr, size, sub_array_size);
    
    printf("%d\n", result);
    
    num_test_cases--;
  }
}