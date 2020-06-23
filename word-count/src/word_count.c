#include "word_count.h"
#include <stdio.h>
#include <ctype.h>

// Check if char is alphabetic
int d_is_alpha(char c) {
  if (c == '\0')
    return 0;
  if ( (c > 64 && c < 91) || (c > 96 && c < 123) || (c > 47 && c < 58) || (c == 39) )
    return 1;
      
  return 0;
}

// Return next word index and buffer word 
int  d_return_next_word_index(char *buffer, const char *str) {
  int i = 0;
  int j = 0;

  while (str[i] != '\0') {
    
    if(str[i] == 39 && i == 0) {
      i++;
    }
    
    if(str[i] == 39 && str[i + 1] == 32) {
      i++;
      return i;
    }
    
    if(d_is_alpha(str[i])) {
      buffer[j] = str[i];
      i++;
      j++;
    } else {
      return i;
    }
  }
  return i;
}

// Compare Strings 
int	d_strcmp(char *s1, char *s2)
{
	char *p1;
	char *p2;

	p1 = s1;
	p2 = s2;
	while (*p1 != '\0')
	{
		if (*p2 == '\0')
			return (2);
		if (*p2 > *p1)
			return (4);
		if (*p2 < *p1)
			return (3);
		p1++;
		p2++;
	}
	if (*p2 != '\0')
		return (-1);
	return (0);
}

// Change to lowercase
char	*d_strlowcase(char *str) {
	int i = 0;
  
  while(str[i] != '\0') {
    str[i] = tolower(str[i]);
    i++;
  }
  return str;
}

int word_count(const char *input_text, word_count_word_t * words) {
  
  // Create pointer to input text 
  const char *test;
  test = input_text;
  
  // Create buffer string to hold individual words. Create pointer to words Struct to check words.
  char buffer[MAX_WORD_LENGTH * 2];
  word_count_word_t *checkWords;
  checkWords = words;
  
  // Create variables to keep track of indices 
  int i = 0;
  int indexTracker = 0;
  int wordLength = 0;
  
  // Main loop to cycle through each word 
  while (test[i] != '\0') {
    
    // If there are too many words, exit
    if (indexTracker == MAX_WORDS) {
      return (EXCESSIVE_NUMBER_OF_WORDS);
    }
    
    // Start loop at beginning of each word 
    if (d_is_alpha(test[i])) {
      
      // Get first word. And keep track of word's length 
      wordLength = d_return_next_word_index(buffer, &test[i]);
      
      // If word is too big, exit 
      if (wordLength > MAX_WORD_LENGTH) {
        return (EXCESSIVE_LENGTH_WORD);
      }
      
      // Make the word lowercase
      d_strlowcase(buffer); 
    
      // checker keeps track of how many times to loop through checkWords. checker2 keeps track of if it's a unique word. 
      int checker = indexTracker;
      int checker2 = 0;
      
      // Check if unique word 
      while(checker > 0) {
        if (d_strcmp(checkWords->text, buffer) == 0) {
          checkWords->count++;
          checker2 = 1;
          checkWords++;
          checker--;
        } else {
          checkWords++;
          checker--;
        }
      }
      
      // Reset checker and checkWords pointer 
      checker = indexTracker;
      while(checker > 0) { 
        checkWords--;
        checker--;
      } 
        
      // If unique word, put in words Struct   
      if (checker2 == 0) {
        int j = 0;
        while (j < wordLength) {
          words->text[j] = buffer[j];
          j++; 
        }
       
       // If unique word, make count 1. Increase indexTracker. Move to next index in words Struct 
        words->count++;
        indexTracker++;
        words++;
      }
     
      // Move to next index in input text string to check for next word 
      i = i + wordLength;
      
      // Reset buffer and wordLength 
     while (wordLength > 0) {
       buffer[wordLength] = '\0';
       wordLength--;
     }  
    } else 
      i++;
  }
  
  // Return the count of how many unique words there are 
  return indexTracker;
}
