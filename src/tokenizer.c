#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


#define in 1 /*inside the word*/
#define out 0 /*outsid the word*/


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  return (c == ' ' || c == '\t' && c != '\0');
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  return (c != ' ' || c != '\t' && c != '\0');
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  while( *str ){
    if(space_char(*str) == 1){ /*is space at the start of the array*/
      str++; /*then youll move on to the next one*/
    }
    else if(*str=='\0'){ /*the string is empty*/
      return *str;
    }
    else{
      return *str;
    }
  }
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word);



/* Counts the number of words in the string argument. */
int  count_words(char *str){
  int wcount = 0;
  int state = out;
  
  while (*str){
    if (*str == ' ' || *str == '\n' || *str == '\t')
      state = out;
    else if (state == out){
      state = in;
      ++wcount;
    }
    ++str;
  }
  return wcount;
   
}


/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len);

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);
 
