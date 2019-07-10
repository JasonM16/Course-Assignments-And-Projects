#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
   int ID;
   char name[40];
   struct student *next;
};
typedef struct student Student;

int getChoice();
Student *addToList(Student *List);
void printList(Student *List);
void printListRR(Student *List);
void searchList(Student *List);

int main() {
    int choice = 0;
    Student *SLIST = NULL;

    choice = getChoice();

    while(choice >= 0) {
        switch(choice) {
            case 0 : printf("Bye...\n"); exit(0);
            case 1 : SLIST = addToList(SLIST); break;
            case 2 : printList(SLIST); break;
            case 3 : printListRR(SLIST); break;
            case 4 : searchList(SLIST); break;
            default: printf("That is not a valid choice\n");
        }
        choice = getChoice();
    }

    if(SLIST) free(SLIST);
    return 0;
}

int getChoice() {
    int choice = 0;

    printf("\n****** MENU ******\n");
    printf("1. Add new student to list.\n");
    printf("2. Print the student list, beginning to end.\n");
    printf("3. Recursively print the student list starting from the end.\n");
    printf("4. Search the list for a student.\n");
    printf("0. Quit.\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    return choice;
}

Student *addToList(Student *List) {

    Student *aStudent = (Student *) malloc(sizeof(Student));

    printf("Enter student's ID: ");
    scanf("%d", &(aStudent->ID));
    printf("Enter student's name: ");
    scanf(" %[^\n]", aStudent->name);

    if (List == NULL) return aStudent;

    Student *pStudent = List;

    while(pStudent->next != NULL)
        pStudent = pStudent->next;

    pStudent->next = aStudent;

    return List;
}

void printList(Student *List) {
    while(List != NULL) {
        printf("%d %s\n", List->ID, List->name);
        List = List->next;
    }
}

void printListRR(Student *List) {
    if(List == NULL) return;
    printListRR(List->next);
    printf("%d %s\n", List->ID, List->name);
}

void searchList(Student *List) {
    int sid;
    printf("Enter student's ID: ");
    scanf("%d", &sid);

    while(List != NULL) {
        if(List->ID == sid){
            printf("%d %s\n", List->ID, List->name);
            return;
        }
        List = List->next;
    }
    printf("ID %d not found", sid);
}