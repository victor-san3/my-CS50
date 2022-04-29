/* Program to loop and print a bit more complex pyramid like below:
   #  #
  ##  ##
 ###  ###
####  ####
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = height; i > 0; i--)
    {
        for (int j = 1; j < i; j++)
        {
            printf(" ");
        }
        for (int k = height; k >= i; k--)
        {
            printf("#");
        }
        printf("  ");
        for (int l = i; l <= height; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
