#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else
    {
        string s = argv[1];
        int j = 0;
        int m = strlen(s);
        while (j < m)
        {
            if (isdigit(s[j]))
            {
                j++;
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        int k = atoi(s);

        string plaintext = get_string("plaintext:  ");

        printf("ciphertext: ");

        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if (isalpha(plaintext[i]))
            {
                if (isupper(plaintext[i]))
                {
                    printf("%c", (((plaintext[i] + k - 65) % 26) + 65));
                }

                if (islower(plaintext[i]))
                {
                    printf("%c", (((plaintext[i] + k - 97) % 26) + 97));
                }
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
