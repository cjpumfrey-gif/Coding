#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Array or different points
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{

    // prompt user for two words
    string word1 = get_string("player 1: ");
    string word2 = get_string("player 2: ");

    // compute score of each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // print winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int total_score = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char letter = word[i];

        if (isupper(toupper(letter)))
        {
            int index = toupper(letter) - 'A';

            total_score += POINTS[index];
        }
    }

    return total_score;
}
