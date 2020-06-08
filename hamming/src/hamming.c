#include <stdlib.h>

int compute(char *str1, char *str2) 
{
  int count1;
  int count2;
  int i;
  int ham;
  
  // Check for NULL strings 
  if (str1 == NULL || str2 == NULL)
  { 
    return -1;
  } 
  
  // Check string lengths 
  count1 = 0;
  count2 = 0;
  i = 0;
  
  while (str1[i])
  {
    count1++;
    i++;
  }
  
  i = 0;
  
  while (str2[i]) 
  {
    count2++;
    i++;
  }
  
  if (count1 != count2) 
  {
    return -1;
  }
  
  // Check Hamming distance 
  i = 0;  
  ham = 0;
  
  while (str1[i]) 
  {
    if (str1[i] == str2[i]) 
    {
      i++;
    } else {
      ham++;
      i++;
    }
  }
  
  return ham;

}
