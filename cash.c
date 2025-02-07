#include <cs50.h>
#include <stdio.h>

int calculate_quarter(int c);
int calculate_dime(int c);
int calculate_nickel(int c);
int calculate_penny(int c);

int main(void)
{
    // ask user for total change owed
    int c;
    do
    {
        c = get_int("Change owed: ");
    }
    while (c < 0);

    // calculate no. quarters
    int quarter = calculate_quarter(c);

    // subtract no. quarters from c
    c = c - (quarter * 25);

    // calculate no. dimes
    int dime = calculate_dime(c);

    // subtract no. dimes from c
    c = c - (dime * 10);

    // calculate no. nickels
    int nickel = calculate_nickel(c);

    // subtract no. nickels from c
    c = c - (nickel * 5);

    // calculate no. pennies
    int penny = calculate_penny(c);

    // subtract no. pennies from c
    c = c - penny;

    // sum total coins used
    int coins = (quarter + dime + nickel + penny);

    // print total
    printf("%d\n", coins);
}

// function for calculating quarters
int calculate_quarter(int c)
{
    int quarter = 0;
    while (c >= 25)
    {
        c = c - 25;
        quarter++;
    }
    return quarter;
}

// function for calculating dimes
int calculate_dime(int c)
{
    int dime = 0;
    while (c >= 10)
    {
        c = c - 10;
        dime++;
    }
    return dime;
}

// function for calculating nickels
int calculate_nickel(int c)
{
    int nickel = 0;
    while (c >= 5)
    {
        c = c - 5;
        nickel++;
    }
    return nickel;
}

// function for calculating pennies
int calculate_penny(int c)
{
    int penny = 0;
    while (c >= 1)
    {
        c--;
        penny++;
    }
    return penny;
}
