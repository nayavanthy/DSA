class Node:
  def __init__(self, data):
    self.data = data
    self.pointer = None

def cycle_detection(node):
  slow = node
  fast = node
  
  while(fast != None):
    slow = slow.pointer
    fast = fast.pointer.pointer
    
    if(slow==fast):
      return True
      
  
  return False

linked_list = Node(1)
linked_list.pointer = Node(2)
linked_list.pointer.pointer = Node(3)
linked_list.pointer.pointer.pointer = Node(4)
linked_list.pointer.pointer.pointer.pointer = linked_list.pointer

print(cycle_detection(linked_list))