import java.util.*;

/*
Given a string with the just the six characters -
‘(’, ‘)’, ‘{’, ‘}’, ‘[’ and ‘]’. Determine if the string is
balanced.
A string is balanced if all brackets exist in pairs 
and are closed in the correct order.
*/

public class Main {
    public static boolean check_paranthesis(String input){
      char[] stack = new char[50];
      int top = -1;
      
      for(char c : input.toCharArray()){
        if(c == '(' || c == '{' || c == '['){
          stack[++top] = c;
        } else {
          
          if(top == -1){
            return false;
          }
          
          if((c == ']' && stack[top] != '[') ||
            (c == '}' && stack[top] != '{') ||
            (c == ')' && stack[top] != '(')){
              return false;
            }
            
          top--;
        }
      }
      
      if(top == -1){
        return true;
      } else {
        return false;
      }
    }
    
    public static void main(String[] args) {
      String expression = "{[]}(){";
      
      if(check_paranthesis(expression)){
        System.out.println("Balanced");
      } else {
        System.out.println("Unbalanced");
      }
  }
}