#include <iostream>
#include <sstream>
using namespace std;
/*
Given a linked list addition
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
  
  void insert(int data){
    Node* node = new Node(data);
    
    if(head == nullptr){
      head = node;
      return;
    }
    
    Node* temp = head;
    
    while(temp->ptr != nullptr){
      temp = temp->ptr;
    }
    
    temp->ptr = node;
  }
  
};

LinkedList add_numbers(LinkedList* l1, LinkedList* l2){
    Node* num1 = l1->head;
    Node* num2 = l2->head;
    LinkedList result;
    int carry = 0;
    
    while(num1 != nullptr || num2 != nullptr || carry>0){
      int sum = carry;
      
      if(num1 != nullptr){
        sum += num1->data;
        num1 = num1->ptr;
      }
      
      if(num2 != nullptr){
        sum += num2->data;
        num2 = num2->ptr;
      }
      
      result.insert(sum % 10);
      carry = sum/10;
    }
    
    return result;
  }

int main() 
{
  LinkedList* l1 = new LinkedList();
  LinkedList* l2 = new LinkedList();
  LinkedList result;
  int a[] = {1, 2, 3};
  int b[] = {6, 4, 1};
  l1->create_linked_list(a, 3);
  l1->print_linked_list();
  l2->create_linked_list(b, 3);
  l2->print_linked_list();
  result = add_numbers(l1, l2);
  result.print_linked_list();
  printf("\n");
  
  //multiline input as a string
  string input = R"(
4
3 3
3 4 9
1 0 1
1 4
3
1 2 3 4
3 3
3 4 5
8 0 1
1 2
3
3 4
)";
  
  stringstream ss(input);
  
  int num_test_cases;
  ss >> num_test_cases;
  
  while(num_test_cases > 0){
    int s1, s2;
    ss >> s1;
    ss >> s2;
    
    int a1[s1];
    for(int i = 0; i < s1; i++){
      ss >> a1[i];
    }
    
    int a2[s2];
    for(int i = 0; i < s2; i++){
      ss >> a2[i];
    }
    
    LinkedList* l1 = new LinkedList();
    LinkedList* l2 = new LinkedList();
    LinkedList result;
    l1->create_linked_list(a1, s1);
    l1->print_linked_list();
    l2->create_linked_list(a2, s2);
    l2->print_linked_list();
    result = add_numbers(l1, l2);
    result.print_linked_list();
    printf("\n");
    
    num_test_cases--;
  }

}