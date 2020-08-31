#include <stdio.h>
#include <cs50.h>
int main(void)
{
    // Promt and validate user input
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);

    // Draw the pyramid
    for (int i = 0; i < n; i++)
    {
        // Print left pyramid
        for (int j = 0; j < (n - i - 1); j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");

        }

        // Print gap
        printf("  ");

        // Print right pyramid
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}