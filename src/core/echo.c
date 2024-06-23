#include "echo.h"

#include <stdio.h>
#include <string.h>

void echo_command(char** argv) {
  int newline = 1;
  int start = 1;

  // Check for the -n flag
  if (argv[1] != NULL && strcmp(argv[1], "-n") == 0) {
    newline = 0;
    start = 2;
  }

  // Print the arguments
  for (int i = start; argv[i] != NULL; i++) {
    fprintf(stdout, "%s", argv[i]);
    if (argv[i + 1] != NULL) {
      fprintf(stdout, "\n");
    }
  }

  // Print newline unless suppressed
  if (newline) {
    fprintf(stdout, "\n");
  }
};