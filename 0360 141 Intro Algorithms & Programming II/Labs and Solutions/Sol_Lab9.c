#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct myWord{
    char Word[21];
    int Length;
};

int main() {
    struct myWord wordList[20];
    struct myWord tempWord, *ptrWordList;
    char *currWord;
    int i, j, wordCount = 0;

    char myString[] = "the cat in the hat jumped over the lazy fox";

    ptrWordList = wordList;
    currWord = strtok(myString, " ");

    while (currWord != NULL) {
        strcpy((ptrWordList+wordCount)->Word, currWord);
        (ptrWordList+wordCount)->Length = strlen(currWord);
        wordCount++;

        currWord = strtok(NULL, " ");
    }

    printf("Printung the unsorted word list\n");
    for(i = 0; i < wordCount; i++)
        printf("%s\t%d\n", (ptrWordList+i)->Word, (ptrWordList+i)->Length);

    printf("\nSorting the word list...\n");
    for(i = 0; i < wordCount; i++) {
        for(j = 0; j < wordCount - 1; j++) {
            if(strcmp((ptrWordList+j)->Word, (ptrWordList+j+1)->Word) > 0) {
                tempWord = *(ptrWordList+j);
                *(ptrWordList+j) = *(ptrWordList+j+1);
                *(ptrWordList+j+1) = tempWord;
            }
        }
    }
    printf("Printung the sorted word list:\n");
    for(i = 0; i < wordCount; i++)
        printf("%s\t%d\n", (ptrWordList+i)->Word, (ptrWordList+i)->Length);

    return 0;
}