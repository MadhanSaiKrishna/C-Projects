// Write a program, which takes an input a date and prints the month calendar where that date belongs.
#include <stdio.h>
#include "functions.h"
#include <time.h>

int main()
{
    int d, m, y;
    scanf("%d %d %d", &d, &m, &y);
    if ((d>0 && d<32)&&(m>0 && m<13)&&(y>0))
    {
        printCalendar(d,m,y);
    }
    else
    {
        printf("**Wrong Input**\n");
    }
    return 0;
}
