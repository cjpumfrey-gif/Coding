#include <cs50.h>
#include <ctype.h> // For isalpha()
#include <math.h>  // For round()
#include <stdio.h>
#include <string.h> // For strlen()

int main(void)
{
    // 1. Get input text from the user
    string text = get_string("Text: ");
    // 2. Initialize counters
    int letter_count = 0;
    // We start word_count at 1, because the prompt assumes
    // no leading/trailing spaces. A text with 0 spaces has 1 word.
    int word_count = 1;
    int sentence_count = 0;
    // 3. Loop through the entire text, one character at a time
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Get the current character
        char c = text[i];

        // Check if it's a letter (from ctype.h)
        if (isalpha(c))
        {
            letter_count++;
        }
        // Check if it's a space (our word separator)
        else if (c == ' ')
        {
            word_count++;
        }
        // Check if it's a sentence-ending punctuation
        else if (c == '.' || c == '!' || c == '?')
        {
            sentence_count++;
        }
    }

    // 4. Calculate L and S (Coleman-Liau variables)
    // L = average letters per 100 words
    // S = average sentences per 100 words
    // We MUST cast these to (float) to avoid integer division!
    float L = ((float) letter_count / (float) word_count) * 100.0;
    float S = ((float) sentence_count / (float) word_count) * 100.0;
    // 5. Calculate the index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // 6. Round the index to the nearest integer
    // round() comes from math.h
    int grade = round(index);
    // 7. Print the final grade based on the rules
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}
