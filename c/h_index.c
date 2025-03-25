#include <stdio.h>
/*
Given an array of integers citations where citations[i] is the number
of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is 
defined as the maximum value of h such that the given researcher has
published at least h papers that have each been cited at least h times.

 

Example 1:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and 
each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the 
remaining two with no more than 3 citations each, their h-index is 3.
Example 2:

Input: citations = [1,3,1]
Output: 1
*/

int max(int* arr,int size){
  int max = 0;
  
  for(int i = 0; i < size; i++){
    
    if(arr[i] > max){
      max = arr[i];
    }
  }
  
  return max;
}

int h_index(int* arr,int size){
  int max_citations = max(arr, size);
  
  for(int i = max_citations; i >= 0; i--){
    int count = 0;
    
    for(int j = 0; j < size; j++){
      if(arr[j] >= i){
        count++;
      }
    }
    
    if(count >= i){
      return i;
    }
  }
  
  return 0;
}

int main()
{
  int citations[] = {3, 0, 6, 1, 5};
  int size = sizeof(citations) / sizeof(citations[0]);
  
  int result = h_index(citations, size);
  
  printf("%d", result);
}