#include "armstrong_numbers.h"
#include <stdlib.h>
#include <math.h>

int isArmstrongNumber(int n) 
{
  // Test for single digits 
  if (n < 10) { return 1; }
  
  // Get number of digits 
  int digitCounter = 2; 
  for (int num = n; num > 100; num = num / 10 ) {
    digitCounter++;
  }
  
  // Find sum of digits raised to the power of number of digits 
  int sum = 0;
  for (int num = n; num > 0; num = num / 10) {
    int digit = num % 10;
    sum = sum + pow(digit, digitCounter);
  }
  
  // Check if result is armstrong number 
  return sum == n;
  
}
