#include <stdio.h>

/*
Problem Statement: Best Time to Buy and Sell Stock
You are given an array prices where prices[i] represents the price of a given stock on the i'thday.

Your task is to maximize your profit by choosing a single day to buy one stock and a different day in the future to sell that stock.

If no profit can be achieved, return 0.

Constraints:
You may not engage in multiple transactions (i.e., you can only buy and sell once).

Example:
Input:
prices = [7, 1, 5, 3, 6, 4]

Output:
5

Explanation:
Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6−1=5.

Input:
prices = [7, 6, 4, 3, 1]

Output:
0

Explanation:
In this case, no transaction is done as no profit is possible.

Objective:
Write a function that takes an array of integers prices and returns the maximum profit that can be achieved.

*/

int max_profit(int *arr, int size){
  int i, min=arr[0], max_profit=0;
  for(i = 0; i<size; i++){
    if(min> arr[i]){
      min = arr[i];
    }
    if(max_profit< arr[i]-min){
      max_profit = arr[i]- min;
    }
  }
  
  return(max_profit);
}

int main()
{
  int prices[] = {7, 2, 8, 1, 3};
  int size = 5;
  int result;
  
  result = max_profit(prices, size);
  
  printf("%d", result);
}