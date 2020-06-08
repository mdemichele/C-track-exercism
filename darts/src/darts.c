#include "darts.h"

int score(coordinate_t point) 
{
  // set up Pythagorean theorem checkers 
  float hypotenuseOuter = 100.0;
  float hypotenuseMiddle = 25.0;
  float hypotenuseInner = 1.0;
  float pythagChecker = (point.x * point.x) + (point.y * point.y);
  
  // Check if missed target
  if (pythagChecker > hypotenuseOuter) {
    return 0;
  }
  
  // Check if hit outer circle (is distance from center greater than 5 but less than 10?)
  if (pythagChecker > hypotenuseMiddle) 
  {
    return 1;
  }
  
  // Check if hit middle circle (is distance from center greater than 1 but less than 5?)
  if (pythagChecker > hypotenuseInner) 
  {
    return 5;
  }
  
  // Check if hit inner circle (is distance from center less than 1?)
  if (pythagChecker <= hypotenuseInner) {
    return 10;
  }
  
  
  
  return 0;
}
