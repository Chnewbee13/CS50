#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int repeated_letters(string key);

int main(int argc, string argv[])
{
    // if no command line arguments entered, or more than one, display error
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int j = 0;
    int key_length = strlen(key);

    // if more or fewer than 26 characters entered, display error
    if (key_length != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    // if non-alphabetical characters entered, display error
    while (j < 26)
    {
        if (isalpha(key[j]))
        {
            j++;
        }
        else
        {
            printf("Key must only contain letters\n");
            return 1;
        }
    }

    // if any letters have been repeated, display error
    int repeat = repeated_letters(key);

    if (repeat > 0)
    {
        printf("Key must not contain repeated letters\n");
        return 1;
    }

    // get input text
    string plaintext = get_string("plaintext:  ");

    // encrypt plan text using key

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int k = (plaintext[i] - 65);
                printf("%c", (toupper(key[k])));
            }

            if (islower(plaintext[i]))
            {
                int k = (plaintext[i] - 97);
                printf("%c", (tolower(key[k])));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
    return 0;
}

int repeated_letters(string key)
{
    int repeat = 0;
    for (int a = 0; a < 25; a++)
    {
        for (int b = (a + 1); b < 26; b++)
        {
            if (toupper(key[a]) == toupper(key[b]))
            {
                repeat++;
            }
        }
    }
    return repeat;
}
