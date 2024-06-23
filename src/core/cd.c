#include "cd.h"

#include <stdio.h>
#include <unistd.h>

void cd_command(char** argv) {
  if (argv[1] == NULL) {
    fprintf(stderr, "cd: expected argument to \"cd\"\n");
  } else {
    if (chdir(argv[1]) != 0) {
      perror("cd");
    }
  }
}