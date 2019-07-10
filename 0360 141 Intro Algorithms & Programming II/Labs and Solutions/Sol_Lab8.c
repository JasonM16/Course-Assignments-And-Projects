#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct myWord{
    char Word[21];
    int Length;
};

int main() {
    struct myWord wordList[20];
    struct myWord tempWord;
    char *currWord;
    int i, j, wordCount = 0;

    char myString[] = "the cat in the hat jumped over the lazy fox";

    currWord = strtok(myString, " ");

    while (currWord != NULL) {
        strcpy(wordList[wordCount].Word, currWord);
        wordList[wordCount].Length = strlen(currWord);
        wordCount++;

        currWord = strtok(NULL, " ");
    }

    printf("Printing the unsorted word list\n");
    for(i = 0; i < wordCount; i++)
        printf("%s\t%d\n", wordList[i].Word, wordList[i].Length);

    printf("\nSorting the word list...\n");
    for(i = 0; i < wordCount; i++) {
        for(j = 0; j < wordCount - 1; j++) {
            if(strcmp(wordList[j].Word, wordList[j+1].Word) > 0) {
                tempWord = wordList[j];
                wordList[j] = wordList[j+1];
                wordList[j+1] = tempWord;
            }
        }
    }
    printf("Printing the sorted word list:\n");
    for(i = 0; i < wordCount; i++)
        printf("%s\t%d\n", wordList[i].Word, wordList[i].Length);

    return 0;
}