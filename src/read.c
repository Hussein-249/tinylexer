#include "header/read.h"
#include <stdio.h>
#include <stdlib.h>

char* read_file(const char* filename) {
  FILE* fileptr;
  char* line = NULL;

  size_t len = 0;

  fileptr = fopen(filename, 'rb');

  return line;
}
