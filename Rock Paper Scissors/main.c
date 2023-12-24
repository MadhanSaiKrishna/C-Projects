#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int randomNumber(int n)
{
    srand(time(NULL));
    return ((rand()%n)+1);
}

int main()
{
    int ch;
    float comp = 0;
    float user=0;
    char name[100];
    int cmp = randomNumber(3);
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    printf("Enter your Name : ");
    scanf("%s", name);
    for (int i = 0; i < 3; i++)
    {
        printf("%s : ", name);
        scanf("%d", &ch);
        if (ch==1 && cmp ==2)
        {
            comp++;
        }
        else if (ch==1 && cmp ==3)
        {
            user++;
        }
        else if (ch==2 && cmp==1)
        {
            user++;
        }
        else if(ch==2 && cmp ==3)
        {
            comp++;
        }
        else if(ch==3 && cmp ==1)
        {
            comp++;
        }   
        else if(ch==3 && cmp ==2)
        {
            user++;
        }   
        else if(ch==cmp)
        {
            user+=0.5;
            comp+=0.5;
        } 
        
    }
    printf("Scores : \n %s : %.2f\nComputer : %.2f\n",name,user,comp);
    if(user>comp)
    {
        printf("%s won the game\n", name);
    }
    else if(comp>user)
    {
        printf("Computer won the game\n");
    }
    else if (user==comp)
    {
        printf("It's a TIE\n");
    }
    return 0;
}