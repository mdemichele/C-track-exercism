#include "space_age.h"
#include <stdio.h>

float convert_planet_age(planet_t planet, int64_t input)
{
  double earthYears;
  long double convert;
  long double planetYears;
  
  earthYears = (double) input / 31557600;
  
  convert = (long double) planet / 10000000;
  
  planetYears = earthYears / convert;
  
  return planetYears;
}
