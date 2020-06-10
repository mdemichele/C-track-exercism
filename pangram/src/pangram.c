#include "pangram.h"
#include <stdio.h>

bool is_pangram(const char *sentence)
{
  int i = 0;
  int alpha = 65;
  
  // Test NULL sentence
  if (sentence == 0) 
  {
    return 0;
  }
  
  // Test pangram 
  while (sentence[i])
  {
    if(alpha == sentence[i] || alpha + 32 == sentence[i])
    {
      alpha++;
      i = 0;
    }
    else 
    {
      i++;
    }
  }
  
  if (alpha == 91)
  {
    return 1;
  }
  
  return 0;
}
