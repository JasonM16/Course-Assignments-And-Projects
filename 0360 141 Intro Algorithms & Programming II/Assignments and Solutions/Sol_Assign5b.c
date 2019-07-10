/****
    This program interactively asks the user for input.It supports dynamically created records.
    The program saves the records to a sequential text file named "contactlistB.dat".
    The file stores all the records in a format that can be read back later when
    requested and display the contents accordingly.

    Written by: Quazi Rahman, July, 2012.
****/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//#define MAX 10

/* contact record */
struct Cont
{
    char first_name[30];
    char last_name [30];
    char address [100];
    char postal_code[7];
    char phone[11];
    struct Cont *next;
};

typedef struct Cont contact;

contact *Head = NULL;

/***** function prototypes *****/
void print_menu();
contact *create_new_contact();
void free_contact_list();
void add_contact();
void display_contacts();
void display_contact(contact *temp);
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
        contact *new_contact = create_new_contact();

        printf("\nAdding new contact:\n");
        printf("First name : ");
        scanf(" %s", buffer);
        wordCap(buffer, 1);
        strcpy(new_contact->first_name, buffer);
        printf("Last name  : ");
        scanf(" %s", buffer);
        wordCap(buffer, 1);
        strcpy(new_contact->last_name, buffer);
        printf("Address    : ");
        scanf(" %[^\n]", buffer);
        wordCap(buffer, 1);
        strcpy(new_contact->address, buffer);
        printf("Postal Code: ");
        scanf(" %s", buffer);
        wordCap(buffer, 2);
        strcpy(new_contact->postal_code, buffer);
        printf("Phone      : ");
        scanf(" %s", buffer);
        strcpy(new_contact->phone, buffer);
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
    contact *temp = Head;
    while(temp)
    {
        display_contact(temp);
        temp = temp->next;
    }
}

void display_contact(contact *temp)
{

    printf("First name : %s\n", temp->first_name);
    printf("Last name  : %s\n", temp->last_name);
    printf("Address    : %s\n", temp->address);
    printf("Postal Code: ");
    formatPostal(temp->postal_code);
    printf("Phone      : ");
    formatPhone(temp->phone);
}

/*
  This function searches for a record
*/
void search_contact()
{
    int count = 0;
    char lName[30];

    contact *temp = Head;

    printf("What is the contact's last name? ");
    scanf("%s", lName);
    wordCap(lName, 1);

    while(temp)
    {
        if(strcmp(lName, temp->last_name) == 0)
            count++;
        temp=temp->next;
    }

    printf("Found %d record(s):\n", count);

    temp = Head;
    while(temp)
    {
        if(strcmp(lName, temp->last_name) == 0)
            display_contact(temp);

        temp = temp->next;
    }
}


/*Saves contact list into a text file*/
void save_contacts()
{
    FILE *out;
    contact *temp = Head;

    if((out = fopen("contactListB.dat", "w")) == NULL)
    {
        printf("Cannot open contactListB.dat for writing\n");
        exit(0);
    }

    while(temp)
    {
        fprintf(out, "%s\n", temp->first_name);
        fprintf(out, "%s\n", temp->last_name);
        fprintf(out, "%s\n", temp->address);
        fprintf(out, "%s\n", temp->postal_code);
        fprintf(out, "%s\n", temp->phone);

        temp = temp->next;
    }

    fclose(out);

    printf("Contact List saved successfully.\n");

}


void load_contacs()
{

    FILE *in;

    free_contact_list();

    if((in = fopen("contactListB.dat", "r")) == NULL)
    {
        printf("Cannot open contactListB.dat for reading\n");
        exit(0);
    }

    while(!feof(in))
    {
        contact *new_contact = create_new_contact();

        fscanf(in, "%s\n", new_contact->first_name);
        fscanf(in, "%s\n", new_contact->last_name);
        fscanf(in, "%[^\n]\n", new_contact->address);
        fscanf(in, "%s\n", new_contact->postal_code);
        fscanf(in, "%s\n", new_contact->phone);
        fflush(in);
    }

    fclose(in);
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

contact *create_new_contact()
{
    contact *new_contact;
    new_contact = (contact *) malloc(sizeof(contact));
    new_contact->next = NULL;

    if(Head == NULL)
        Head = new_contact;
    else
    {
        contact *temp = Head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new_contact;
    }

    return new_contact;
}

void free_contact_list()
{
    if(Head)
    {
        contact *temp = Head;

        while(Head)
        {
            Head = Head->next;
            free(temp);
            temp = Head;
        }
    }
}