#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void show_prompt(void);
int num_words_in_command(char *command);
char **get_input();
int execute(char **token);

/*
 * test function:
 *
 * void test_token(char **token);
 */

#endif
