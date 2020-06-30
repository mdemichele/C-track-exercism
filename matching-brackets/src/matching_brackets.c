#include "matching_brackets.h"
#include <stdio.h>

bool check_pair(const char *str, int index) {
  
  int i = index;
  
  
  // Check for matching brackets 
  if (str[i] == '[') {
    while (str[i]) {
      if (str[i] == ']') {
        return 1;
      } else {
        i++;
      }
    }
    return 0;
  } 
  
  // Check for matching curly brackets 
  if (str[i] == '{') {
    while (str[i]) {
      if (str[i] == '}') {
        return 1;
      } else {
        i++;
      }
    }
    return 0;
  } 
  
  // Check for matching parentheses 
  if (str[i] == '(') {
    while (str[i]) {
      if (str[i] == ')') {
        return 1;
      } else {
        i++;
      }
      return 0;
    }
    return 0;
  } 
    
  // Check for end brackets 
  if (str[i] == ']') {
    while (i >= 0) {
      if (str[i] == '[') {
        return 1;
      } else {
        i--;
      }
    }
    return 0;
  }
    
  // Check for end curly brackets  
  if (str[i] == '}') {
    while (i >= 0) {
      if (str[i] == '{') {
        return 1;
      } else {
        i--;
      }
    }
    return 0;
  }
  
  // Check for end parentheses 
  if (str[i] == ')') {
    while (i >= 0) {
      if (str[i] == '(') {
      return 1;
      } else {
        i--;
      }
    }
    return 0;
  }
  
  return 1;
}

bool is_paired(const char *input) {
  
  const char *str = input;
  bool answer;
  
  for (int i = 0; str[i]; i++) {
      answer = check_pair(str, i);
      if (answer == 0) {
        return answer;
      }
  }
  
  return 1;  
}











