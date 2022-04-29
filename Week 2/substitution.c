// Implementation of a substitution cipher for text encryption

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

_Bool valid(string s);
char cipher(char c, string key);

int main(int argc, string argv[])
{
    // Check whether user's inputted 2 command-line arguments or not; if not complied then we print an error message and return 1
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];

    // Check if user's input key meet all three conditions; if not, an error message is printed and return 1;
    if (!valid(key))
    {
        printf("Key must contain 26 alphabetic, non-repeated characters.\n");
        return 1;
    }

    // Variable to store the plaintext
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");
    // In this loop we simply pass each character of the plaintext to our cipher function and then print the ciphered characters one by one
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", cipher(plaintext[i], key));
    }
    printf("\n");
}


// Function in charge of chipering the c character into its matched key character
char cipher(char c, string key)
{
    // Our main working variable converts all passed characters to lowercase for processing
    char input = tolower(c);
    // Will hold the value of the ouput
    char output;

    // This loop will evaluate which element of the key array will correlate to our inputted character
    // Variable i being the index to key and variable j being all the alphabetic characters
    for (int i = 0, j = 'a'; i < strlen(key); i++, j++)
    {
        if (input == j)
        {
            // If c was originally lowercase, then output should be lowercase aswell, otherwise output will be uppercase
            return output = islower(c) ? tolower(key[i]) : toupper(key[i]);
        }
    }
    // Returns any non-alphabetic characters passed through c
    return c;
}


// This function will check for 3 conditions and return true or false
_Bool valid(string s)
{
    // Valid if containing 26 characters(condition1), containing only alphabetic character(condition2), and containing each letter exactly once(condition3)
    _Bool valid = false;

    // If the string is 26 character long, the condition 1 is true
    if (strlen(s) == 26)
    {
        valid = true;
        // Loop to iterate through every character in s string
        for (int i = 0; i < strlen(s); i++)
        {
            // If the i-th character is alphabetic, the condition 2 is true
            if (isalpha(s[i]))
            {
                valid = true;
            }
            // If the i-th character is non-alphabetic, the condition 2 is false
            else
            {
                valid = false;
                return valid;
            }
            // Nested loop to compare letter by letter
            for (int j = i + 1; j < strlen(s); j++)
            {
                // If non-repeated letter, then condition 3 is true
                if (s[j] != s[i])
                {
                    valid = true;
                }
                // If a letter is repeated, condition 3 is false
                else
                {
                    valid = false;
                    return valid;
                }
            }
        }
    }
    // If the string isn't 26 character long, the condition 1 is false
    else
    {
        valid = false;
        return valid;
    }
    return valid;
}
