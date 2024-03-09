/*
  This set of lexer functions handle converting characters / strings into tokens.
*/
#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>

#include "token.h"

typedef struct LEXER_STRUCT {
  char* source;
  size_t source_size;
  char c;
  unsigned int i;
} lexer_type;

lexer_type* init_lexer(char* source);

void lexer_advance(lexer_type* lexer);

token_t* lexer_advance_with_T(lexer_type* lexer, token_t* token);

token_t* next_token(lexer_type* lexer);

void ignore_whitespace(lexer_type* lexer);

token_t* parse_id(lexer_type* lexer);

#endif
