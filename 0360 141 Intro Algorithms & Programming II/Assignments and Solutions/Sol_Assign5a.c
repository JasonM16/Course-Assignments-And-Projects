/****
    This program interactively asks the user for input.It supports up to MAX (10) records.
    The program saves the records to a sequential text file named "contactlistA.dat".
    The file stores all the records in a format that can be read back later when
    requested and display the contents accordingly.

    Written by: Quazi Rahman, July, 2012.
****/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 10

/* contact record */
typedef struct
{
    char first_name[30];
    char last_name [30];
    char address [100];
    char postal_code[7];
    char phone[11];
} contact;

contact contactList[MAX];
int COUNT = 0;

/***** function prototypes *****/
void print_menu();
void add_contact();
void display_contacts();
void display_contact(int index);
void search_contact();
void save_contacts();
void load_contacs();
void wordCap(char name[], int n);
void Exit();
void formatPostal(char string[]);
void formatPhone(char string[]);

int main()
{
    int choice;

    printf("   *** Personal Contact Book v1.0 ***\n");

    while(1)
    {
        print_menu();
        scanf("%d", &choice);

        switch(choice)
        {
            case 1 : add_contact(); break;
            case 2 : display_contacts(); break;
            case 3 : search_contact(); break;
            case 4 : save_contacts(); break;
            case 5 : load_contacs(); break;
            case 6 : Exit();
            default:printf("Invalide choice, choose again.\n");
        }
    }

    return 0;
}

void print_menu()
{
    printf("\t1. Add new contact\n");
    printf("\t2. Display current contacts\n");
    printf("\t3. Search for a contact\n");
    printf("\t4. Save contacts to file\n");
    printf("\t5. Load contacts from file\n");
    printf("\t6. Exit\n\t> ");
}

/*
  This function gets values from the user
  and stored them into the "contact" structure
  after any needed formatting
*/
void add_contact()
{
    char buffer[100];
    char ans = 'y';

    while(ans == 'y' || ans == 'Y')
    {
        if(COUNT >= MAX)
        {
            printf("The List is full, cannot add any more contact\n");
            return;
        }
        printf("\nAdding new contact:\n");
        printf("First name : ");
        scanf(" %s", buffer);
        wordCap(buffer, 1);
        strcpy(contactList[COUNT].first_name, buffer);
        printf("Last name  : ");
        scanf(" %s", buffer);
        wordCap(buffer, 1);
        strcpy(contactList[COUNT].last_name, buffer);
        printf("Address    : ");
        scanf(" %[^\n]", buffer);
        wordCap(buffer, 1);
        strcpy(contactList[COUNT].address, buffer);
        printf("Postal Code: ");
        scanf(" %s", buffer);
        wordCap(buffer, 2);
        strcpy(contactList[COUNT].postal_code, buffer);
        printf("Phone      : ");
        scanf(" %s", buffer);
        strcpy(contactList[COUNT].phone, buffer);
        COUNT++;
        printf("\nAdd another contact?(y/n): ");
        scanf(" %c", &ans);
    }
}

/*
  This function either capitalize the first letter
  of a word or format postatl code
*/
void wordCap(char string[], int n)
{
    int i = 0;

    while(string[i])
    {
        string[i] = toupper(string[i]);
        i++;

        if(n == 1)
        {
            while(string[i] != ' ')
            {
                string[i] = tolower(string[i]);
                i++;
            }

            if(string[i])
                i++;
        }
    }
}

void display_contacts()
{
    int i = 0;
    while(i < COUNT) display_contact(i++);
}

void display_contact(int index)
{

    printf("First name : %s\n", contactList[index].first_name);
    printf("Last name  : %s\n", contactList[index].last_name);
    printf("Address    : %s\n", contactList[index].address);
    printf("Postal Code: ");
    formatPostal(contactList[index].postal_code);
    printf("Phone      : ");
    formatPhone(contactList[index].phone);
}

/*
  This function searches for a record
*/
void search_contact()
{
    int index = 0, count = 0;
    int iArray[MAX] = {0};
    char lName[30];

    printf("What is the contact's last name? ");
    scanf("%s", lName);
    wordCap(lName, 1);
    while(index < COUNT)
    {
        if(strcmp(lName, contactList[index].last_name) == 0)
        {
            iArray[index] = 1;
            count++;
        }

        index++;
    }

    printf("Found %d record(s):\n", count);

    index = 0;
    while(index < COUNT)
    {
        if(iArray[index] == 1)
            display_contact(index);

        index++;
    }
}


/*Saves contact list into a text file*/
void save_contacts()
{
    FILE *out;
    int i;

    if((out = fopen("contactListA.dat", "w")) == NULL)
    {
        printf("Cannot open contactListA.dat for writing\n");
        exit(0);
    }

    fprintf(out, "%d\n", COUNT);

    for(i = 0; i < COUNT; i++)
    {
        fprintf(out, "%s\n", contactList[i].first_name);
        fprintf(out, "%s\n", contactList[i].last_name);
        fprintf(out, "%s\n", contactList[i].address);
        fprintf(out, "%s\n", contactList[i].postal_code);
        fprintf(out, "%s\n", contactList[i].phone);
    }

    fclose(out);

    printf("Contact List saved successfully.\n");

}


void load_contacs()
{
    FILE *in;
    int i;
    char temp[100];

    if((in = fopen("contactListA.dat", "r")) == NULL)
    {
        printf("Cannot open contactListA.dat for reading\n");
        exit(0);
    }

    fscanf(in, "%d", &COUNT);

    for(i = 0; i < COUNT; i++)
    {
        fscanf(in, " %s", contactList[i].first_name);
        fscanf(in, " %s", contactList[i].last_name);
        fscanf(in, " %[^\n]", contactList[i].address);
        fscanf(in, " %s", contactList[i].postal_code);
        fscanf(in, " %s", contactList[i].phone);

    }

    fclose(in);

    printf("Contact List loaded successfully.\n");
}

void Exit()
{
    char ans;

    printf("Save your contacts to file before leaving? (y/n): ");
    fflush(stdin);
    scanf("%c", &ans);
    if(ans == 'y' || ans == 'Y')
        save_contacts();

    printf("Bye!\n");
    exit(0);
}

void formatPostal(char string[])
{
    int i = 0;

    while(i < 3) putchar(string[i++]);
    putchar('-');
    while(string[i]) putchar(string[i++]);
    putchar('\n');
}

void formatPhone(char string[])
{
    int i = 0;

    putchar('(');
    while(i < 3) putchar(string[i++]);
    printf(") ");
    while(i < 6) putchar(string[i++]);
    putchar('-');
    while(string[i]) putchar(string[i++]);
    printf("\n\n");
}