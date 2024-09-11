#include <stdio.h>
#include <stdlib.h>

#include "cli_parser.h"

CliState* parse_command_line(int argc, char **argv) {
  char *file_name;
  unsigned long raw_key;
  CliState *state;

  if (argc == 1) {
    fprintf(stderr, "Incorrect usage!\n");
    return NULL;
  }

  if (argc > 3) {
    fprintf(stderr, "Only expected file name and key, but received more arguments.\n");
    return NULL;
  }

  file_name = argv[1]; 
  
  raw_key = strtoul(argv[2], NULL, 10);
  if (raw_key == 0) {
    fprintf(stderr, "Invalid key format\n");
    return NULL;
  }

  if (raw_key > 25) {
    fprintf(stderr, "Key size is too big!\n");
    return NULL;
  }

  state = malloc(sizeof(CliState));
  if (state == NULL) {
    fprintf(stderr, "Internal error: Cannot create state.\n");
    return NULL;
  }

  state->key = (unsigned)raw_key;
  state->file_name = file_name;

  return state;
}
