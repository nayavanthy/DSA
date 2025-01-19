#include <stdio.h>
#include <stdlib.h>
/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before
each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate
them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

logic

sum of all elements = S 

let P be the sum of all positive elements and N be the sum of all negative elements
P-N = target

we know
P+N = S 

therefore adding the two equations 
2P = target+sum
or
P = target+sum/2 

thus if we find possible ways to get sum of P from arr we have solved the problem.

initialize an array from 0 to P, it will store number of ways to get sum of the index
update this array with the ways to form sum 0 to P by processing each num in arr
*/

int get_target_sum_ways(int *arr, int target, int size){
  int sum = 0;
  for(int i = 0; i < size; i++){
    sum += arr[i];
  }
  
  if((target > sum) || ((sum+target)%2 !=0))
    return 0;
    
  int n = (sum + target)/2;
  int* dp = (int*)calloc(n + 1, sizeof(int));
  dp[0] = 1;
  
  for(int i = 0; i < size; i++){
    for(int j = n; j >= arr[i]; j--){
      dp[j] += dp[j-arr[i]];
    }
  }
  
  return dp[n];
}

int main()
{
  int nums[] = {1, 1, 1, 1, 1};
  int size = sizeof(nums) / sizeof(nums[0]);
  int target = 3;
  
  int result = get_target_sum_ways(nums, target, size);
  
  printf("%d", result);
}