#include "file.h"

#include <stdio.h>

void touch_command(char** argv) {
  if (argv[1] == NULL) {
    fprintf(stderr, "touch: missing file operand\n");
  } else {
    FILE* file = fopen(
        argv[1], "ab");  // "ab" mode to create the file if it doesn't exist
    if (file == NULL) {
      perror("touch");
      return;
    }

    fclose(file);
  }
}

void cat_command(char** argv) {
  FILE* file;
  char buffer[1024];
  size_t bytes_read;

  for (int i = 1; argv[i] != NULL; i++) {
    file = fopen(argv[i], "r");
    if (file == NULL) {
      perror("cat");
      continue;
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
      fwrite(buffer, 1, bytes_read, stdout);
    }

    fclose(file);
  }
}

void mv_command(char** argv) {
  if (argv[1] == NULL || argv[2] == NULL) {
    fprintf(stderr, "mv: missing file operand\n");
    return;
  }

  if (rename(argv[1], argv[2]) != 0) {
    perror("mv");
  }
}