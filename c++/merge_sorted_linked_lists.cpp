#include <iostream>
#include <sstream>
using namespace std;
/*
Given 2 sorted linkedlists, merge them
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
  
  void merge_linked_lists(LinkedList* ll){
    Node* curr1 = head;
    Node* curr2 = ll->head;
    
    Node* index;
    if(curr1->data < curr2->data){
      index = curr1;
      curr1 = curr1->ptr;
    } else {
      index = curr2;
      curr2 = curr2->ptr;
    }
    
    head = index;
    
    while(curr1 != nullptr && curr2 != nullptr){
      if(curr1->data < curr2->data){
        index->ptr = curr1;
        curr1 = curr1->ptr;
      } else {
        index->ptr = curr2;
        curr2 = curr2->ptr;
      }
      index = index->ptr;
    }
    
    if(curr1 != nullptr){
      index->ptr = curr1;
    }
    
    if(curr2 != nullptr){
      index->ptr = curr2;
    }
  }
};

int main() 
{
  LinkedList ll;
  int a[] = {1, 2, 3, 4, 5};
  ll.create_linked_list(a, 5);
  int b[] = {3, 4, 5};
  LinkedList* ll2 = new LinkedList();
  ll2->create_linked_list(b, 3);
  ll.print_linked_list();
  ll.merge_linked_lists(ll2);
  ll.print_linked_list();
  
  //multiline input as a string
  string input = R"(
2
3 4
1 2 3
2 2 4 5
3 3
2 3 3
1 4 5
)";
  
  stringstream ss(input);
  
  int num_test_cases;
  ss >> num_test_cases;
  
  while(num_test_cases > 0){
    int size_a;
    ss >> size_a;
    int size_b;
    ss >> size_b;
    
    int arr_a[size_a];
    for(int i = 0; i < size_a; i++){
      ss >> arr_a[i];
    }
    
    int arr_b[size_b];
    for(int i = 0; i < size_b; i++){
      ss >> arr_b[i];
    }
    
    LinkedList ll;
    LinkedList* ll_b = new LinkedList();
    ll.create_linked_list(arr_a, size_a);
    ll.print_linked_list();
    ll_b->create_linked_list(arr_b, size_b);
    ll.merge_linked_lists(ll_b);
    ll.print_linked_list();
    num_test_cases--;
  }

}