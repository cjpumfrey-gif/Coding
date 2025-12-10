#include <cs50.h>
#include <stdio.h>
#include <string.h> // Required for strcmp

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Loop through all candidates to find a name match
    for (int i = 0; i < candidate_count; i++)
    {
        // Use strcmp to compare the input name with the candidate's name
        if (strcmp(name, candidates[i].name) == 0)
        {
            // If matched, store the *candidate's index* in the preferences array
            preferences[voter][rank] = i;
            return true; // Vote was successful
        }
    }

    // If no match is found after checking all candidates, it's an invalid vote
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Loop through each voter
    for (int i = 0; i < voter_count; i++)
    {
        // For each voter, loop through their ranks (j) from 1st choice onwards
        for (int j = 0; j < candidate_count; j++)
        {
            // Get the index of the candidate at this rank
            int candidate_index = preferences[i][j];

            // Check if this candidate is NOT eliminated
            if (!candidates[candidate_index].eliminated)
            {
                // If they are not eliminated, this is the voter's active choice
                // Increment their vote count
                candidates[candidate_index].votes++;

                // IMPORTANT: Break from the inner loop (j)
                // This voter's vote is counted, so move to the next voter (i)
                break;
            }
            // If candidates[candidate_index] *was* eliminated, the inner loop (j)
            // continues to check their next rank (j+1)
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // A winner needs more than 50% of the vote
    // We can check this by seeing if votes > voter_count / 2

    // Loop through all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if any candidate has more than half the votes
        if (candidates[i].votes > (voter_count / 2))
        {
            // If so, they are the winner
            printf("%s\n", candidates[i].name);
            return true; // Signal that a winner was found
        }
    }

    // If no candidate has a majority, return false
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Start with a high number (max possible votes)
    int min_votes = voter_count;

    // Loop through all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Only consider candidates who are NOT eliminated
        if (!candidates[i].eliminated)
        {
            // If this candidate's votes are less than the current minimum
            if (candidates[i].votes < min_votes)
            {
                // Update the minimum
                min_votes = candidates[i].votes;
            }
        }
    }

    // Return the final minimum value
    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Loop through all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // We only care about non-eliminated candidates
        if (!candidates[i].eliminated)
        {
            // If we find even ONE non-eliminated candidate
            // whose votes are NOT equal to the minimum...
            if (candidates[i].votes != min)
            {
                // ...then it is NOT a tie.
                return false;
            }
        }
    }

    // If the loop finishes, it means every non-eliminated candidate
    // had exactly 'min' votes. This is a tie.
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Loop through all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // If a candidate (even one already eliminated, though it doesn't matter)
        // has the minimum number of votes...
        if (candidates[i].votes == min)
        {
            // ...eliminate them.
            candidates[i].eliminated = true;
        }
    }
    return;
}
