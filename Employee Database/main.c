//Issues with printf statements used for output
#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

typedef Node *Linkedlist;

int main()
{
    int ch;
    printf("Employee Database Management System\n");
    printf("1. Add Employee\n");
    printf("2. Display Employees\n");
    printf("3. Search Employee\n");
    printf("4. Update Salary\n");
    printf("5. Delete Employee\n");
    printf("6. Exit\n\n");
    Node *list = malloc(sizeof(Node));
    list = NULL;
    while (1)
    {

        printf("Enter your choice : ");
        scanf("%d", &ch);
        if (ch > 6 || ch < -1)
        {
            printf("**Wrong Input**\nTry Again ... \n");
            printf("Enter your choice : ");
            scanf("%d", &ch);
        }
        else if (ch == 1)
        {
            list = add(list);
        }
        else if (ch == 2)
        {
            printf("Employee List : \n");
            display(list);
        }
        else if (ch == 3)
        {
            int num;
            printf("Enter Employee ID to search:");
            scanf("%d", &num);
            searchbyId(num, list);
        }
        else if (ch == 4)
        {
            int id, newsalary;
            printf("Enter Employee ID to update salary: ");
            scanf("%d", &id);
            printf("Enter new salary: ");
            scanf("%d", &newsalary);
            updateSalary(id, newsalary, list);
        }
        else if (ch == 5)
        {
            int num;
            printf("Enter Employee ID to delete: ");
            scanf("%d", &num);
            list = delete (num, list);
        }
        else if (ch == 6)
        {
            printf("Exiting the program...\n");
            Linkedlist tm = list;
            while (tm != NULL)
            {
                free(tm->data.name);
                free(tm->data.position);
                tm = tm->next;
            }
            free(tm);
            free(list);
            return 0;
        }
    }
    return 0;
}