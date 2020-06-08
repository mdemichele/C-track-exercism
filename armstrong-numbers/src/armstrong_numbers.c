#include "armstrong_numbers.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int isArmstrongNumber(int n) 
{
  int number;
  int digitCounter;
  int sum;
  int digit; 
  
  // Test for zero, and single digits 
  if (n == 0 || n < 10) 
  {
    return 1;
  }
  
  // There are no two digit armstrongs, so test for double digits 
  if (n > 9 && n < 100) 
  {
    return 0;
  }
  
  // Get Number of digits  
  number = n;
  digitCounter = 2;
  
  while (number > 100) 
  {
    number = number / 10;
    digitCounter++;
  }
  
  // Find sum of digits raised to the power of number of digits 
  sum = 0;
  number = n;
  digit = 0;
  
  while (number > 0)
  {
    digit = number % 10;
    sum = sum + pow(digit, digitCounter);
    number = number / 10;
  }

  if (sum == n) {
    return 1;
  }
  else {
    return 0;
  }
  
  

  return 0;
}
