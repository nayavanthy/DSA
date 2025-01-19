#include <stdio.h>
#include <string.h>
/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Explanation:
The strings s and t can be made identical by:
Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:
Input: s = "foo", t = "bar"
Output: false

Explanation:
The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:
Input: s = "paper", t = "title"
Output: true
*/

int check_isomorphic(char *s, char *t){
  int hash_s[26] = {0}, hash_t[26] = {0};
  
  for(int i=0; i<strlen(s); i++){
    hash_s[(int)s[i]-(int)'a']++;
  }
  for(int i=0; i<strlen(t); i++){
    hash_t[(int)t[i]-(int)'a']++;
  }
  
  for(int i=0; i<26;i++){
    if(hash_s[i]!=0){
      for(int j=0; j<26; j++){
        if(hash_s[i]==hash_t[j]){
          hash_t[j]=0;
          break;
        }
        if(j==25){
          return 0;
        }
      }
    }
  }
  
  return 1;
}

int main()
{
  char s[] = "paper";
  char t[] = "title";
  
  int ret = check_isomorphic(s, t);
  
  if(ret ==1)
    printf("given strings are isomorphic");
  else
    printf("given strings are not isomorphic");
}