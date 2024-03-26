#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"
#include "tokenizer.h"
List *init_history(){
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));
  return list;
}

void add_history(List *list, char *str){
  int id = 1; // used to keep track of items ins list
  Item *tmp = list->root;

  //loops until the next element of the loop is null using id to keep
  //track of how many items in the list
  while(tmp->next != 0){
    tmp = tmp->next;
    id++;
  }
  //memory allocation for the next item
  tmp->next = malloc(sizeof(Item));
  tmp->next->id = id;
  tmp->next->str = strdup(str);

}
char *get_history(List *list, int id){
  Item *tmp;
  if(!list){
    return '\0';
  }
  else{
    tmp = list->root;
    for(Item *tmp = list->root; tmp != NULL; tmp = tmp->next){
      if(tmp->id == id){
	return tmp->str;
      }
    }
    printf("History item with id = %d not found.\n", id);

    return '\0';//indicates no history item found
  }
}

void print_history(List *list){
  if(!list){
    printf("history is empty, enter an input.\n");
  }
  else{
    Item *tmp =list->root;
    while (tmp!=0){
      char *word = get_history(list, tmp->id);
      printf("%d: %s\n", tmp->id, tmp->str);
      tmp = tmp->next;
    }
    printf("\n");
  }
}
void free_history(List *list){
  Item *tmp;
  Item *next;
  for(tmp = list->root; tmp != NULL ; tmp = next){
    next = tmp->next;
    free(tmp->str);
    free(tmp);
  }
  free(list);
}
 int string_length(char *str){
   int length = 0;
   for(int i= 0; *(str+i) != '\0'; i++){
     length +=1;
   }
   return length;
 }
