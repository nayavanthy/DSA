"""
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

"""

class Node:
  def __init__(self, data):
    self.data = data
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
    
  def height(self, node = "default"):
    if node == "default":
      node = self.root
      
    if node is None:
      return 0
      
    lheight = self.height(node.left)
    rheight = self.height(node.right)
    
    if lheight > rheight:
      return lheight + 1 
    else:
      return rheight + 1
      
  def find_diameter(self, node= "default"):
    
    if node == "default":
      node = self.root
      
    if node is None:
      return 0
      
    lheight = self.height(node.left)
    rheight = self.height(node.right)
    
    ldia = self.find_diameter(node.left)
    rdia = self.find_diameter(node.right)
    
    return max(lheight+rheight, ldia, rdia)

arr = [1, 2, 3, 4, 5, 6]
tree = Tree(arr)

diameter = tree.find_diameter()
print("diameter of the tree is ", diameter)