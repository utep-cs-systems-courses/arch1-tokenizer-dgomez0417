#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  while((c = getchar()) != EOF)
    if (c == ' ' || c == '\t')
      return 1;
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
   while((c = getchar()) != EOF)
    if (c == ' ' || c == '\t')
      return 0;
  return 1;
}
