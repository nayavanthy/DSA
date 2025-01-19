#include <stdio.h> 
#include <string.h>

/*
Take input of a string and check if all letters in the alphabet exist within the String
Output:- Change the input string to true or false
assume:- string only consists of characters from a-z
*/

void check_for_all_letters(char * str) {
  //Create a hash table for 26 characters of the alphabet
  int hash[26]= {0};
  int len = strlen(str);
  
  // Increment hash for each alphabet character in the string
  for(int i=0; i<len; i++){
    hash[(int)str[i]- (int)'a']++;
  }
  
  //check if any hash is 0, i.e. letter doesn't exist in string
  for(int i= 0; i<26; i++){
    if(hash[i]==0){
      strcpy(str, "False");
      return;
    }
  }
  
  strcpy(str, "True");
  return;
}

int main(void) { 
  char str[] = "abcdefghijklmnopqrstuvwxyz";
  check_for_all_letters(str);
  printf("%s", str);
  return 0;
    
}