#include "header/read.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_file(const char* filename) {
  FILE* fileptr;
  char* line = NULL;

  size_t len, read;
  len = 0;

  fileptr = fopen(filename, 'rb');

  if (fp == NULL) {
    printf("Could not read or find file: %s \n", filename);
    exit(1);
  }

  char* buf = (char*) calloc(1, sizeof(char));
  buffer[0] = '\0';

  fclose(fileptr);

  return line;
}
