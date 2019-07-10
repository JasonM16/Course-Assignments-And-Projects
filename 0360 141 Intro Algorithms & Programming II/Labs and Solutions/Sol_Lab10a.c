#include<stdio.h>
#include<stdlib.h>

struct employee{
    char firstName[40];
    char lastName[40];
    int ID;
};

typedef struct employee Employee;

void InputEmpRecord(Employee *EmpList);
void PrintEmpList(const Employee *EmpList);
void SaveEmpList(const Employee *EmpList, const char *FileName);

#define SIZE 3
int main() {

    Employee EmpList[SIZE];

    InputEmpRecord(EmpList);
    PrintEmpList(EmpList);
    SaveEmpList(EmpList, "employee.dat");

    return 0;
}

/* Input the employee data interactively from the keyboard */
void InputEmpRecord(Employee *EmpList)
{
    int i;
    for(i=0; i<SIZE; i++)
    {
        printf("Enter data for employee 1:\n", i+1);
        printf("ID? ");
        scanf("%d", &EmpList[i].ID);
        printf("First Name? ");
        scanf(" %s", EmpList[i].firstName);
        printf("Last Name? ");
        scanf(" %s", EmpList[i].lastName);
    }
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