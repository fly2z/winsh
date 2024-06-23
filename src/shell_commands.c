#include "core/cd.h"
#include "core/dir.h"
#include "core/echo.h"
#include "core/file.h"
#include "core/ls.h"
#include "core/pwd.h"
#include "shell.h"

typedef void (*CommandFunc)(char**);

typedef struct {
  const char* command;
  CommandFunc func;
} CommandEntry;

void exit_command();
void clear_command();
void help_command();

void handle_command(char** argv) {
  CommandEntry commands[] = {
      {"exit", exit_command},
      {"clear", clear_command},
      {"echo", echo_command},
      {"ls", ls_command},
      {"pwd", pwd_command},
      {"cd", cd_command},
      {"cat", cat_command},
      {"touch", touch_command},
      {"mv", mv_command},
      {"mkdir", mkdir_command},
      {"help", help_command},
      {"rmdir", rmdir_command},
      {NULL, NULL}  // Terminator entry
  };

  for (int i = 0; commands[i].command != NULL; i++) {
    if (strcmp(argv[0], commands[i].command) == 0) {
      commands[i].func(argv);
      return;
    }
  }

  kprintf(KRED KBOLD, "%s: command not found\n", argv[0]);
}

void exit_command() { exit(0); }
void clear_command() { clrscr(); }
void help_command() {
  printf("\n");
  printf("************************************************\n");
  printf("*               WinsSH - Help Menu             *\n");
  printf("************************************************\n");
  printf("*                                              *\n");
  printf("*   Available Commands:                        *\n");
  printf("*   - exit         : Exit the shell            *\n");
  printf("*   - clear        : Clear the screen          *\n");
  printf("*   - echo         : Echo arguments to stdout  *\n");
  printf("*   - ls           : List directory contents   *\n");
  printf("*   - pwd          : Print current directory   *\n");
  printf("*   - cd <dir>     : Change directory          *\n");
  printf("*   - cat <file>   : Display file contents     *\n");
  printf("*   - touch <file> : Create an empty file      *\n");
  printf("*   - mv <src> <dest> : Move or rename file    *\n");
  printf("*   - mkdir <dir>  : Create a directory        *\n");
  printf("*   - rmdir <dir>  : Remove a directory        *\n");
  printf("*   - help         : Display this help message *\n");
  printf("*                                              *\n");
  printf("************************************************\n");
  printf("\n");
}