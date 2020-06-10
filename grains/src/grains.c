#include "grains.h"
#include <stdio.h>

uint64_t square(uint8_t index) 
{
  // Check index is not 0
  if (index == 0) 
  {
    return 0;
  }
  long grains = 1;
  for (long i = 1; i < index; i++) 
  {
    grains = grains * 2;
  }
  return grains;
}

uint64_t total(void) 
{
  long sum = 1;
  long grainCounter = 1;
  for (long i = 1; i < 65; i++) 
  {
    grainCounter = grainCounter * 2;
    sum = sum + grainCounter;
  }
  return sum;
}

