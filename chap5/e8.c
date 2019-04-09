#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31}
};

int main() {
    int day_of_year(int year, int month, int day);
    void month_day(int year, int dayth, int *month, int *day);
    int month, day;
    
    month_day(2019, 99, &month, &day);
    printf("%d\n", day_of_year(2019, 4, 9));
    printf("%d  %d\n", month, day);
    return 0;
}

int day_of_year(int year, int month, int day) {
    int isleap(int year);
    int i, leap, dayth;

    if (month < 0 || month > 12)
        return -1;
    leap = isleap(year);
    for (i = 1, dayth = day; i < month; i++) {
        dayth += daytab[leap][i];
    }
    return dayth;
}

void month_day(int year, int dayth, int *month, int *day) {
    int isleap(int year);
    int i, leap;
    leap = isleap(year);
    if (dayth - leap > 365 || dayth < 0) {
        *month = -1;
        *day = -1;
    }

    for (i = 1; i <= 12; i++) {
        if (dayth > daytab[leap][i])
            dayth -= daytab[leap][i];
        else
            break;
    }
    *month = i;
    *day = dayth;
}

int isleap(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
