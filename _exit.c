#include "main.h"

#define MAX_INPUT_SIZE 1024

void _exit() {
    printf("Exiting the shell...\n");
    exit(0);
}

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("SimpleShell> ");

        fgets(input, MAX_INPUT_SIZE, stdin);

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            _exit();
        } else {
            printf("Command not recognized: %s\n", input);
        }
    }

    return 0;
}
