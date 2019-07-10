#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 40

struct employee {
    int ID;
    char lastName[21];
    char firstName[21];
    char phone[20];
};
typedef struct employee Employee;

void enter_data(int id, Employee *e, char *line);
void print_menu();
void search_ID(Employee emp[], int num_emp);
void search_LN(Employee emp[], int num_emp);
void edit_emp(Employee emp[], int num_emp);
void add_emp(Employee emp[], int *num_emp);

int main()
{
    int i, choice, num_emp;;
    char line[256];
    char name[21];

    Employee e, emp[SIZE];

    num_emp = 0;

    while(scanf(" %s", line) != EOF)
    {
        //line[strlen(line) - 1] = '\0';
        enter_data(num_emp + 1, &emp[num_emp], line);
        num_emp++;
    }

    for(i = 0; i < num_emp; i++)
    {
        printf("%d %s, %s. %s\n", emp[i].ID, emp[i].lastName, emp[i].firstName, emp[i].phone);

    }

   /***REDIRECT STDIN TO KEYBOARD***/
    freopen("/dev/tty", "r", stdin);

    do
    {
        print_menu();
        printf("\nEnter integer for your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 0: exit(0);
            case 1: search_ID(emp, num_emp); break;
            case 2: search_LN(emp, num_emp); break;
            case 3: edit_emp(emp, num_emp);  break;
            case 4: add_emp(emp, &num_emp);  break;
            default: printf("That is not a correct choice!\n");
        }

    }while(1);

}

void enter_data(int id, Employee *e, char *line)
{
    char *word = NULL;
    char phone[15];
    int i;
    if(line)
    {
        e->ID = id;
        word = strtok(line, " ,");
        word[0] = toupper(word[0]);
        i = 1;
        while(word[i] != '\0')
        {
            word[i] = tolower(word[i]);
            i++;
        }

        strcpy(e->firstName, word);

        word = strtok(NULL, " ,");
        i = 0;
        while(word[i] != '\0')
        {
            word[i] = toupper(word[i]);
            i++;
        }

        strcpy(e->lastName, word);

        word = strtok(NULL, " ,");
        strcpy(phone, "(");
        strcpy(phone+1, word);
        strcpy(phone+4, ") ");

        word = strtok(NULL, " ,");
        strncpy(phone+6, word, 3);
        strcpy(phone+9, "-");
        strcpy(phone+10, word+3);

        strcpy(e->phone, phone);
    }
    else
        printf("No data to enter\n");
}

void print_menu()
{
    printf("\n\nMake a choice from the followings:\n");
    printf("1: Search employee using ID\n");
    printf("2: Search employee using last name\n");
    printf("3: Edit employee data\n");
    printf("4: Add new empolyee\n");
    printf("0: Quit\n");
}

void search_ID(Employee emp[], int num_emp)
{
    int i, id;
    printf("Enter employee id to search: ");
    scanf(" %d", &id);
    for(i = 0; i < num_emp; i++)
    {
        if(emp[i].ID == id)
            printf("%d %s, %s. %s\n", emp[i].ID, emp[i].lastName, emp[i].firstName, emp[i].phone);
    }
}

void search_LN(Employee emp[], int num_emp)
{
    int i;
    char name[21];
    printf("Enter employee last name to search: ");
    scanf(" %s", name);
    for(i = 0; i < num_emp; i++)
    {
        if(strcmp(emp[i].lastName, name) == 0)
            printf("%d %s, %s. %s\n", emp[i].ID, emp[i].lastName, emp[i].firstName, emp[i].phone);
    }
}

void edit_emp(Employee emp[], int num_emp)
{
    int id;
    char temp, line[256];
    printf("Enter employee id to edit [1 - %d]: ", num_emp);
    scanf("%d", &id);
    printf("Enter comma separeted list of new data: ");
    scanf(" %s", line);
    enter_data(id, &emp[id-1], line);

}

void add_emp(Employee emp[], int *num_emp)
{
    char temp, line[256];
    printf("Enter comma separeted list of new employee data: ");
    scanf(" %s", line);
    enter_data(*num_emp+1, &emp[*num_emp], line);
    (*num_emp)++;
}