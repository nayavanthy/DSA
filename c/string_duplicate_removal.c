#include <stdio.h>
#include<string.h>
/*
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  
The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
*/

void remove_adjacent_duplicates(char *s, char *out){
  char stack[strlen(s)];
  int top=-1;
  for(int i=0; s[i]!='\0'; i++){
    if(top>=0 && stack[top]==s[i])
      top--;
    else{
      top++;
      stack[top]= s[i];
    }
  }
  
  for(int i=0; i<=top; i++){
    out[i] = stack[i];
  }
  
  out[top+1]='\0';
  
  return;
}
int main()
{
  char s[] = "abbaca";
  char ret[strlen(s)];
  remove_adjacent_duplicates(s, ret);
  
  printf("%s", ret);
}