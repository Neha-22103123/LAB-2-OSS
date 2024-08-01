#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    char paragraph[10000];
    WordCount wordCounts[MAX_WORDS];
    int wordCountIndex = 0;

    printf("Enter a paragraph (end with a newline):\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " \n\t.,;:!?\r");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < wordCountIndex; i++) {
            if (strcmp(wordCounts[i].word, token) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(wordCounts[wordCountIndex].word, token);
            wordCounts[wordCountIndex].count = 1;
            wordCountIndex++;
        }
        token = strtok(NULL, " \n\t.,;:!?\r");
    }

    printf("Word frequencies:\n");
    for (int i = 0; i < wordCountIndex; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}
