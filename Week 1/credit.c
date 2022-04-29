// This program will determine if a credit card's number is valid using Luhn’s Algorithm and will also output the card's label

#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int calculate_length(long card);
char determine_label(long card, int length);
bool validity(int checksum, int length);

int main(void)
{
    long card, y, z;
    int length, checksum;
    char label;
    bool valid;

    checksum = 0;
    card = get_long("Number: ");
    length = calculate_length(card);
    label = determine_label(card, length);

    // This loop is responsible for multiplying every other digit by 2; with i starting with the number’s second-to-last digit position
    for (long i = 100; i <= pow(10, length); i *= 100)
    {
        // Y is assigned to the modulo of card % i;
        y = fmod(card, i);
        // Y result updated to digit isolated
        y /= i / 10;
        // Multiplications of the digit by 2
        y *= 2;

        // Loop to check wether the y variable is 2 digit long
        if (y >= 10)
        {
            // Update y to sum each digit separately
            y = (y % 10) + (y / 10);
        }
        // Total sum of y multiplied by 2
        checksum += y;
    }

    // This loop will update the total sum with the sum of the digits that weren't multiplied by 2; with i starting with the last digit position
    for (long i = 10; i <= pow(10, length); i *= 100)
    {
        z = fmod(card, i);
        z /= i / 10;
        checksum += z;
    }

    // Checks the other two conditions for the card number's validity
    valid = validity(checksum, length);

    // Checks the conditions for each card type we've been working with
    // 'A', 'M' and 'V' are abstractions for each card label
    if (valid && label == 'A')
    {
        printf("AMEX\n");
    }
    else if (valid && label == 'M')
    {
        printf("MASTERCARD\n");
    }
    else if (valid && label == 'V')
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}


// Return an integer of digit number in a given credit card number
int calculate_length(long card)
{
    // The counter variable will give us how many times the card's number can be divided, hence giving the number of digits
    int counter = 0;

    // A loop to divide the card's number by 10 until there's no decimal places left
    do
    {
        card /= 10;
        counter++;
    }
    while (card > 0);

    return counter;
}


// Return the first letter of our 3 possible card's labels
char determine_label(long card, int length)
{
    int label;

    label = card / pow(10, length - 2);

    // 'A' stands for AMEX
    if (label == 34 || label == 37)
    {
        return 'A';
    }
    // 'M' stands for MASTERCARD
    else if (label >= 51 && label <= 55)
    {
        return 'M';
    }
    // 'V' stands for VISA
    else if (label / 10 == 4)
    {
        return 'V';
    }
    // Else state for compiling
    else
    {
        return ' ';
    }
}


// Return a boolean value if our total’s last digit is 0 and if the card's number is equal to or higher than 13 digits
bool validity(int checksum, int length)
{
    bool valid;

    if (checksum % 10 == 0 && length >= 13)
    {
        valid = true;
    }
    else
    {
        valid = false;
    }

    return valid;
}
