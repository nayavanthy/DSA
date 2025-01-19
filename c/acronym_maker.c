#include <stdio.h>
#include <string.h>

/*
Create acronym for a word which is count of letter followed by letter for a string containing multiple repeating letters
eg:- wwwggtffu -> 3w2g1t2f1u
*/

void make_acronym(char *str) {
  char ret[50];
  int count, ret_idx=0;
  int i;
  
  //iterate through the string
  for(i=0; str[i]!='\0'; i++){
    if(str[i-1]!=str[i] || i==0){
      // when new character is detected, update return string with the count of the prev char
      if(i!=0){
        ret[ret_idx]= ((char)((int)'0'+count));
        ret[ret_idx+1]= (str[i-1]);
        ret_idx +=2;
      }
      count =1;
    }
    else{
      count++;
    }
  }

  ret[ret_idx]= ((char)((int)'0'+count));
  ret[ret_idx+1]= (str[i-1]);
  ret_idx +=2;
  
  ret[ret_idx] = '\0';
  
  strcpy(str, ret);
  return;
}

int main(void) { 
  char str[] = "wwwggtffu";
  make_acronym(str);
  printf("%s", str);
  return 0;
}