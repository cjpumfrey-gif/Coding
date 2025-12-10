#include <stdio.h>

int main(void) {
    int month, day, year;

    // 1. Get User Input
    printf("Enter date (mm/dd/yyyy):\n");
    printf("Enter Month (1-12):\n");
    scanf("%d", &month);
    printf("Enter Day (1-31):\n");
    scanf("%d", &day);
    printf("Enter Year (yyyy):\n");
    scanf("%d", &year);

    printf("\nFormatted Date: ");

    // 2. Print the Month in Words (Switch Statement)
    switch (month) {
        case 1:  printf("January");   break;
        case 2:  printf("February");  break;
        case 3:  printf("March");     break;
        case 4:  printf("April");     break;
        case 5:  printf("May");       break;
        case 6:  printf("June");      break;
        case 7:  printf("July");      break;
        case 8:  printf("August");    break;
        case 9:  printf("September"); break;
        case 10: printf("October");   break;
        case 11: printf("November");  break;
        case 12: printf("December");  break;
        default:
            printf("Invalid Month");
            return 1; // Exit program on invalid input
    }

    // Print the day number
    printf(" %d", day);

    // 3. Print the Suffix for the Day (If/Else If Logic)

    // Check for the exception cases: 11, 12, 13 (always 'th')
    if (day == 11 || day == 12 || day == 13) {
        printf("th");
    }
    // Check the last digit (using modulo % 10)
    else if (day % 10 == 1) {
        printf("st");
    }
    else if (day % 10 == 2) {
        printf("nd");
    }
    else if (day % 10 == 3) {
        printf("rd");
    }
    // Default case for all other numbers (4, 5, 20, 24, etc.)
    else {
        printf("th");
    }

    // 4. Print the Year
    printf(", %d\n", year);

    return 0;
}
