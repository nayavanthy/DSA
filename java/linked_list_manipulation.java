import java.util.*;

/*
Given a linked list of the form:
N0 → N1 → N2 → ....Nn-2 → Nn-1
Reorder the list in the following format:
N0 → Nn-1 → N1 → Nn-2 → N2 → ....
*/
class Node {
  int val;
  Node next;
  
  Node(int val) {
    this.val = val;
    this.next = null;
  }
}

public class Main {
  public static void reorderList(Node head) {
      if (head == null || head.next == null) return;
      
      //find middle
      Node slow = head, fast = head;
      while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
      }
      
      //reverse second half
      Node prev = null, curr = slow.next;
      slow.next = null; 
      while (curr != null) {
        Node nextNode = curr.next;
        curr.next = prev;
        prev = curr;
        curr = nextNode;
      }
      
      //merge first and the reversed second half
      Node first = head, second = prev;
      while (second != null) {
          Node temp1 = first.next, temp2 = second.next;
          first.next = second;
          second.next = temp1;
          first = temp1;
          second = temp2;
      }
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
    head.next.next.next.next = new Node(5);
    
    System.out.println("Original List:");
    printList(head);
    
    reorderList(head);
    
    System.out.println("Reordered List:");
    printList(head);
  }
}