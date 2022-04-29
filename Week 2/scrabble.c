// Implementation of a simple scrabble game

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print winners
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
    // Output variable
    int score = 0;

    // The first layer of this loop will iterate through every letter of the function argument
    for (int i = 0; i < strlen(word); i++)
    {
        // In this layer we defined j variable to hold the ASCII value of alphabetic letters and k to be a counter.
        for (int j = 'a', k = 0; j <= 'z'; j++, k++)
        {
            // Every time j matches a letter in word, we pass k value to index in POINTS. This way we can safely indicate in which position, related to the alphabet, the letter in the word argument is located, henceforth we easily access the corresponding element in variable POINTS
            // All letters are converted to lowercase to eliminate complexity since this version of scrabble is case-insensitive
            if (j == tolower(word[i]))
            {
                score += POINTS[k];
            }
        }
    }
    return score;
}
