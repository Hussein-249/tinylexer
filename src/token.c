#include "header/token.h"

#include <stddef.h>
#include <stdlib.h>


token_t* init_token(char* value, int type) {
  token_t* token = calloc(1, sizeof(token_t));
  if (token == NULL) {
    // in case of memory allocation failure
    return NULL;
  }
  token->type = type;
  token->literal_value = value;

  return token;
}
