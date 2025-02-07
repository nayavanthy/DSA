import java.util.*;

/*
Given a linked list, rotate it to the right by k nodes.
Examples:
Input: 1→2→3→4
k: 3
Output: 2→3→4→1
*/

class Node {
  int val;
  Node next;
  
  Node(int val){
    this.val = val;
    this.next = null;
  }
}

public class Main {
  public static Node rotate_list(Node head, int k){
    Node tail = head;
    int length = 1;
    
    while(tail.next != null){
      length++;
      tail = tail.next;
    }
    
    k = k % length;
    
    if(k == 0){
      return head;
    }
    
    Node new_tail = head;
    
    for(int i = 0; i < length - k - 1; i++){
      new_tail = new_tail.next;
    }
    
    tail.next = head;
    
    head = new_tail.next;
    
    new_tail.next = null;
    
    return head;
  }
  
  public static void printList(Node head) {
    Node temp = head;
    while (temp != null) {
      System.out.print(temp.val + " → ");
      temp = temp.next;
    }
    System.out.println("NULL");
  }

  public static void main(String[] args) {
    Node head = new Node(1);
    head.next = new Node(2);
    head.next.next = new Node(3);
    head.next.next.next = new Node(4);
    int k = 3;
    
    System.out.println("Original List:");
    printList(head);
    
    head = rotate_list(head, k);
    
    System.out.println("Reordered List:");
    printList(head);
  }
}