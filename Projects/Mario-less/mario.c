#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for pyramid height
    int height;
    do
    {
        height = get_int("Height: "); // Good practice to capitalize "Height: "
    }
    while (height <= 0);

    // Print a pyramid of entered height
    for (int i = 1; i <= height; i++)
    {
        // 1. Print the spaces first
        for (int j = 0; j < (height - i); j++)
        {
            printf(" ");
        }

        // 2. Then, print the hashes
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        // 3. print a new line to end the row
        printf("\n");
    }
    // The main loop ends here
}
