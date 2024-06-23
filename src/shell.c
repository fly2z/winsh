#include "shell.h"

#include <windows.h>

// Function to parse command arguments, handling quoted strings
char** parse_args(char* buffer) {
  int bufsize = MAX_ARGS;
  int i = 0;
  char** args = malloc(bufsize * sizeof(char*));
  if (!args) {
    fprintf(stderr, "allocation error in parse_args: tokens\n");
    exit(1);
  }

  char* arg_start = NULL;
  int in_quotes = 0;
  int length = strlen(buffer);

  for (int j = 0; j <= length; j++) {
    char c = buffer[j];

    if (c == '"') {
      if (in_quotes) {
        buffer[j] = '\0';
        args[i++] = arg_start;
        in_quotes = 0;
        arg_start = NULL;
      } else {
        in_quotes = 1;
        arg_start = &buffer[j + 1];
      }
    } else if ((c == ' ' && !in_quotes) || c == '\0') {
      if (arg_start) {
        if (c != '\0') {
          buffer[j] = '\0';
        }
        args[i++] = arg_start;
        arg_start = NULL;
      }
    } else if (!arg_start) {
      arg_start = &buffer[j];
    }

    if (i >= bufsize) {
      bufsize += MAX_ARGS;
      args = realloc(args, bufsize * sizeof(char*));
      if (!args) {
        fprintf(stderr, "reallocation error in parse_args: tokens\n");
        exit(1);
      }
    }
  }

  args[i] = NULL;

  // if no tokens were found, return an array with a single NULL pointer
  if (i == 0) {
    free(args);
    args = malloc(sizeof(char*));
    if (!args) {
      fprintf(stderr, "allocation error in parse_args\n");
      exit(1);
    }
    args[0] = NULL;
  }

  return args;
}

void print_startup_message() {
  printf("\n");
  printf("************************************************\n");
  printf("*        WinSH - POSIX Shell for Windows       *\n");
  printf("*              (c) fly2z 2024                  *\n");
  printf("*                                              *\n");
  printf("*     Type 'help' to see a list of commands    *\n");
  printf("************************************************\n");
  printf("\n");
}

void clrscr() { system("cls"); }

void get_hostname(char* hostname, DWORD size) {
  if (!GetComputerNameA(hostname, &size)) {
    fprintf(stderr, "failed to get hostname\n");
  }
}