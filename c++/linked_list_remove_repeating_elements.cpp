#include <iostream>
#include <sstream>
using namespace std;
/*
Given a linked list, remove all repeating elements
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
  
  void remove_repeating_element(){
    Node* node = head;
    int curr = node->data;
    Node* prev = head;
    
    while(node != nullptr){
      
      if(node->data != curr){
        prev->ptr = node;
        curr = node->data;
        
        if(node->ptr == nullptr || node->ptr->data != node->data){
          prev = node;
        }
      }
      
      node = node->ptr;
    }
  }
  
};

int main() 
{
  LinkedList ll;
  int a[] = {1, 2, 2, 2, 3, 3, 4, 5};
  ll.create_linked_list(a, 8);
  ll.print_linked_list();
  ll.remove_repeating_element();
  ll.print_linked_list();
  
  //multiline input as a string
  string input = R"(
2
8
1 2 2 2 3 3 4 7
3
4 5 6
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
    ll.remove_repeating_element();
    ll.print_linked_list();
    
    num_test_cases--;
  }

}