#include <stdlib.h>
#include <string.h>

int compute(char *str1, char *str2) 
{
  
  // Check for NULL strings 
  if (str1 == NULL || str2 == NULL)
  { 
    return -1;
  } 
  
  // Check string lengths 
  if (strlen(str1) != strlen(str2)) 
  {
    return -1;
  }
  
  // Check Hamming distance
  int ham = 0; 
  for (int i = 0; str1[i]; i++) {  
    if (str1[i] != str2[i]) 
      ham++;
  }
  
  return ham;

}
