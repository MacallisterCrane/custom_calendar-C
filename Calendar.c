#include <stdio.h>
#include <stdlib.h>

int get_first_weekday(int year) {
    int d;
    d = (((year-1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return d;
}
int main() {
    system("Color 1F");
    printf("...No need for panic! ~Just your local BSOD Calendar here!~ Enjoy!\n");
    int year, month, day, weekDay=0, daysInMonth, startingDay;
    printf("\nEnter your desired year:");
    scanf("%d", &year);

    int monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};
    char *months[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    if (year % 4 == 0 && year % 100 != 0 && year % 400 == 0) {
        monthDays[1]=29;
    }
    startingDay = get_first_weekday(year);
    for (month=0; month<12; month++) {
        daysInMonth = monthDays[month];
        printf("\n\n -----------%s-----------\n", months[month]);
        printf("\n Sun   Mon  Tue  Wed  Thu  Fri  Sat\n");

        for (weekDay=0; weekDay<startingDay; weekDay++)
            printf("     ");

        for (day=1;day<=daysInMonth;day++) {
            printf("%5d", day);
            if (++weekDay>6) {
                printf("\n");
                weekDay=0;
            }
            startingDay=weekDay;
        }
    }
    system("pause");
}
