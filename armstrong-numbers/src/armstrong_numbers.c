#include "armstrong_numbers.h"
#include <stdlib.h>

int isArmstrongNumber(int n) 
{
  
  int sum = 0;
  int numDigits = 1;
  int count = n;
  int digitCount;
  
  // Test for zero, and single digits 
  if (n == 0 || n < 10) {
    return 1;
  }
  
  // Find the Number of digits
  while (count > 0) {
    
    if (count < 10) {
      count = 0; 
    }
    else if (count > 10) {
      numDigits = numDigits + 1;
      count = count / 10; 
    }
  }
  
  // Break number into its digits 
  int *digits = (int *) malloc(numDigits * sizeof(int) + 1);
  
  count = n;
  digitCount = numDigits - 1;
  
  while (count > 0) {
    
    if (count < 10) {
      digits[0] = count;
      count = 0;
    } else if (count > 10) {
      digits[digitCount] = (count % 10);
      digitCount--;
      count = count / 10;
    }
  }
  
  // Find sum
  int i = 0; 
  while (digits[i] != '\0') {
    sum = sum + (digits[i] * numDigits);
    i++;
  }
  
  if (sum == n) 
    return 1;
  else
    return 0;
}
