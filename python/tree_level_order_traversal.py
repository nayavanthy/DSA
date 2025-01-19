"""
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []

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
    
  def height(self, node = "empty"):
    if node == "empty":
      node = self.root
      
    if node is None:
      return 0
      
    lheight = self.height(node.left)
    rheight = self.height(node.right)
    
    if lheight > rheight:
      return lheight + 1 
    else:
      return rheight + 1
      
  def printcurrlevel(self, level, node = "empty"):
    if node == "empty":
      node = self.root
      
    if node is None:
      return
    
    if level == 1:
      print(node.data, end = " ")
      
    if level > 1:
      self.printcurrlevel(level - 1, node.left)
      self.printcurrlevel(level - 1, node.right)
      
  def printlevelorder(self):
    h = self.height()
    for i in range(1, h + 1):
      self.printcurrlevel(level = i)
      print()

arr_rep = [3,9,20, None, None,15,7]

tree = Tree(arr_rep)
tree.printlevelorder()