import java.util.*;

/*
Given a linked list which can have a loop, find the node 
at which the loop starts. If no loop exists,
return NULL.

Assuming data in each node is unique
*/

public class Main {

  public static void main(String[] args) {
    Node head = new Node(1);
    head.next = new Node(2);
    head.next.next = new Node(3);
    head.next.next.next = new Node(4);
    head.next.next.next.next = head.next.next;
    
    LinkedList ll = new LinkedList();
    
    Node loop_start = ll.get_loop_starting_node(head);
    
    if(loop_start == null){
      System.out.println("no loop");
    } else {
      System.out.println(loop_start.val);
    }
    
  }
}

class Node {
  int val;
  Node next;
  
  Node(int val) {
    this.val = val;
    this.next = null;
  }
}

class LinkedList {
  
  public boolean check_loop(Node head){
    Node slow = head;
    Node fast = head.next;
    
    while(fast != null && fast.next != null){
      if(slow == fast){
        return true;
      }
      
      slow = slow.next;
      fast = fast.next.next;
    }
    
    return false;
  }
  
  public Node get_loop_starting_node(Node head){
    
    if(check_loop(head)){
      Node curr_node = head;
      int[] hash_map = new int[50];
      
      while(true){
        
        if(hash_map[curr_node.val] == 1){
          return curr_node;
        }
        
        hash_map[curr_node.val] = 1;
        curr_node = curr_node.next;
      }
      
    } else {
      return null;
    }
  }
}
