// Write a program, which takes an input a date and prints the month calendar where that date belongs.
#include <stdio.h>
#include "functions.h"
#include <time.h>

int main()
{
    int d, m, y;
    scanf("%d %d %d", &d, &m, &y);
    printCalendar(d,m,y);
    return 0;
}