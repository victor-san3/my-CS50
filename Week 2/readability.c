// In this program we will use Coleman-Liau index to determine the approximate grade level needed to comprehend a given text

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Prototypes declarations
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Stores the text input we will work on
    string text = get_string("Text: ");

    // Variable to count the input's letters, words and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Coleman-Liau index's two variables
    // Average number of letters per 100 words in the text
    double average_letters = ((double)letters / words) * 100;
    // Average number of sentences per 100 words in the text
    double average_sentences = ((double)sentences / words) * 100;

    // Coleman-Liau index formula
    double grade_formula = 0.0588 * average_letters - 0.296 * average_sentences - 15.8;

    // Loop to printf the corresponding grade, according to Coleman-Liau index
    if (grade_formula < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_formula >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(grade_formula));
    }

}

// Function to calculate how many letters are in the text
int count_letters(string text)
{
    // Stores input's length
    int length = strlen(text);
    // Counts how many times the loop will run, hence how many letter
    int counter = 0;


    for (int i = 0; i < length; i++)
    {
        // Checks if index character is uppercase
        if (isupper(text[i]))
        {
            // Converts any uppercase character to lowercase
            text[i] = tolower(text[i]);
        }

        // Since the loop above already converted every uppercase to lowercase we are just checking a-z instead of a-z && A-Z
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            counter++;
        }
    }

    return counter;
}

// Function to calculate how many words are in the text
int count_words(string text)
{
    // Stores input's length
    int length = strlen(text);
    // Loop counter
    int counter = 0;

    for (int i = 0; i <= length; i++)
    {
        // Checks for spaces to count words and checks for the NUL caracter at the end of the text to count the last word
        if (text[i] == 32 || text[i] == '\0')
        {
            counter++;
        }
    }

    return counter;
}

// Function to calculate the number of sentences in the text, for every time it hit on specific characters
int count_sentences(string text)
{
    int length = strlen(text);
    int counter = 0;

    // This loop will count every time it detects periods, exclamation marks and question marks
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            counter++;
        }
    }

    return counter;
}
