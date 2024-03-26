#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c){
  if(c == ' ' || c == '\t'){
	 return 1;
  }

  return 0;
}

int non_space_char(char c){
  if(c == ' ' || c == '\t'){
    return 0;
  }
  
  return 1;
}

char *token_start(char *str){
  int i = 0;
  if(*str == '\0')
    return NULL;
  while(str[i]){
    if(non_space_char(str[i])){
      return str +i;
    }
	
    i++;
  }
    
  return str+i;
}

//this method will return a pointer to the null character indicating that the string has finished
char *token_terminator(char *token){
  token_start(token);
  int i = 0;
  while(token[i]!= '\0'){
    if(token[i] == '\0'|| space_char(token[i])){
      return token + i;
    }
    i++;
    }
  return token + i;
}

int count_tokens(char *str){
  int count = 0;
  int i;
  char *tmp = token_start(str);
  while(*tmp){
    count++;
    tmp = token_start(tmp);
    tmp = token_terminator(tmp);
    }
  return count;

             }

char *copy_str(char *inStr, short len){
  short i;
  if(inStr == NULL)
    return NULL;

  char *outStr = malloc((len + 1)* sizeof(char));

  for(i = 0; i < len; i++){
    outStr[i] = inStr[i];
  }
  outStr[i] = '\0';
  printf("%d\n",outStr[i]);
  return outStr;
}

char **tokenize(char *str){
  int count = count_tokens(str);
  char **tokens = malloc((count + 1) * sizeof(char *));
  int i;
  int token_count;
  char *p = str;
  for(i = 0;i < count;i++){
    p = token_start(p);
    char *token_end = token_terminator(p);
    int length = token_end - p;
    tokens[i] = copy_str(p, length);
    p = token_end;
  }
    
  tokens[i] = '\0';
  
  return tokens;
}
  
void  print_tokens(char **tokens){
  int i;
  while(tokens[i]){
    if(space_char(tokens[i][0])||tokens[i][0]== '\0'){
      i++;
      continue;
      }
    printf("Token[%d] = %s\n", i, tokens[i]);
    i++;
  }
  printf("Token[%d] = 0\n", i);

}

void free_tokens(char **tokens){
  int i = 0;
  if (tokens == 0){
    return;
  }
  while(tokens[i]!= NULL){
    free(tokens[i]);
    i++;}
  free(tokens);
}
