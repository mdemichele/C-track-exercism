#include "gigasecond.h"

time_t gigasecond_after(time_t date)
{
  time_t gigasecond = 1000000000;
  time_t gigasecond_moment = date + gigasecond;

  return gigasecond_moment;
}
