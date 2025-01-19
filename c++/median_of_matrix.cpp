#include <iostream>
#include <sstream>
using namespace std;
// median of row sorted n*m matrix

int matrix_median(int matrix[][100], int n, int m){
  int low = matrix[0][0], high = 0;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(matrix[i][j] < low){
        low = matrix[i][j];
      }
      if(matrix[i][j] > high){
        high = matrix[i][j];
      }
    }
  }
  
  int desired_pos = (n*m) / 2 + 1;
  
  while(low < high){
    int mid = (low + high) / 2;
    int count = 0;
    
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(matrix[i][j] <= mid){
          count++;
        }
      }
    }
    
    if(count < desired_pos){
      low = mid + 1;
    }
    else {
      high = mid;
    }
  }
  
  return low;
}
int main() 
{
  int matrix[100][100] = {{1, 2, 3}, {3, 3, 4}, {1, 1, 2}};
  
  int return_value = matrix_median(matrix, 3, 3);
  
  printf("%d\n", return_value);
  
  //multiline input as a string
  string input = R"(
3
3 3
1 2 3
3 3 4
1 1 2
3 3
1 2 3
4 5 6
7 8 9
3 5
1 6 7 7 8
2 2 3 3 4
1 2 2 2 2
)";
  
  stringstream ss(input);
  
  int num_test_cases;
  ss >> num_test_cases;
  
  while(num_test_cases > 0){
    int n, m;
    ss >> n;
    ss >> m;
    
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        ss >> matrix[i][j];
      }
    }
    
    return_value = matrix_median(matrix, n, m);
    
    printf("%d\n", return_value);
    
    num_test_cases--;
  }
  
}