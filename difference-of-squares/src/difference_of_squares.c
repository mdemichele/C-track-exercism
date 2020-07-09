#include "difference_of_squares.h"


unsigned int sum_of_squares(unsigned int number) {
  unsigned int summed = 0;
  
  for (unsigned int i = 1; i <= number; i++) {
    summed = summed + (i * i);
  }
  
  return summed;
}

unsigned int square_of_sum(unsigned int number) {
  unsigned int summed = 0;
  
  for (unsigned int i = 1; i <= number; i++) {
    summed = summed + i;
  }
  
  return summed * summed;
}

unsigned int difference_of_squares(unsigned int number) {
  unsigned int difference = 0;
  
  difference = square_of_sum(number) - sum_of_squares(number);
  
  return difference;
}
