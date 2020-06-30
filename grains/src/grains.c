#include "grains.h"
#include <stdio.h>

uint64_t square(uint8_t index) 
{
  if (index <= 1)
    return index;
  else 
    return 2 * square(index - 1);  
}

uint64_t total(void) 
{
  int16_t sum = 1;
  int16_t grainCounter = 1;
  for (int16_t i = 1; i < 65; i++) 
  {
    grainCounter = grainCounter * 2;
    sum = sum + grainCounter;
  }
  return sum;
}

