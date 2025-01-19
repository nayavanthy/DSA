"""
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 
The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example 1:


Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node,
just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
"""

class Node:
  def __init__(self, data):
    self.data = data
    self.right = None
    self.left = None
    self.next = None

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
    
  def connectright(self):
    
    leftmost = self.root
    while leftmost.left is not None:
      head = leftmost
      
      while head is not None:
        head.left.next = head.right
        
        if head.next is not None:
          head.right.next = head.next.left
        
        head = head.next
      
      leftmost = leftmost.left
      
  def print_with_next(self):
    if not self.root:
      return

    level_start = self.root
    while level_start:
      current = level_start
      while current:
        print(current.data, end=" -> " if current.next else " -> None\n")
        current = current.next
      level_start = level_start.left 


arr_rep = [3, 9, 20, 4, 12, 15, 7]

tree = Tree(arr_rep)
tree.connectright()
tree.print_with_next()