#include <stdio.h>

char *getMonth(int m)
{
    switch (m)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        return "Invalid Input";
    }
}
char *getSuffix(int d)
{
    if (d%10 == 1)
        return "st";
    else if (d%10 == 2)
        return "nd";
    else if (d%10 == 3)
        return "rd";
    else
        return "th";
}

int getNumberOfDays(int m, int y)
{
    switch (m)
    {
    case 1:
        return 31;
    case 2:
        if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
            return 29;
        else
            return 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    default:
        return -1;
    }
}

//Zellerś congruence Algorithm

int dayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return (h + 5) % 7 + 1; 
}

void printCalendar(int d, int m, int y)
{
    printf("%s %d%s, %d \n", getMonth(m), d, getSuffix(d), y);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    int i,j;
    int dayCounter=1;
    int numDays = getNumberOfDays(m,y);
    int startDay = dayOfWeek(1,m,y);
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 7; j++) {
            if (i == 0 && j < startDay) {
                int prevMonthDays = getNumberOfDays(m - 1, y);
                    printf("%d  ", prevMonthDays - startDay + j + 1);
            } else if (dayCounter <= numDays) {
                printf("%2d", dayCounter);
                if (dayCounter == d) {
                    printf("* ");
                } else {
                    printf("  ");
                }
                dayCounter++;
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }   
       
}
