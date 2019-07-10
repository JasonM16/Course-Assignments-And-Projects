#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Reverse(char *str);
void ParseSentence(char *str);

int main()
{
    char buffer1[] = {'t', 'h', 'i', 's', ' ', 'i', 's', ' ', 't', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'b', 'u', 'f', 'f', 'e', 'r'};
    char buffer2[] = "this is the second buffer";
    char buffer3[80];
    char str[] = "Hello";

    printf("Enter a string: ");
    scanf(" %[^\n]s ", buffer3);

    printf("%s\n", buffer1);
    printf("%s\n", buffer2);
    printf("%s\n", buffer3);

    char *pBuffer = buffer3;
    printf("%s\n", pBuffer);

    pBuffer += 4;
    printf("%s\n", pBuffer);

    printf("\nReversing \"%s\"\n", str);
    Reverse(str);
    printf("%s\n", str);

    char str2[] = "Hello world, how are you today.";
    printf("\nParsing sentence\n\n");
    ParseSentence(str2);
    return 0;
}

void Reverse(char *str)
{
    char temp;
    int start, end;

    start = end = 0;

    while(str[end] != '\0') end++;
    end--;

    while (start <= end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

}

void ParseSentence(char *str)
{
    char *token;

    token = strtok(str, " ,;.");

    while(token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ,;.");
    }
}