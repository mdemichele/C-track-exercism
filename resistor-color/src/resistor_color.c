#include "resistor_color.h"
#include <stdio.h>


static resistor_band_t bands[] = {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};

resistor_band_t color_code(resistor_band_t x)
{
  return bands[x];
}

resistor_band_t *colors(void)
{
  return bands;
}

