#include <stdio.h>
#include <stdlib.h>
/*
Given a sorted dictionary of an alien language having some words dict and k starting alphabets of a standard dictionary. Find the order of characters in the alien language. If no valid ordering of letters is possible, then return an empty string.

Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be "true" if the order of string returned by the function is correct else "false" denotes incorrect string returned.

Examples:

Input: dict = ["baa","abcd","abca","cab","cad"], k = 4
Output: true
Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Input: dict = ["dhhid" "dahi" "cedg" "fg" "gdah" "i" "gbdei" "hbgf" "e" "ddde"], k = 9 
Output: false

*/

void add_edge(int **arr, char a, char b){
  arr[a - 'a'][b - 'a'] = 1;
}

int dfs(int node, int *visited, int *recstack, int **arr, int k, char *out, int *index){
  visited[node] = 1;
  recstack[node] = 1;
  
  for(int i = 0; i < k; i++){
    if(arr[node][i] == 1){
      if((visited[i] == 0) && (dfs(i, visited, recstack, arr, k, out, index) == 1))
        return 1;
      else if(recstack[i] == 1)
        return 1;
    }
  }
  
  recstack[node] = 0;
  out[*index] = node + 'a';
  (*index)--;
  return 0;
}

int topological_sort(int **arr, int k, char *out){
  int visited[26] = {0};
  int recstack[26] = {0};
  int index = k-1;
  
  for(int i = 0; i < k; i++){
    if(visited[i] == 0){
      if(dfs(i, visited, recstack, arr, k, out, &index) == 1){
        return 0;
      }
    }
  }
  
  return 1;
}

void print_order(char **arr, int size,  int k){
  int **adj = (int **)malloc(k * sizeof(int *));
  for (int i = 0; i < k; i++) {
    adj[i] = (int *)malloc(k * sizeof(int));
    for(int j = 0; j < k; j++){
      adj[i][k] = 0;
    } 
  }
  
  for(int i = 0; i < size-1; i++){
    
    int j = 0;
    while(arr[i][j] != '\0' && arr[i+1][j] != '\0'){
      
      if(arr[i][j] != arr[i+1][j]){
        add_edge(adj, arr[i][j], arr[i+1][j]);
         
        break;
      }
      
      j++;
    }
  }
  
  char ret[k];
  
  if(topological_sort(adj, k, ret)){
    ret[k] = '\0';
    printf("Valid order: %s\n", ret);
  } else {
    printf("No valid order possible\n");
  }

  for (int i = 0; i < k; i++) {
    free(adj[i]);
  }
  free(adj);
}
int main()
{
  int k = 4;
  char *words[] = {"baa","abcd","abca","cab","cad"};
  int size = sizeof(words) / sizeof(words[0]);
  
  print_order(words, size, k);
  
  return 0;
}