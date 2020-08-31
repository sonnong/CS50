#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // Assign key
        int k = atoi(argv[1]);

        // Prompt user for plaintext
        string p = get_string("Enter plaintext: ");

        // Print ciphertext
        printf("ciphertext: ");

        for (int i = 0, n = strlen(p); i < n; i++)
        {
            // Check if character is letter and shift
            if (isalpha(p[i]))
            {
                // Declare index modifier
                int m;

                if (isupper(p[i]))
                {
                    m = 65;
                }
                if (islower(p[i]))
                {
                    m = 97;
                }

                // Anphabetical index
                int index = p[i] - m;

                // Enciphered ASCII
                int c = ((index + k) % 26) + m;

                // Print enciphered character
                printf("%c", c);
            }
            else
            {
                printf("%c", p[i]);
            }

        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
}
