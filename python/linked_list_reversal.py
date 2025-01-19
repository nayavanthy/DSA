#inplace linkedlist reversal

class Node:
  def __init__(self, data):
    self.data = data
    self.ptr = None

class LinkedList:
  def __init__(self):
    self.head = None
  
  def print_list(self):
    current = self.head
    while current:
      print(current.data, end=" -> ")
      current = current.ptr
    print("None")
    
  def reversal(self):
    node = self.head
    prev = None
    
    while(node):
      nxt = node.ptr
      node.ptr = prev
      prev = node
      node = nxt
      
    self.head = prev

ll = LinkedList()
ll.head = Node(1)
ll.head.ptr = Node(2)
ll.head.ptr.ptr = Node(3)
ll.head.ptr.ptr.ptr = Node(4)

ll.print_list()

ll.reversal()
print("reversed")
ll.print_list()

