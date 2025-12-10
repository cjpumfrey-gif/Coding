#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Determines whether a given year is a leap year.
 * A leap year must be divisible by 4, but not by 100,
 * unless it is also divisible by 400.
 * @param year The year to be checked.
 * @return bool True if it is a leap year, False otherwise.
 */

bool is_leap_year(int year) {
    // The logic is: (Divisible by 4) AND ((NOT divisible by 100) OR (Divisible by 400))
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

int main() {
    int year;

    printf("Pick a year between 1800 and 10000: \n");

    if (scanf("%d", &year) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    // Input validation (optional, but good practice)
    if (year < 1800 || year > 10000) {
        printf("The year %d is outside the requested range.\n", year);
    }

    // Call the is_leap_year function and use a conditional statement (ternary operator)
    // to output the result based on the boolean return value (true or false).
    if (is_leap_year(year)) {
        printf("\nRESULT: %d is a Leap Year.\n", year);
    } else {
        printf("\nRESULT: %d is Not a Leap Year.\n", year);
    }

    return 0;
}
