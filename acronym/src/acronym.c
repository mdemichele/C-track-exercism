#include "acronym.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *abbreviate(const char *phrase)
{
  int wordCount = 1;
  int i;
  int j;

 // Check if phrase is empty
  if (phrase == NULL || strlen(phrase) == 0)
    return NULL;

 // Get the word count of the phrase
  i = 0;
  while (phrase[i])
  {
    if (phrase[i] == ' ')
      wordCount++;
    i++;
  }

  // Allocate the correct amount of memory space for abbreviation[]
  char *abbreviation = (char *) malloc(wordCount * sizeof(char) + 1);

  // Fill abbreviation with the capitalized first letter of each word
  i = 0;
  j = 1;
  while (phrase[i])
  {
    abbreviation[0] = toupper(phrase[0]);

    if (phrase[i] == ' ' || phrase[i] == '-')
    {
      abbreviation[j] = toupper(phrase[i + 1]);
      j++;
    }

    i++;
  }

  abbreviation[j] = '\0';
  // Return abbrevation[], which should contain the abbreviated phrase
  return (abbreviation);
}
