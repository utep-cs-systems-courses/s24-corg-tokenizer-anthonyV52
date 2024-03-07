#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history(){
  List *list = malloc(sizeof(List));
  list->root = (Item*)malloc(sizeof(Item));
  return list;
}

void add_history(List *list, char *str){
  int id = 1; // used to keep track of items ins list
  Item *tmp = list->root;

  //loops until the next element of the loop is null using id to keep
  //track of how many items in the list
  while(tmp->next != NULL){
    tmp = tmp->next;
    id++;
  }
  //memory allocation for the next item
  tmp->next = malloc(sizeof(Item));
  tmp->id = id;
  tmp->str = str;

}
char *get_history(List *list, int id){
  if(!list){
    return '\0';
  }
  else{
    for(Item *tmp = list->root; tmp; tmp = tmp->next){
      if(tmp->id == id){
	return tmp->str;
      }
    }
    return '\0';
  }
}

void print_history(List *list){
  if(!list){
    printf("history is empty, enter an input.\n");
  }
  else{
    Item *tmp =list->root;
    while (tmp){
      char *word = get_history(list, tmp->id);
      if (word){
	printf("%d: %s\n", tmp->id, word);
      }
      tmp = tmp->next;
    }
    printf("\n");
  }
}
void free_history(List *list){
  Item *tmp;
  for(Item *head = list->root; head; head = head->next){
    tmp = head;
    free(tmp);
  }
}

