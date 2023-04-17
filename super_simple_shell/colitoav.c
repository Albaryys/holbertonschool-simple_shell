#include <stdlib.h>
#include <string.h>

#define DELIMITER " \t\r\n\a"

char **split_string(char *str)
{
    char **words = NULL;
    char *word = strtok(str, DELIMITER);
    int word_count = 0;

    while (word != NULL) {
        words = realloc(words, sizeof(char *) * (word_count + 1));
        words[word_count] = word;
        word_count++;
        word = strtok(NULL, DELIMITER);
    }

    words = realloc(words, sizeof(char *) * (word_count + 1));
    words[word_count] = NULL;

    return words;
}

