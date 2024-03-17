/*
  This set of lexer functions handle converting characters / strings into tokens.
*/

#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>

#include "token.h"

typedef struct LEXER_STRUCT
{
  char* source;
  size_t source_size;
  char c;
  unsigned int i;
} lexer_type;

// creates a lexer variable connected to a source
lexer_type* init_lexer(char* source);

// allows the lexer to peek along the current source by a specified offset
char lexer_peek(lexer_type* lexer, int offset_index);

// allows the lexer to move to the next token
void lexer_advance(lexer_type* lexer);

token_t* lexer_advance_cur(lexer_type* lexer, int type);

// allows the lexer to advance to the next character while remembering the current token (for strings, variable names)
token_t* lexer_advance_with_T(lexer_type* lexer, token_t* token);

token_t* next_token(lexer_type* lexer);

void ignore_whitespace(lexer_type* lexer);

token_t* parse_id(lexer_type* lexer);

token_t* parse_nr(lexer_type* lexer);

#endif
