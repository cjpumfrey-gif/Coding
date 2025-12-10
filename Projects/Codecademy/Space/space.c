#include <stdio.h>

int main() {

    int planet_choice;
    double earth_weight;
    double Mercury =	0.38;
    double	Venus =	0.91;
    double	Mars =	0.38;
    double	Jupiter =	2.34;
    double	Saturn =	1.06;
    double	Uranus =	0.92;
    double	Neptune =	1.19;
    double target_weight;


    printf("Enter weight: ");
    scanf("%lf", &earth_weight);

    printf("Select a planey by number:\n");
    printf("1. Mercury\n");
    printf("2. Venus\n");
    printf("3. Mars\n");
    printf("4. Jupiter\n");
    printf("5. Saturn\n");
    printf("6. Uranus\n");
    printf("7. Neptune\n");
    printf("Enter your choice: ");

    scanf("%d", &planet_choice);

  switch (planet_choice) {
    case 1:
    target_weight = earth_weight * Mercury;
    break;
    case 2:
    target_weight = earth_weight * Venus;
    break;
    case 3:
    target_weight = earth_weight * Mars;
    break;
    case 4:
    target_weight = earth_weight * Jupiter;
    break;
    case 5:
    target_weight = earth_weight * Saturn;
    break;
    case 6:
    target_weight = earth_weight * Uranus;
    break;
    case 7:
    target_weight = earth_weight * Neptune;
    break;

    default:
        printf("Error: not a valid option");
        return 1;
    }



printf("Your weight on that planet is: %lf\n", target_weight);




    return 0;
    }

