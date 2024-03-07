#include <string.h>
#include <ctype.h>
#include "lexer.h"


lexer_type* init_lexer(char* source){
  // Constructor for a lexer "object" from struct
  lexer_type* lexer = calloc(1, sizeof(LEXER_STRUCT));
  lexer->source = source;
  lexer->source_size= strlen(source);
  lexer->i = 0;
  lexer->c = lexer->source[lexer->i];

  return lexer;
}


void lexer_advance(lexer_type* lexer) {
  if (lexer->i < lexer->source_size && lexer->c != '\0') {
    lexer->i++;
    lexer->c = lexer->source[lexer->i];
  }
}


token_T* next_token(lexer_type* lexer) {
  while (lexer->c != '\0') {
    if (isalnum(lexer->c)) {
      continue;
    }
  }

  return lexer;
}


void ignore_whitespace(lexer_type* lexer) {
  while (lexer->c = ' ' || lexer->c = '\t') {
    lexer_advance(lexer);
  }

  return lexer;
}
