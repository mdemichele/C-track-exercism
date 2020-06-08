#include "isogram.h"
#include <stdlib.h>
#include <ctype.h>

bool is_isogram(const char phrase[])
{
  int i;
  bool alphabet[26] = {0};
  int letter;

  // check if phrase is empty
  if (phrase == NULL)
    return false;

  // check for isogram
  i = 0;
  while (phrase[i])
  {
    if(isalpha(phrase[i])) // Only check index if it's a letter;
    {
      letter = tolower(phrase[i]) - 'a'; // Get the correct letter index

      if(alphabet[letter]) // If that letter is in the phrase already, it's not an isogram
        return false;
      else
        alphabet[letter] = true; // Note that the letter has been found in the phrase
    }

    i++;
  }
  return true;
}
