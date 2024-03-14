#include "lexer.h"
#include "macros.h"

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Constructor for a lexer "object" via a struct defined in lexer.h
lexer_type* init_lexer(char* source){

  lexer_type* lexer = calloc(1, sizeof(lexer_type));
  lexer->source = source;
  lexer->source_size= strlen(source);
  lexer->i = 0;
  lexer->c = lexer->source[lexer->i];

  return lexer;
}

// Advance the lexer within the current token
void lexer_advance(lexer_type* lexer) {
  if (lexer->i < lexer->source_size && lexer->c != '\0') {
    lexer->i++;
    lexer->c = lexer->source[lexer->i];
  }
}

// Allows lexer to peek along the token by a specified offset
char lexer_peek(lexer_type* lexer, int offset){
  return lexer->source[MIN(lexer->i+offset, lexer->source_size)];
}

// Advance the lexer to the next token and categorize it
token_t* next_token(lexer_type* lexer) {
  while (lexer->c != '\0') {
    if (isalnum(lexer->c)) {
      lexer_advance_with_T(lexer, parse_id(lexer));
    }

    if (isdigit(lexer->c)) {
      lexer_advance_with_T(lexer, parse_nr(lexer));
    }

    switch (lexer->c) {
      case '=' : { }
      case '(' : return lexer_advance_cur(lexer, TOKEN_LPAR);
      case ')' : return lexer_advance_cur(lexer, TOKEN_RPAR);
      case '{' : { return lexer_advance_cur(lexer, TOKEN_LBR); }
      case '}' : { return lexer_advance_cur(lexer, TOKEN_RBR); }
      case ';' : { return lexer_advance_cur(lexer, TOKEN_SEMICOLON); }
      case '\0' : break;
      default: {printf("Lexer encountered unexpected character: %c\n", lexer->c );
                exit(1);
                break;
                }
    }
  }

  return lexer_advance_with_T(lexer, parse_id(lexer));
}


token_t* lexer_advance_with_T(lexer_type* lexer, token_t* token){
  lexer_advance(lexer);
  return token;
}


// Allow the lexer to ignore spaces, tabs, newlines
void ignore_whitespace(lexer_type* lexer) {
  while (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\t' || lexer->c == '\n') {
    lexer_advance(lexer);
  }
}


token_t* parse_id(lexer_type* lexer) {

  char* value = calloc(1, sizeof(char));
  while (isalnum(lexer->c)) {
    value = realloc(value, (strlen(value) + 2) * sizeof(char));

    strcat(value, (char[]){lexer->c,0});

    lexer_advance(lexer);
  }
  return init_token(value, TOKEN_ID);
}

token_t* parse_nr(lexer_type* lexer) {
  char* value = calloc(1, sizeof(char));
  while (isdigit(lexer->c)) {
    value = realloc(value, (strlen(value) + 2) * sizeof(char));

    strcat(value, (char[]){lexer->c,0});

    lexer_advance(lexer);
  }
  return init_token(value, TOKEN_INT);
}

token_t* lexer_advance_with_cur(lexer_type* lexer, int type) {
  char * value = calloc(2, sizeof(char));
  value[0] = lexer->c;
  value[1] = '\0';

  token_t* token = init_token(value, type);
  lexer_advance(lexer);

  return token;
}
