"""

depth first search(dfs)

"""

class Node:
  def __init__(self, indata):
    self.data = indata
    self.right = None
    self.left = None
    
class Tree:
  def __init__(self, arr_rep):
    nodes = [None] * len(arr_rep)
    
    for i in range(len(arr_rep)):
      if arr_rep[i] is not None:
        nodes[i] = Node(arr_rep[i])
      
    for i in range(len(arr_rep)):
      if nodes[i] is not None:
        left_index = 2*i + 1
        right_index = 2*i + 2
        if left_index < len(arr_rep):
          nodes[i].left = nodes[left_index]
        if right_index < len(arr_rep):
          nodes[i].right = nodes[right_index]
      
    self.root = nodes[0]
    
  def level_order_traversal(self):
    node = self.root
    queue = []
    queue.append(node)
    while(queue):
      if node.right is not None:
        queue.append(node.right)
      if node.left:
        queue.append(node.left)
        
      print(node.data, end = '->')
      node = queue.pop()
      
      

if __name__ == '__main__':
  arr = [1, 2, 3, 4, 5, 6, 7]
  
  tree = Tree(arr)
  
  tree.level_order_traversal()