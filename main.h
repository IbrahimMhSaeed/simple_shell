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
#include <sys/stat.h>

void show_prompt(void);
int num_words_in_command(char *command);
char **get_input();
int execute(char **token);

/*
 * test function:
 *
 * void test_token(char **token);
 */

/**
 * error functions
 */

void memory_allocation_error_buffer(char *buffer);
void memory_allocation_error_2d(char **token, int row);

#endif
