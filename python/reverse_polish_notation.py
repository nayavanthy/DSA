"""
evaluate reverse polish notation

["6", "3", "+", "5", "/"]

1
"""
def is_integer(s):
  return s.lstrip('-').isdigit()

def evaluate(in_arr):
  stack = []
  
  for c in in_arr:
    
    if is_integer(c):
      stack.append(int(c))
      
    else :
      b = stack.pop()
      a = stack.pop()
      
      if c == '+':
        stack.append(a+b)
      if c == '-':
        stack.append(a-b)
      if c == '*':
        stack.append(a*b)
      if c == '/':
        c = int(a/b)
        stack.append(int(a/b))
        
  return stack[0]
  
arr = ["6", "-3", "+", "5", "-"]


print(evaluate(arr))