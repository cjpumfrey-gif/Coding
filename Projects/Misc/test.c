#include <stdio.h>
#include <stdlib.h>

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


    char input_buffer[20];

    printf("Enter weight: ");
    fgets(input_buffer, 20, stdin);

    earth_weight = strtod(input_buffer, NULL);

    printf("You entered a weight of: %lf\n", earth_weight);

    return 0;
    }

