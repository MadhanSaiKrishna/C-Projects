#include <stdio.h>
#include "functions.h"
#include <string.h>
#include <stdlib.h>

typedef Node* Linkedlist;

Node *add(Node *list)
{
    Linkedlist newNode = (Linkedlist)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failure \n");
        return list;
    }
    newNode->next=NULL;
    if (list == NULL)
    {
        input(newNode);
        return newNode;
    }
    
    else
    {
        Linkedlist tm = list;
        while (tm->next!=NULL)
        {
            tm=tm->next;
        }
        tm->next= newNode;
        input(newNode);
        return list;
        
    }
    printf("Employee added successfully\n");
    return list;
}

void input(Linkedlist list)
{
    printf("Enter Employee ID : ");
    scanf("%d", &list->data.id);
    printf("Enter Name : ");
    fgets(list->data.name,1000,stdin);
    printf("Enter Position : ");
    fgets(list->data.position,1000,stdin);
    printf("Enter Salary : ");
    scanf("%d", &list->data.salary);
    //Issue with taking input
}

void display(Linkedlist list)
{
    printf("Employee List : \n");
    printf("ID \tName\t\tPosition\t\tSalary\n");
    if(list==NULL)
    printf("(empty)\n");
    Linkedlist tm = list;
    while (tm!=NULL)
    {
        printf("%3d\t%s\t\t%s\t\t%d\n", tm->data.id, tm->data.name,tm->data.position, tm->data.salary);
        tm= tm->next;
    }
}