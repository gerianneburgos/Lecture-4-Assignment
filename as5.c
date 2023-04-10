#include <stdio.h>

#define min_days 28
#define max_days 31

int main() {
    int days, start_day;

    // prompts the user for number of days in the month
    printf("Enter number of days in the month: ");
    scanf("%d", &days);

    // checks if number of days in the month is valid
    if (days < min_days || days > max_days) {
        printf("Invalid number of days\n");
        return 1;
    }

    // prompts the user which day of the week will the month start
    printf("Enter the starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start_day);

    // checks if the start day is valid
    if (start_day < 1 || start_day > 7) {
        printf("Invalid start day\n");
        return 1;
    }

    // prints calendar header
    printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // prints leading spaces
    for (int i = 1; i < start_day; i++) {
        printf("     ");
    }

    // prints days of the month
    for (int i = 1; i <= days; i++) {
        printf("%4d", i);
        if ((i + start_day - 1) % 7 == 0) {
            printf("\n");
        }
    }

    // prints trailing new line
    printf("\n");

    return 0;
}

