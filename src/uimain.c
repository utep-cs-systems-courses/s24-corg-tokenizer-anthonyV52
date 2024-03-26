#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main(){
  int i;
  List *history =  init_history();
  int num;
  char *strHistory;
  fputs("$ ", stdout);
  fflush(stdout);
  char input[100];
  char *p = input;
  printf("Enter one of the following characters to start:\n");
  while (1){
    printf("Enter 's' to type and save sentences\n Enter'!h' to display all saved sentences\n Enter '! #' to display certain sentences\n");
    printf("^ ");
    fgets(input, sizeof(input), stdin);
    if(input[0] == 's'){
      printf("Please enter your sentence:\n$ ");

      fgets(input, sizeof(input), stdin);

      char **tokens = tokenize(input);

      printf("\n");

      print_tokens(tokens);
      add_history(history, input);
      free_tokens(tokens);
      
    } else if (input[0] == '!' && input[1] == 'h') {

      print_history(history);

    } else if (input[0] == '!') {

      int id = atoi(input + 1);

      if (id == 0 || (input[1] == 'h' && input[2] == '\0')) {

	print_history(history);

      } else {

	char *strHistory = get_history(history, id);

	if (*strHistory != '\0') {

	  printf("%s", strHistory);

	}

      }

    } else {

      printf("Sorry, that was not a valid option please try again.\n");

    }

  }



  free_history(history);
  return 0;
}
