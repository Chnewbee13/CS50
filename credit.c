#include <cs50.h>
#include <stdio.h>

int checksum(long c);
int getlength(long c);
int getFirstDigit(long c);
int getFirstTwoDigits(long c);

int main(void)
{
    // get the user's card number
    long c;
    do
    {
        c = get_long("Number: ");
    }
    while (c < 0);

    // checksum
    int sum = checksum(c);
    if ((sum % 10) != 0)
    {
        printf("INVALID\n");
    }

    else // check for card number length and starting digits
    {
        int length = getlength(c);
        int firstDigit = getFirstDigit(c);
        int firstTwoDigits = getFirstTwoDigits(c);

        // check VISA
        if (((length == 13) || (length == 16)) && (firstDigit == 4))
        {
            printf("VISA\n");
        }

        // check AMEX
        else if ((length == 15) && ((firstTwoDigits == 34) || (firstTwoDigits == 37)))
        {
            printf("AMEX\n");
        }

        // check MASTERCARD
        else if ((length == 16) &&
                 ((firstTwoDigits == 51) || (firstTwoDigits == 52) || (firstTwoDigits == 53) ||
                  (firstTwoDigits == 54) || (firstTwoDigits == 55)))
        {
            printf("MASTERCARD\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
}

int checksum(long c)
{
    long n = c;
    int sum = 0;
    int digit;
    int digit1;
    int digit2;
    int digit2a;
    int digit2b;
    while (n > 0)
    {
        digit1 = n % 10;
        n /= 10;
        sum = sum + digit1;

        digit2 = n % 10;
        n /= 10;
        digit2 = digit2 * 2;
        digit2a = digit2 % 10;
        digit2b = digit2 / 10;
        sum = sum + digit2a + digit2b;
    }
    return sum;
}

int getlength(long c)
{
    long m = c;
    int length = 0;
    while (m > 0)
    {
        m /= 10;
        length++;
    }
    return length;
}

int getFirstDigit(long c)
{
    long o = c;
    while (o > 9)
    {
        o /= 10;
    }
    return o;
    int firstDigit = o;
}

int getFirstTwoDigits(long c)
{
    long p = c;
    while (p > 99)
    {
        p /= 10;
    }
    return p;
    int firstTwoDigits = p;
}
