#include <stdio.h>
/*
Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, 
LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, 
it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total 
capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will 
be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.

 

Example 1:

Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
*/

void min_heapify(int *arr, int *copy, int n, int i){
  int smallest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;
  
  if (left < n && arr[left] < arr[smallest]){
    smallest = left;
  }
  
  if (right < n && arr[right] < arr[smallest]){
    smallest = right;
  }
  
  if(smallest != i){
    int temp = arr[i];
    int temp2 = copy[i];
    
    arr[i] = arr[smallest];
    copy[i] = copy[smallest];
    
    arr[smallest] = temp;
    copy[smallest] = temp2;
    
    min_heapify(arr, copy, n, smallest);
  }
}

int find_maximum_capital(int *profits, int *capital, int num_proj, int k, int w){
  min_heapify(capital, profits, num_proj, 0);
  int top = 0;
  while(k>0){
    int index = top;
    int max_profit = 0;
    //find maximum profit we can afford
    while(capital[index] <= w){
      if(max_profit < profits[index])
        max_profit = profits[index];
        
      index++;
    }
    
    w += max_profit;
    k--;
    top++;
  }
  
  return w;
}

int main()
{
  int profits[] = {1, 2, 3};
  int capital[] = {0, 0, 0};
  int num_proj = sizeof(profits) / sizeof(profits[0]);
  int k = 2;
  int w = 0;
  
  int maximum_capital = find_maximum_capital(profits, capital, num_proj, k, w);
  printf("%d", maximum_capital);
}