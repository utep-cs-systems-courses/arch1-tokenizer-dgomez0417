#include <stdio.h>
#include <stdlib.h>
#include "history.h"


/* Initialize the linked list to keep the history. */
List* init_history(){
  List *ll = malloc(sizeof(List));
  return ll;
}
/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  char *clone;
  Item *newnode = malloc(sizeof(Item));
  if(list->root == NULL){
    newnode->id = 1;
    newnode->str = str;
    list->root = newnode;
  }
  else{
    int countId = 2;
    Item *temp = list->root;
    while(temp->next != NULL){
      temp = temp->next;
      countId++;
    }
    newnode->id = countId;
    newnode->str = str;
    temp->next = newnode;
  }   
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *temp = list->root;
  char *str;

  while(temp != NULL){
    if(temp->id == id){
      str = temp->str;
    }
    temp = temp->next;
  }
  return str;
}

/*Print the entire contents of the list. */
void print_history(List *list){
  Item * temp = list->root;
  while(temp->next != 0){
    printf("%d. %s", temp->id, temp->str);
    temp = temp->next;
  }
}
  
/*Free the history list and the strings it references. */
void free_history(List *list){
  //Item * temp = list->root;
  //while(temp->next != 0){
    //free(temp->id, temp->str);
    //temp = temp->next;
}
