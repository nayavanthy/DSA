#include <stdio.h>
// 3 sum two pointer

int three_sum(int *arr, int size,  int target){
  for(int i=0; i<size-2; i++){
    int left = i+1;
    int right = size-1;
    
    while(left<right){
      int test = arr[i]+arr[left]+arr[right];
      if(test==target){
        return(1);
      }
      else if(test<target){
        left++;
      }
      else{
        right--;
      }
    }
  }
  
  return(0);
}
int main()
{
  int arr[]= {1, 2, 3, 4, 5};
  int target = 100;
  
  if(three_sum(arr, 5, target)==1){
    printf("True");
  }
  else{
    printf("false");
  }
}