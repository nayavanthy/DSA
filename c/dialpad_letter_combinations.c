#include <stdio.h>
#include <string.h>
/*
Given a string containing digits from 2-9 inclusive, return 
all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) 
is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

int main()
{
  char* map[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  
  char digits[] = "23";
  int size = strlen(digits);
  int* array_digits = malloc(sizeof(int) * size);
  
  for(int i = 0; digits[i] != 0; i++){
    array_digits[i] = (int)digits[i] - (int)'0';
  }
  
  char* queue[1000];
  queue[0] = "";
  
  int front = 0, rear = 1;
  
  while(front < rear){
    char* s = queue[front++];
    if(strlen(s) == size){
      printf("%s ", s);
      continue;
    }
    
    int num = array_digits[strlen(s)];
    char* chars = map[num];
    
    for(int i = 0; chars[i] != '\0'; i++){
      char* newstr = malloc(strlen(s)+2);
      strcpy(newstr, s);
      newstr[strlen(s)] = chars[i];
      newstr[strlen(s) + 1] = '\0';
      queue[rear++] = newstr;
    }
  }
}
