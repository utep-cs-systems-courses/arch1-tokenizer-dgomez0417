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
  Item *newnode = malloc(sizeof(Item)); // create a new node
  if(list->root == NULL){ // if the list is empty
    newnode->id = 1; // then it gives the newnode number 1
    newnode->str = str; // enters the string
    list->root = newnode; // and points to null
  }
  else{ // the list is not empty
    int countId = 2; // starts the count at 2
    Item *temp = list->root;
    while(temp->next != NULL){ // traverse the list
      temp = temp->next; // moves on to the next node
      countId++; // increments on count id
    }
    newnode->id = countId; // the new node get the current count
    newnode->str = str; // and the string
    temp->next = newnode; // and points to null
  }   
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *temp = list->root;
  char *str;
  
  // printf("Entering while loop");
  while(temp != NULL){ // Traverse till the end of the list
    if(temp->id == id){ // if the id in the node equals the node requested
      str = temp->str; // then it places that string in str
      // printf("%s \n", str);
      return str; // and returns it
    } 
    temp = temp->next;// moves on to the next node
  }
  return 0; // return null if not found
}

/*Print the entire contents of the list. */
void print_history(List *list){
  Item * temp = list->root;
  while(temp != NULL){ // traverse till the end of the list
    printf("%d. %s \n", temp->id, temp->str); // prints the id and str inside the node
    temp = temp->next; // moves one to the next node
  }
}
  
/*Free the history list and the strings it references. */
void free_history(List *list){
  Item * temp = list->root;
  while(temp != NULL){ // traverse till the end of the list
    free(temp); // free node
    temp = temp->next; // moves one to the next node
  }
}
