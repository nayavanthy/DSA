#include <iostream>
#include <sstream>
using namespace std;
/*
Given a Linked List, find middle element
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
  
  int find_middle_element(){
    Node* slow = head;
    Node* fast = head;
    
    while(fast != nullptr && fast->ptr != nullptr){
      fast = fast->ptr->ptr;
      if(fast != nullptr){
        slow = slow->ptr;
      }
    }
    
    return(slow->data);
  }
  
  void print_linked_list(){
    Node* node = head;
    
    while(node != nullptr){
      printf("%d->", node->data);
      node = node->ptr;
    }
    
    printf("NULL\n");
  }
};

int main() 
{
  LinkedList ll;
  int a[] = {1, 2, 3, 4, 5};
  ll.create_linked_list(a, 5);
  ll.print_linked_list();
  
  int middle = ll.find_middle_element();
  printf("%d\n", middle);
  
  //multiline input as a string
  string input = R"(
2
4
3 4 5 6
1
3
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
    middle = ll.find_middle_element();
    printf("%d\n", middle);
    
    num_test_cases--;
  }
}