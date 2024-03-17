/*
  Creates and defines token types
*/

#ifndef TOKEN_H
#define TOKEN_H


typedef struct TOKEN_STRUCT {
  char* literal_value;
  enum {
    TOKEN_ID,
    TOKEN_INT,
    TOKEN_LPAR,
    TOKEN_RPAR,
    TOKEN_LBR,
    TOKEN_RBR,
    TOKEN_EQ,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_COMMA,
    TOKEN_SEMICOLON,
    TOKEN_COLON,
    TOKEN_EOF
  } type;
} token_t;


token_t* init_token(char* value, int type);

#endif
