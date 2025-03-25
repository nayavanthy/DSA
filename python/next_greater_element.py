"""
Given an array of positive integers A, find the first 
greater number for every element on its right. If
a greater number does not exist, use -1.
"""

def next_greater_element(in_arr):
  out_arr = []
  for i in range(0, len(arr)):
    out_arr.append(-1)
    for j in range(i+1, len(arr)):
      if(in_arr[j] > in_arr[i]):
        out_arr[i] = in_arr[j]
        break;
  
  return out_arr
  
arr = [1, 5, 2, 3, 5]
print(next_greater_element(arr))