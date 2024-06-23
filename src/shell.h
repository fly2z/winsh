#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shell_styles.h"

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64

// parse_args parses the command buffer and returns a list of arguments
char** parse_args(char* buffer);

// handle_command takes a list of arguments and executes the command
void handle_command(char** args);

// print_startup_message prints the shell credits and banner
void print_startup_message();

// clrscr clears the console
void clrscr();

/* get_hostname gets the hostname of the system and stores it in
   the hostname buffer. The size parameter is the size of the buffer. */
void get_hostname(char* hostname, unsigned long size);

#endif