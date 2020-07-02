#include "matching_brackets.h"
#include <stdio.h>
#include <stdlib.h>

bool is_paired(const char *input) {

  char *stack = malloc(sizeof(input));
  int stackCount = 0;
  char check;


  for (int i = 0; input[i]; i++) {
  
   // if current index is opening parenthesis, push to stack 
   if (input[i] == '{' || input[i] == '[' || input[i] == '(') {
     stack[stackCount] = input[i];
     stackCount++;
   }
   
   // if current index is closing parenthesis, pull from stack. if pulled doesn't match closing then 0 else continue
   if (input[i] == '}') {
     check = stack[stackCount - 1];
    
    if (check != '{') {
       return 0;
     } else {
      stackCount--;
      continue;
     }
   }
  
   if (input[i] == ']') {
    check = stack[stackCount - 1];
    
    if (check != '[') {
      return 0;
    } else {
      stackCount--;
      continue;
    }
  }
  
    if (input[i] == ')') {
      check = stack[stackCount - 1];
    
      if (check != '(') {
        return 0;
    } else {
      stackCount--;
      continue;
      }
    }
  
  }
  
  // If still stuff in stack return 0
  if (stackCount != 0)
    return 0;
    
return 1;
  
}










