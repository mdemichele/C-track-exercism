#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#include <stdint.h>

typedef enum planet {
   MERCURY = 2408467,
   VENUS = 6151972,
   EARTH = 10000000,
   MARS = 18808158,
   JUPITER = 118626150,
   SATURN = 294474980,
   URANUS = 840168460,
   NEPTUNE = 1647913200,
} planet_t;

float convert_planet_age(planet_t planet, int64_t input);

#endif
