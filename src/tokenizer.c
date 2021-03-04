#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  return ((c == ' ' || c == '\t') && c != '\0');
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  return ((c != ' ' && c != '\t') && c != '\0');
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  while(space_char(*str)){ // looks for the first letter of the word in str
    str++; 
  }
  return str;
}
    
/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  while(non_space_char(*word)){ // looks for the space or \0 in word
   word++;
  }
  return word;
}

/* Counts the number of words in the string argument. */
int  count_words(char *str){
  int wcount = 0;
  char *pstr = str;
    
  while (*pstr){
    pstr = word_start(pstr); // points to the first word in char
    pstr = word_terminator(pstr); // and checks if its null
    wcount++;
  }
  return wcount;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *cpstr = (char *)malloc((len+1) * (sizeof(char))); // creates the space for the copy of instr
  for(int i = 0; i < len; i++){
    cpstr[i] = inStr[i];
  }
  cpstr[len] = '\0';
  return cpstr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  int wc = count_words(str);
  char **strtoken = (char **)malloc((wc+1) * sizeof(char *));
  
  for(int i = 0; i < wc; i++){
    str = word_start(str);
    int L = word_terminator(str) - word_start(str);
    strtoken[i] = copy_str(str, L);
    printf("just tokenized word %s \n", strtoken[i]);
    str = word_start(word_terminator(str));
  }
  strtoken[wc] = 0;
  printf("tokenized 0 %d \n", strtoken[wc]);
  return strtoken;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  while(*tokens != 0){
  printf("token: %s \n", *tokens);
  tokens++;
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  //char **temp = tokens; 
  //int i = 0;
  while(*tokens != 0){
    free(*tokens);
    // printf("free %s \n",*tokens);
    tokens++;
  }
  free(tokens);
} 
