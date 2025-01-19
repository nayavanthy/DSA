#include <iostream>
using namespace std;
/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
*/

//doubly linked list to keep track of usage of keys
class Node {
  public:
  int key;
  int value;
  Node* prev;
  Node* next;
  
  Node(int k, int v){
    key= k;
    value= v;
    prev= nullptr;
    next= nullptr;
  }
};

class LRUCache {
  public:
  Node** cache;
  Node* head;
  Node * tail;
  int capacity;
  int size;
  
  void rem(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  
  void add(Node* node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
  }
  
  Node* findNode(int key) {
    Node* current = head->next;
    while (current != tail) {
      if (current->key == key) {
        return current;
      }
      current = current->next;
    }
    return nullptr;  // Key not found
  }
  
  LRUCache(int cap){
    capacity = cap;
    size = 0;
    head = new Node(0,0);
    tail = new Node(0,0);
    head->next=tail;
    tail->prev=head;
    cache = new Node*[capacity]; 
  }
  
  int get(int key){
    Node* node = findNode(key);
    if(node== nullptr)
      return -1;
    
    //move to front of list
    rem(node);
    add(node);
    
    return node->value;
  }
  
  void put(int key, int value){
    Node* node = findNode(key);
    if(node!=nullptr){
      node->value = value;
      rem(node);
      add(node);
    }else{
      if(size==capacity){
        Node* lru = tail->prev;
        rem(lru);
        size--;
      }
      node = new Node(key, value);
      add(node);
      size++;
    }
  }
};

int main() 
{
  LRUCache lRUCache(2);

  lRUCache.put(1, 1);    // cache is {1=1}
  lRUCache.put(2, 2);    // cache is {1=1, 2=2}
  cout << lRUCache.get(1) << endl;    // returns 1
  lRUCache.put(3, 3);    // evicts key 2, cache is {1=1, 3=3}
  cout << lRUCache.get(2) << endl;    // returns -1 (not found)
  lRUCache.put(4, 4);    // evicts key 1, cache is {4=4, 3=3}
  cout << lRUCache.get(1) << endl;    // returns -1 (not found)
  cout << lRUCache.get(3) << endl;    // returns 3
  cout << lRUCache.get(4) << endl;    // returns 4

}