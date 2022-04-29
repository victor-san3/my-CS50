// Caesar’s cipher encryption method for text

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

// Functions prototypes
bool only_digits(string s);
char rotate(char c, int key);


int main(int argc, string argv[])
{
    // Tests if the program is called with one command-line argument
    if (argc != 2)
    {
        // Printf message error and return 1
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Logic variable to call the 'only_digits' function in order to test if the argument is a sequence of numbers
    bool valid = only_digits(argv[1]);

    // If not valid i.e., the command-line argument isn't one or a sequence of positive integers, we print the same error message and return 1
    if (!valid)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Variable to store the converted string command-line argument into a positive integer. The so-called 'Key'
    int key = atoi(argv[1]);

    string plain = get_string("plaintext:  ");

    printf("ciphertext: ");

    // We iterate through every character of the plaintext string, passing each of them to the function, alongside with our key number
    for (int i = 0; i < strlen(plain); i++)
    {
        // We will print every ciphered character seprately to build our ciphertext
        printf("%c", rotate(plain[i], key));
    }

    printf("\n");
    return 0;
}


// This function will check every character in the command-line argument string and return true if all of them are positive integers, and false if othewise
bool only_digits(string s)
{
    // The variable value to be returned by the function
    bool valid = false;

    // Loop to iterate through every character of the string s
    for (int i = 0; i < strlen(s); i++)
    {
        // Sets the output to be true
        if (isdigit(*(s + i)))
        {
            valid = true;
        }
        else
        {
            // If the iteration faces any non-alphabetic character in the array, it sets the test condition to be false and break the flow
            valid = false;
            break;
        }
    }
    // Returns the value
    return valid;
}


// This functions is, per se, the algorithm needed to encrypt the plaintext, letter by letter
char rotate(char c, int key)
{
    // This array will store every uppercase letter in the alphabet
    char upper[26];

    // While this array will store every lowercase letter in the alphabet
    char lower[26];

    // Size of both arrays
    int size = 25;

    // This variable is necessary to identify the correlation of which position the plaintext character is, relatively to the arrays indexes declared above.
    // For instance, if the plain character is 'a', then its correlation is lower[0]; 'b' lower[1]; 'A' is upper[0] and so on
    int plainchar;

    // This variable will store the position of the ciphered character in relation to the arrays declared above. If the ciphered character is 'a' or 'A' then this variable will be 0.
    // Because 0 will access the first element (a or A) of each array
    int chiperchar_index;

    // Assignment of uppercase array 'A to Z'
    // The variable j holds the ASCII value of the letters
    for (int i = 0, j = 65; i <= size; i++, j++)
    {
        upper[i] = j;
    }

    // Assignment of lowercase array 'a to z'
    // The variable j holds the ASCII value of the letters
    for (int i = 0, j = 97; i <= size; i++, j++)
    {
        lower[i] = j;
    }

    // Checks if c is uppercase
    if (isupper(c))
    {
        // This loop will check c correlation in the upper array
        for (int i = 0; i <= size; i++)
        {
            if (c == *(upper + i))
            {
                plainchar = i;
            }
        }
        // cipherchar will now get the sum of the plaintext character index in the upper array and the key MOD 26
        chiperchar_index = (plainchar + key) % 26;
        // The result of the above equation tells us in which position in the array the ciphered character element is located, hence returning the wanted character
        return upper[chiperchar_index];
    }

    // Checks if c is lowercase and perform every step as the loop above, except it'll access the lower array
    else if (islower(c))
    {
        for (int i = 0; i <= size; i++)
        {
            if (c == *(lower + i))
            {
                plainchar = i;
            }
        }
        chiperchar_index = (plainchar + key) % 26;
        return lower[chiperchar_index];
    }
    // Return non-alphabetic characters unchanged
    else
    {
        return c;
    }
}
