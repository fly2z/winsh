#include "dir.h"

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

void mkdir_command(char** argv) {
  if (argv[1] == NULL) {
    fprintf(stderr, "mkdir: missing operand\n");
  } else {
    if (mkdir(argv[1]) != 0) {
      perror("mkdir");
    }
  }
}

void rmdir_command(char** argv) {
  if (argv[1] == NULL) {
    fprintf(stderr, "rmdir: missing operand\n");
  } else {
    if (rmdir(argv[1]) != 0) {
      perror("rmdir");
    }
  }
}