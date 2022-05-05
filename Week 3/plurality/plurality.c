#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Iterate through every cadidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Checks if name arguments is equal to candidate's name and increments the vote counting
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Variable to determine how many votes the most voted candidate has
    int most_votes = 0;

    // We will iterate through every candidate to check who has been the most voted
    for (int i = 0; i < candidate_count; i++)
    {
        // If the i-th candidate has been the most voted, then our variable will be updated to this number
        if (candidates[i].votes > most_votes)
        {
            most_votes = candidates[i].votes;
        }
    }

    // Loop to print the name of the candidate or candidates with more votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == most_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}