#include <Lmcons.h>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>

#include "shell.h"

int main(int argc, char** argv) {
  if (isatty(STDIN_FILENO)) {
    char cwd[1024];

    char username[UNLEN + 1];
    DWORD cch = UNLEN + 1;
    if (!GetUserNameA(username, &cch)) {
      fprintf(stderr, "failed to get username");
      return 1;
    }

    char hostname[MAX_COMPUTERNAME_LENGTH];
    get_hostname(hostname, MAX_COMPUTERNAME_LENGTH);

    clrscr();
    print_startup_message();

    char cmdbuf[MAX_COMMAND_LENGTH];

    while (1) {
      getcwd(cwd, sizeof(cwd));
      printf("%s@%s:%s$ ", username, hostname, cwd);

      fgets(cmdbuf, sizeof(cmdbuf), stdin);
      cmdbuf[strcspn(cmdbuf, "\r\n")] = 0;

      char** argv = parse_args(cmdbuf);
      if (argv[0] == NULL) {
        continue;
      }

      handle_command(argv);
      free(argv);
    }
  } else {
    printf("not atty!");
  }

  return 0;
}