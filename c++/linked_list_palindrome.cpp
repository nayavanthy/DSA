#include <iostream>
#include <sstream>
using namespace std;
/*
Given a linked list check if its a palindrome
*/

class Node{
public:
  int data;
  Node* ptr;
  Node(int in_data){
    data = in_data;
    ptr = nullptr;
  }
};

class LinkedList{
public:

  Node* head = nullptr;
  
  void create_linked_list(int *arr, int size){
    
    head = new Node(arr[0]);
    
    Node* prev = head;
    
    for(int i = 1; i < size; i++){
      Node* temp = new Node(arr[i]);
      prev->ptr = temp;
      prev = temp;
    }
  }
  
  void print_linked_list(){
    Node* node = head;
    
    while(node != nullptr){
      printf("%d->", node->data);
      node = node->ptr;
    }
    
    printf("NULL\n");
  }
  
  Node* reverse_linked_list(Node* start_node){
    Node* prev = nullptr;
    Node* current = start_node;
    Node* next = nullptr;
    
    while (current != nullptr){
      next = current->ptr;
      
      current->ptr = prev;
      
      prev = current;
      current = next;
    }
    
    return prev;
  }
  
  int check_palindrome(){
    Node* slow = head;
    Node* fast = head;
    
    while(fast != nullptr && fast->ptr != nullptr){
      fast = fast->ptr->ptr;
      if(fast != nullptr){
        slow = slow->ptr;
      }
    }
    
    Node* second_half = reverse_linked_list(slow);
    Node* first_half = head;
    Node* temp = second_half;
    
    while(temp != nullptr){
      if(temp->data != first_half->data){
        return 0;
      }
      temp = temp->ptr;
      first_half = first_half->ptr;
    }
    
    return 1;
  }
  
};

int main() 
{
  LinkedList ll;
  int a[] = {1, 2, 3, 4, 5};
  ll.create_linked_list(a, 5);
  ll.print_linked_list();
  int palindrome_flag = ll.check_palindrome();
  printf("%d\n", palindrome_flag);
  
  //multiline input as a string
  string input = R"(
3
4
3 4 5 3
5
1 2 3 2 1
3
3 1 3
)";
  
  stringstream ss(input);
  
  int num_test_cases;
  ss >> num_test_cases;
  
  while(num_test_cases > 0){
    int size;
    ss >> size;
    
    int arr[size];
    for(int i = 0; i < size; i++){
      ss >> arr[i];
    }
    
    LinkedList ll;
    ll.create_linked_list(arr, size);
    ll.print_linked_list();
    palindrome_flag = ll.check_palindrome();
    printf("%d\n", palindrome_flag);
    
    num_test_cases--;
  }

}