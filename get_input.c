#include "main.h"

/**
 * num_words_in_command - calculate the number of words in user input
 * @command: command from user
 * Return: number of words in command (including termination NULL)
 */

int num_words_in_command(char *command)
{
	int space;

	space = 0;

	if (command == NULL)
		return (-1);

	while (*command != '\0')
	{
		if (*command == ' ')
			space++;
		command++;
	}

	space += 2;

	return (space);
}

/**
 * get_word_len - length of word
 * @word: word to be measured
 * Return: len of word && (-1) on fail
 */

int get_word_len(char *word)
{
	int len;

	if (word == NULL)
		return (-1);
	len = 0;

	while (*word != '\0' && *word != '\n')
	{
		word++;
		len++;
	}
	len++;

	return (len);
}

/**
 * _strcpy - copy string into string
 * @token: memory to copy string into
 * @word: string to be copied
 * @wordlen: length of word to be copied
 * Return: None
 */

void _strcpy(char *token, char *word, int wordlen)
{
	int i;

	for (i = 0; i < wordlen; i++)
	{
		if (word[i] == '\n')
			token[i] = '\0';
		else
			token[i] = word[i];
	}
}

/**
 * allocate_2d_array - create 2d array for tokenization
 * @row: number of words in user input
 * @buffer: user input
 * Return: tokenized input in form of 2D array
 */

char **allocate_2d_array(int row, char *buffer)
{

	int i, wordlen;
	char **token;
	char *word;

	token = malloc(sizeof(char *) * row);

	if (token == NULL)
	{
		perror("Error: memory allocation error");
		return (NULL);
	}

	i = 0;
	word = strtok(buffer, " ");

	while (word != NULL)
	{
		wordlen = get_word_len(word);
		token[i] = malloc(sizeof(char) * wordlen);
		if (token[i] == NULL)
		{
			memory_allocation_error_2d(token, row);
			return (NULL);
		}
		_strcpy(token[i], word, wordlen);
		word = strtok(NULL, " ");
		i++;
	}
	token[i] = NULL;
	return (token);
}

/**
 * get_input - reads input from user
 * Return: 2D array || or NULL on failure
 */

char **get_input()
{
	char *buffer;
	size_t len;
	ssize_t r;
	int words;
	char **token;

	token = NULL;
	buffer = NULL;
	len = 0;

	r = getline(&buffer, &len, stdin);
	if (r == -1)
	{
		memory_allocation_error_buffer(buffer);
		return (NULL);
	}
	words = num_words_in_command(buffer);
	if (words == -1)
	{
		perror("Entered an empty command");
		free(buffer);
		return (NULL);
	}

	token = allocate_2d_array(words, buffer);

	free(buffer);
	return (token);
}
