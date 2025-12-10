#include <stdio.h>

int main(void) {
  int month, day, year;

  // Standard date form
  printf("Enter date (mm/dd/yyyy):\n");
  printf("Enter Month:\n");
  scanf("%d", &month);
  printf("Enter Day\n");
  scanf("%d", &day);
  printf("Enter Year\n");
  scanf("%d", &year);



  // Print the month
  printf("\nYour date is: ");

  printf("%d/", day);

   switch (month) {
    case 1:
        printf("January");
        break; // Stop checking cases and exit the switch
    case 2:
        printf("February");
        break;
    case 3:
        printf("March");
        break;
    case 4:
        printf("April");
        break;
    case 5:
        printf("May");
        break;
    case 6:
        printf("June");
        break;
    case 7:
        printf("July");
        break;
    case 8:
        printf("August");
        break;
    case 9:
        printf("September");
        break;
    case 10:
        printf("October/");
        break;
    case 11:
        printf("November");
        break;
    case 12:
        printf("December");
        break;
    default:
        // This is the "catch-all" if the user enters a number outside 1-12
        printf("Invalid Month");
        break;
}
    printf("%d\n", year);


  return 0;
}
