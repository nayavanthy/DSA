#include <iostream>
#include <sstream>
using namespace std;
/*
Given a linked list, reverse k groups 
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
  
  Node* reverse(Node* start, Node* end){
    Node* prev = start;
    Node* current = start->ptr;
    Node* next = nullptr;
    Node* final = end->ptr;
    
    while(current != end){
      next = current->ptr;
      current->ptr = prev;
      
      prev = current;
      current = next;
    }
    
    current->ptr = prev;
    start->ptr = final;
    return end;
  }
  
  void reverse_k_groups(int k){
    Node* start = head;
    Node* end = head;
    Node* prev = nullptr;
    
    while(end != nullptr){
      int counter = 1;
      
      while(end != nullptr && counter < k){
        end = end->ptr;
        counter++;
      }
      
      if(end == nullptr){
        break;
      }
      
      Node* next = end->ptr;
      Node* new_start = reverse(start, end);
      if(prev == nullptr){
        head = new_start;
      } else {
        prev->ptr = new_start;
      }
      
      prev = start;
      
      start = next;
      end = start;
    }
  }
  
};

int main() 
{
  LinkedList l1;
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  l1.create_linked_list(a, 9);
  l1.print_linked_list();
  l1.reverse_k_groups(3);
  l1.print_linked_list();
  printf("\n");
  
  //multiline input as a string
  string input = R"(
3
9
1 2 3 4 5 6 7 8 9
3
8
1 2 3 4 5 6 7 8
3
9
1 2 3 4 5 6 7 8 9
12
)";
  
  stringstream ss(input);
  
  int num_test_cases;
  ss >> num_test_cases;
  
  while(num_test_cases > 0){
    int s1, s2;
    ss >> s1;
    
    int a1[s1];
    for(int i = 0; i < s1; i++){
      ss >> a1[i];
    }
    
    int k;
    ss >> k;
    
    LinkedList l1;
    l1.create_linked_list(a1, s1);
    l1.print_linked_list();
    l1.reverse_k_groups(k);
    l1.print_linked_list();
    printf("\n");
    
    num_test_cases--;
  }

}