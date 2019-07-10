#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee{
    char firstName[40];
    char lastName[40];
    int ID;
};

typedef struct employee Employee;

char *CapWord(char *word);
void ReadEmpList(Employee *EmpList, const char *FileName);
void PrintEmpList(const Employee *EmpList);
void SaveEmpList(const Employee *EmpList, const char *FileName);

#define SIZE 3
int main() {

    Employee EmpList[SIZE];
	int i;

    ReadEmpList(EmpList, "employee.dat");

    for(i = 0; i < SIZE; i++)
    {
		strcpy(EmpList[i].firstName, CapWord(EmpList[i].firstName));
		strcpy(EmpList[i].lastName, CapWord(EmpList[i].lastName));
	}

	PrintEmpList(EmpList);
    SaveEmpList(EmpList, "employee.dat");

    return 0;
}

/* Read the employee data from the file */
void ReadEmpList(Employee *EmpList, const char *FileName)
{
    FILE *fp;
    int i;
    char temp[40];
    if((fp = fopen(FileName, "r")) == NULL)
    {
        printf("File opening error\n");
        exit(0);
    }
    fscanf(fp, " %s %s %s", temp, temp, temp);

    for(i=0; i<SIZE; i++)
    {
        fscanf(fp, " %d %s %s", &EmpList[i].ID, EmpList[i].firstName, EmpList[i].lastName);
    }
    fclose(fp);
}

/* Convert the first letter of a word to capital */
char *CapWord(char *word)
{
	word[0] = toupper(word[0]);
	return word;
}

/* Save (append) the employee record to the text file
   specified by FileName (one record at a time) */
void SaveEmpList(const Employee *EmpList, const char *FileName)
{
    FILE *fp;
    int i;
    if((fp = fopen(FileName, "w")) == NULL)
    {
        printf("File opening error\n");
        exit(0);
    }
    fprintf(fp, "ID\tFirstName\t\tLastName\n");
    for(i=0; i<SIZE; i++)
    {
        fprintf(fp, "%d\t%s\t\t%s\n", EmpList[i].ID, EmpList[i].firstName, EmpList[i].lastName);
    }
    fclose(fp);
}

/* Display the contents of a given Employee record */
void PrintEmpList(const Employee *EmpList)
{
    int i;

    printf("ID\tFirstName\tLastName\n");
    for(i=0; i<SIZE; i++)
    {
        printf("%d\t%s\t\t%s\n", EmpList[i].ID, EmpList[i].firstName, EmpList[i].lastName);
    }
}