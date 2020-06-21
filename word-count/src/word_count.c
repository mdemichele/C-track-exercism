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

  while (str[i] != '\0') {
    
    if(d_is_alpha(str[i])) {
      buffer[i] = str[i];
      i++;
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
			return (-1);
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
  
  while(str[i]) {
    str[i] = tolower(str[i]);
    i++;
  }
  return str;
}

int word_count(const char *input_text, word_count_word_t * words) {
  
  const char *test;
  test = input_text;
  
  char buffer[MAX_WORD_LENGTH + 1];
  //char *endBuffer;
  word_count_word_t *checkWords;
  checkWords = words;
  
  int i = 0;
  int indexTracker = 0;
  int wordLength = 0;
  while (test[i] != '\0') {
    
    if (d_is_alpha(test[i])) {
      wordLength = d_return_next_word_index(buffer, &test[i]);
      // for (int k = 0; buffer[k]; k++) {
      //    buffer[k] = tolower(buffer[k]);
      // }
      d_strlowcase(buffer);
      //printf("%s", buffer);
    //  printf("%d\n", wordLength); 
    
      int checker = indexTracker;
      int checker2 = 0;
      
      while(checker > 0) {
        if (d_strcmp(checkWords->text, buffer) == 0) {
          checkWords->count++;
          //printf("%d", checkWords->count);
          checker2 = 1;
          checker = 0;
        } else {
          //printf("%s", buffer);
          //printf("%d", d_strcmp(checkWords->text, buffer));
          checkWords++;
          checker--;
        }
      }
      
      checker = indexTracker;
      while(checker > 0) {
        checkWords--;
        checker--;
      } 
      
      
      if (checker2 == 0) {
        int j = 0;
        while (j < wordLength) {
          words->text[j] = buffer[j];
          j++; 
        }
      //  printf("%s\n", words->text);
       
        words->count++;
        indexTracker++;
        words++;
      }
     
      i = i + wordLength;
      
     while (wordLength > 0) {
       buffer[wordLength] = '\0';
       wordLength--;
     }  
    } else 
      i++;
    
  }
  
  //printf("%d", indexTracker);
  
  return indexTracker;
}
