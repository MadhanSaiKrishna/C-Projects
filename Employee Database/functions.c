#include <stdio.h>
#include "functions.h"
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000

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
        printf("Employee added successfully!\n\n");
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
        printf("Employee added successfully!\n\n");
        free(tm);
        return list;
        
    }
    return list;
}

void input(Linkedlist list)
{
    printf("Enter Employee ID : ");
    scanf("%3d", &list->data.id);
    while (getchar() != '\n');
    printf("Enter Name : ");
    list->data.name= (char*)malloc(BUFFER_SIZE);
    if (list->data.name == NULL)
    {
        printf("Memory Allocation Failure \n");
        return;
    }
    fgets(list->data.name,BUFFER_SIZE,stdin);
    list->data.name[strcspn(list->data.name, "\n")] = '\0'; 
    printf("Enter Position : ");
    list->data.position = (char*)malloc(BUFFER_SIZE);
    fgets(list->data.position,BUFFER_SIZE,stdin);
    list->data.position[strcspn(list->data.position, "\n")] = '\0'; 
    printf("Enter Salary : ");
    scanf("%d", &list->data.salary);
    printf("\n");
}

void display(Linkedlist list)
{
    if (list==NULL)
    {
        printf("Employee List: (empty)\n\n");
    }
    
    printf("ID \tName\t\t\tPosition\t\tSalary\n");
    printf("-----------------------------------------------------------------------------\n");
    if(list==NULL)
    printf("(empty)\n");
    Linkedlist tm = list;
    while (tm!=NULL)
    {
        printf("%3d\t%s\t\t%s\t\t%d\n", tm->data.id, tm->data.name,tm->data.position, tm->data.salary);
        tm= tm->next;
    }
}

void searchbyId(int num, Linkedlist list)
{
    int flag=0;
    Linkedlist tm = list;
    while (tm!=NULL)
    {
        if (num==tm->data.id)
        {
            flag =1;
            printf("Employee found!\n\n");
            display(tm);
        }
        tm=tm->next;
    }
    if (flag==0)
    {
        printf("Employee NOT found!!\n\n");
    }
    free(tm);
}

void updateSalary(int id, int newsalary, Linkedlist list)
{
    int flag=0;
    Linkedlist tm = list;
    while (tm!=NULL)
    {
        if (tm->data.id==id)
        {
            flag=1;
            tm->data.salary=newsalary;
        }
        tm=tm->next;
    }
    if(flag==1)
    {
        printf("Salary updated successfully!\n\n");
    }    
    else if(flag ==0)
    {
        printf("Employee ID NOT found!!\n\n");
    }
    free(tm);
}

Node* delete(int num,Linkedlist list)
{
    int flag=0;
    if(list==NULL)
    {
        printf("(empty)\n");
        return NULL;
    }
    if (list->next==NULL&& list->data.id==num)
    {
        freeList(list);
        return NULL;
    }
    
    Linkedlist tm = list;
    Linkedlist address;
    while (tm->next!=NULL)
    {
        if(tm->next->data.id==num)
        {
            address= tm->next->next;
            freeList(tm->next);
            tm->next= address;
        }
        tm = tm->next;
    }
    printf("Employee deleted successfully!\n\n");
    free(tm);
    free(address);
    return list;
}

void freeList(Linkedlist list)
{
    free(list->data.name);
    free(list->data.position);
    free(list->next);
    free(list);

}