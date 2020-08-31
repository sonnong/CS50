#include <stdio.h>
#include <cs50.h>
int main(void)
{
    // Promt for user input
    long long n;
    do
    {
        n = get_long_long("Number: ");
    }
    while (n < 0);

    // Calculate checksum
    int sum1, sum2;
    long long i = n;

    // Sum of products digits (every other digit starting with second-to-last)
    sum1 = 0;
    do
    {
        n = (n - (n % 10)) / 10;
        int m = n % 10;
        if (m < 5)
        {
            sum1 = sum1 + (m * 2);
        }
        else
        {
            sum1 = sum1 + (m * 2 % 10) + 1;
        }
        n = (n - (n % 10)) / 10;
    }
    while (n >= 10);

    // Sum of remaining digits
    sum2 = 0;

    // Count digits
    int j = 0;
    int k = 0;
    // First 2 digits
    int l = 0;

    do
    {
        if (i < 10)
        {
            k = 1;
        }

        if (10 <= i && i < 100)
        {
            l = i;
        }

        if (100 <= i && i < 1000)
        {
            l = (i - (i % 10)) / 10;
        }

        sum2 = sum2 + i % 10;
        i = (i - (i % 100)) / 100;
        j++;
    }
    while (i > 0);

    // Checksum and print output
    if (((sum1 + sum2) % 10) == 0)
    {
        if (((2 * j - k) == 15) && (l == 34 || l == 37))
        {
            printf("AMEX\n");

        }
        else
        {
            if (((2 * j - k) == 16) && (51 <= l && l <= 55))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                if ((((2 * j - k) == 13) || (2 * j - k) == 16) && (((l - (l % 10)) / 10) == 4))
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }

}