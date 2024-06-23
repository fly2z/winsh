#include "pwd.h"

#include <stdio.h>
#include <unistd.h>

void pwd_command() {
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));

  fprintf(stdout, "%s\n", cwd);
}