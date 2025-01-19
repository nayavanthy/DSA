#include <stdio.h>
/*
You are given an integer array ribbons, where ribbons[i] represents 
the length of the i-th  ribbon, and an integer k. You may cut any of 
the  ribbons into any number of segments of positive integer lengths, 
or perform no cuts at all.

For example, if you have a ribbon of length 4, you can:
Keep the ribbon of length 4,
Cut it into one ribbon of length 3 and one ribbon of length 1,
Cut it into two ribbons of length 2,
Cut it into one ribbon of length 2 and two ribbons of length 1, or
Cut it into four ribbons of length 1.
Your goal is to obtain k ribbons of all the same positive integer length. 
You are allowed to throw away any excess ribbon as a result of cutting.

Return the maximum possible positive integer length that you can obtain k 
ribbons of, or 0 if you cannot obtain k ribbons of the same length.

Example 1:

Input: ribbons = [9,7,5], k = 3

Output: 5

Explanation:

Cut the first ribbon to two ribbons, one of length 5 and one of length 4.
Cut the second ribbon to two ribbons, one of length 5 and one of length 2.
Keep the third ribbon as it is.
Now you have 3 ribbons of length 5.
*/
int max_length(int *ribbons, int size){
  int max  = 0;
  
  for(int i = 0; i < size; i++){
    if(ribbons[i] > max){
      max = ribbons[i];
    }
  }
  
  return max;
}

int max_length_k_ribbons(int *ribbons, int size, int num_ribbons){
  int low = 0, high;
  high = max_length(ribbons, size);
  
  while(low<high){
    int mid = (low+high+1) / 2;
    int count = 0;
    
    for(int i = 0; i<size; i++){
      count += ribbons[i] / mid;
    }
    
    if(count < num_ribbons){
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  
  return low;
}
int main()
{
   int ribbons[] = { 9, 7, 5};
   int size = sizeof(ribbons) / sizeof(ribbons[0]);
   int num_ribbons = 5;
   int result;
   
   result = max_length_k_ribbons(ribbons, size, num_ribbons);
   
   printf("%d", result);
}