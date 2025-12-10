#include <cs50.h>
#include <ctype.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// "Prototypes" for our helper functions.
// This tells main() that these functions exist, even though they are defined later.
bool is_all_digits(string s);
char rotate(char c, int k);

int main(int argc, string argv[])
{
    // --- 1. VALIDATE THE KEY ---

    // Validation 1: Check for the wrong number of arguments.
    // argc is the "argument count".
    // argv[0] is the program's name (./caesar)
    // argv[1] is the key (e.g., "13")
    // So, we need argc to be exactly 2.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1; // 1 signifies an error
    }

    // Validation 2: Check if the key (argv[1]) contains only digits.
    if (!is_all_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // --- 2. CONVERT KEY & GET PLAINTEXT ---

    // The key is valid. Now we convert the string "13" to the int 13.
    // atoi ("ASCII to integer") is from stdlib.h
    int k = atoi(argv[1]);

    // Get the plaintext from the user
    string plaintext = get_string("plaintext:  "); // 2 spaces

    // --- 3. ENCRYPT & PRINT CIPHERTEXT ---

    printf("ciphertext: "); // 1 space

    // Loop over every character in the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Get the i-th character
        char c = plaintext[i];

        // Rotate the character using our helper function
        char rotated_char = rotate(c, k);

        // Print the single rotated character
        printf("%c", rotated_char);
    }

    // --- 4. FINISH UP ---

    // Print the final newline
    printf("\n");
    return 0; // 0 signifies success
}

/**
 * Helper function: Checks if a string is composed entirely of digits.
 */
bool is_all_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // isdigit() is from ctype.h
        // It returns false if the char is not a digit (0-9).
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    // If we get through the whole loop, all chars were digits.
    return true;
}


char rotate(char c, int k)
{
    // If the character is not a letter, return it unchanged.
    if (!isalpha(c))
    {
        return c;
    }

    // Determine the "base" ASCII value: 'A' (65) for uppercase, 'a' (97) for lowercase.
    char base = isupper(c) ? 'A' : 'a';

    // 1. Convert ASCII ('A'-'Z') to alphabetical index (0-25)
    int alpha_index = c - base;

    // 2. Apply the Caesar formula: (p_i + k) % 26
    //    This adds the key and wraps around 26.
    int rotated_index = (alpha_index + k) % 26;

    // 3. Convert the new index (0-25) back to ASCII ('A'-'Z')
    char rotated_char = rotated_index + base;

    return rotated_char;
}
