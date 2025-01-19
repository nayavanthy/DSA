#include <stdio.h>
/*
Given an array of coins[] of size n and a target value sum, where coins[i] 
represent the coins of different denominations. You have an infinite supply 
of each of the coins. The task is to find the minimum number of coins
required to make the given value sum. If it’s not possible to make a change, 
return -1.

Examples:  

Input: coins[] = [25, 10, 5], sum = 30
Output: 2
Explanation : Minimum 2 coins needed, 25 and 5  


Input: coins[] = [9, 6, 5, 1], sum = 19
Output: 3
Explanation: 19 = 9 + 9 + 1
*/
int min(int a, int b){
  if(a>b)
    return b;
  else
    return a;
}

int min_coin_sum(int *coins, int sum, int size, int index){
  if(sum == 0){
    return 0;
  }
  if(sum < 0 || index == size){
    return 10000;
  }
  
  int take;
  take = min_coin_sum(coins, sum - coins[index], size, index);
  if(take < 10000){
    take++;
  }
  
  int no_take;
  no_take = min_coin_sum(coins, sum, size, index+1);
  
  return min(take, no_take);
  
}

int main()
{
  int coins[] = {25, 10, 5};
  int size = sizeof(coins) / sizeof(coins[0]);
  int sum = 4;
  int result;
  
  result = min_coin_sum(coins, sum, size, 0);
  
  if(result < 10000){
    printf("%d", result);
  } else {
    printf("sum can't be made from given coin denominations");
  }
}