#include <stdio.h>
#include "tokenizer.h"

int main()
{
  char input[100];

  printf("$");
  fgets(input, 100, stdin);
  puts(input);

  printf("%d \n",space_char(input[1]));
  printf("%d \n",non_space_char(input[1]));
  printf("%d \n", count_words(input));
}

