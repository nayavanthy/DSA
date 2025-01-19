#include <stdio.h>
#include<stdlib.h>
/*
Problem Statement:
Given an array of integers nums and an integer k, 
find the maximum value in every contiguous subarray (sliding window) of size k. 
Return the resulting array of maximum values.
*/

void sliding_window_maximum(int *inarr, int size, int window_size, int *outarr){ // O(n*k)
  int i, j, max;
  
  for(i=0; i<=size-window_size; i++){
    max = inarr[i];
    
    for(j= i+1; j<i+window_size; j++){
      if(max<inarr[j])
        max = inarr[j];
    }
    
    outarr[i] = max;
  }
}

void sliding_window_maximum_dequeue(int *inarr, int size, int window_size, int *outarr){ // O(n)
  int dequeue[size];
  int front = 0, back = -1;
  int out_idx= 0;
  
  for(int i= 0; i< size; i++){
    if(front<=back && dequeue[front]< i- window_size + 1){
      front++;
    }
    
    while(front<=back && inarr[dequeue[back]]<inarr[i]){
      back--;
    }
    
    dequeue[++back] = i;
    
    if(i>= window_size-1){
      outarr[out_idx++] = inarr[dequeue[front]];
    }
  }
}

int main()
{
  int arr[] = {1,2,3,4,5,6,7,8,9};
  int arr_size = 9;
  int window_size = 3;
  int resarr_size = arr_size - window_size+1;
  int resarr[resarr_size];
  
  sliding_window_maximum_dequeue(arr, arr_size, window_size, resarr);
  
  for(int i= 0; i<resarr_size; i++){
    printf("%d ", resarr[i]);
  }
}