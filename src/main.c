#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char input[100];

  printf("$");
  fgets(input, 100, stdin);
  puts(input);

  printf("space char: %d \n", space_char(input[1]));
  printf("non space char: %d \n", non_space_char(input[1]));
  //printf("%d \n", word_start(input));
  // printf("%d \n", word_terminator(input));
  printf("word count: %d \n", count_words(input));
  printf("copy of string: %s \n", copy_str(input, 100));
  char **token = tokenize(input);
  print_tokens(token);
  free_tokens(token);

  List *list = (init_history());
  add_history(list, input);
  //printf("%s \n", get_history(list, 2));
  //print_history(list);
  
}

