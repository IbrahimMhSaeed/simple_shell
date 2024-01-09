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

/* Main functions: */

void show_prompt(void);
char *get_input();
char **command_tokenization(char *buffer, char **environ);
int execute(char **token, char **env);
int execute_arg(char **token);

/* allocation functions: */

void free_2d(char **token);
char **allocate_2d_array(int row, char *buffer, char *delim);

/* Path Fuctions: */

int _strcmp(char *comp1, char *comp2);
void _strcpy(char *token, char *word, int wordlen);
int get_word_len(char *word, char delim);
int num_words_in_string(char *string, char delim);
char *get_name(char *name, char *var);
char *_getenv(char *name, char **environ);
char **tokenize_path(char **environ);

/* test function: */

void test_token(char **token);

/* error functions */

void memory_allocation_error_buffer(char *buffer);
void memory_allocation_error_2d(char **token, int row);

#endif
