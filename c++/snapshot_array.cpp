#include <iostream>
using namespace std;

/*
Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length. Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id
 

Example 1:

Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation: 
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5
*/

class SnapshotArray{
  public:
  int *arr;
  int **memory;
  int length;
  int snap_id;
  SnapshotArray(int length){
    this->length = length;
    arr = new int[length];
    for(int i=0; i<length; i++){
      arr[i] = 0;
    }
    
    memory = new int*[100]; //assume maximum of 100 snapshots
    
    snap_id = 0;
  }
  
  void set(int index, int val){
    arr[index]= val;
  }
  
  int snap(){
    memory[snap_id]= new int[length];
    for (int i = 0; i < length; i++) {
      memory[snap_id][i] = arr[i];  // Copy the current array state into memory
    }
    snap_id++;
    
    return snap_id - 1; 
  }
  
  int get(int index, int snap_id){
    return memory[snap_id][index];
  }
};

int main() 
{
  SnapshotArray snapshotArr(3);  // Initialize SnapshotArray with length 3
  snapshotArr.set(0, 5);         // Set arr[0] = 5
  cout << snapshotArr.snap() << endl; // Take a snapshot, returns snap_id 0
  snapshotArr.set(0, 6);         // Set arr[0] = 6
  cout << snapshotArr.get(0, 0) << endl; // Get the value of arr[0] at snap_id 0, should return 5
  return 0;
}