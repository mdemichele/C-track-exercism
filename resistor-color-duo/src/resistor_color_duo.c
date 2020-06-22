#include "resistor_color_duo.h"
#include <stdio.h>


resistor_band_t color_code(resistor_band_t *colors) {
  
  resistor_band_t c1 = colors[0];
  resistor_band_t c2 = colors[1];
  
  resistor_band_t result = (c1 * 10) + c2;


  return (result);
}


