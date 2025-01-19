"""
You are given the head of a linked list.

The nodes in the linked list are sequentially assigned to non-empty groups whose lengths form the sequence of the natural numbers (1, 2, 3, 4, ...). The length of a group is the number of nodes assigned to it. In other words,

The 1st node is assigned to the first group.
The 2nd and the 3rd nodes are assigned to the second group.
The 4th, 5th, and 6th nodes are assigned to the third group, and so on.
Note that the length of the last group may be less than or equal to 1 + the length of the second to last group.

Reverse the nodes in each group with an even length, and return the head of the modified linked list.
"""

class Node:
  def __init__(self, data):
    self.data = data
    self.ptr  = None
    
class LinkedList:
  def __init__(self):
    self.head = None
    
  def print_list(self):
    node= self.head
    while(node is not None):
      print(node.data, end='->')
      node= node.ptr
    print()
    
  def reverse_even_groups(self):
    def reverse_linked_list(start, end):
      prev = None
      curr = start
      while curr != end:
          next_node = curr.ptr
          curr.ptr = prev
          prev = curr
          curr = next_node
      return prev

    dummy = Node(0)
    dummy.ptr = self.head
    prev_group_end = dummy

    node = self.head
    group_length = 1

    while(node is not None):
      group_start = node
      for _ in range(group_length):
        if not node:
          break
        node = node.ptr
        
      if group_length % 2 == 0:  # Reverse the group if the length is even
        prev_group_end.ptr = reverse_linked_list(group_start, node) #prev_group_end now points at end of the group
        group_start.ptr = node  # Connect reversed group's tail to the next group 
        prev_group_end = group_start
      else:
        prev_group_end = group_start
        for _ in range(group_length - 1):
          prev_group_end = prev_group_end.ptr
          
      group_length += 1

    self.head = dummy.ptr

ll = LinkedList()
ll.head = Node(1)
ll.head.ptr = Node(2)
ll.head.ptr.ptr = Node(3)
ll.head.ptr.ptr.ptr = Node(4)
ll.head.ptr.ptr.ptr.ptr = Node(5)
ll.head.ptr.ptr.ptr.ptr.ptr = Node(6)
#ll.head.ptr.ptr.ptr.ptr.ptr.ptr = Node(7)
#ll.head.ptr.ptr.ptr.ptr.ptr.ptr.ptr = Node(8)

ll.print_list()

ll.reverse_even_groups()

ll.print_list()