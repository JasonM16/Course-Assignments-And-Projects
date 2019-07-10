#include<stdio.h>
#include<stdlib.h>

int AtoI ( const char * str );
int StrCmp ( const char * str1, const char * str2 );
char * StrCpy ( char * dest, const char * src );
char * StrCat ( char * dest, const char * src );
char * StrChr ( char * str, int ch );

int main()
{
	int choice, result;
	char ch, src[256], dest[256];

	printf("This program simulates some of the library functions.\n");

	printf("Enter a numeric string to convert: ");
	scanf(" %[^\n]", src);
	printf("%s to integer = %d\n", src, AtoI(src));

	printf("Enter string 1: ");
	scanf(" %[^\n]", src);
	printf("Enter string 2: ");
	scanf(" %[^\n]", dest);
	result = StrCmp(src, dest);
	if(result > 0)
		printf("String 1 is greater than String 2.\n");
	else if(result < 0)
		printf("String 1 is less than String 2.\n");
	else
		printf("String 1 and String 2 are equal.\n");

	printf("Enter a string: ");
	scanf(" %[^\n]", src);
	StrCpy(dest, src);
	printf("Original string is: %s.\n", src);
	printf("Copied  string  is: %s.\n", dest);

	printf("Enter string 1: ");
	scanf(" %[^\n]", dest);
	printf("Enter string 2: ");
	scanf(" %[^\n]", src);
	StrCat(dest, src);
	printf("String 1 + String 2: %s.\n", dest);

	printf("Enter a string: ");
	scanf(" %[^\n]", src);
	printf("Enter a charcter to search: ");
	scanf(" %c", &ch);
	printf("Character %c %s in the string %s.\n", ch, StrChr(src, ch)?"is":"is not", src);

}

int AtoI ( const char * str )
{
	int i = 0, num = 0;
	while(str[i] != '\0')
	{
		if(str[i] == '.') break;
		if(str[i] >= '0' && str[i] <= '9')
			num = (num*10) + str[i] - '0';
		i++;
	}
	return num;
}

int StrCmp ( const char * str1, const char * str2 )
{
	int i = 0, flag = 0;
	while(str1[i] != '\0' && str2[i] != '\0')
	{
		if(str1[i] < str2[i]) return -1;
		if(str1[i] > str2[i]) return 1;
		i++;
	}
	if(str1[i] == '\0') return -1;
	if(str2[i] == '\0') return 1;
	return 0;
}

char * StrCpy ( char * dest, const char * src )
{
	int i = 0;

	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return dest;
}

char * StrCat ( char * dest, const char * src )
{
	int i = 0, j = 0;

	while(dest[i] != '\0') i++;

	while(src[j] != '\0')
	{
		dest[i] = src[j];
		i++; j++;
	}
	dest[i] = '\0';

	return dest;
}

char * StrChr ( char * str, int ch )
{
	int i = 0;
	while(str[i] != ch && str[i] != '\0') i++;

	if(str[i] == ch) return &str[i];
	return NULL;
}