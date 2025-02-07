#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int x = 0; x < n; x++)
    {
        for (int y = (n - x); y > 1; y--)
        {
            printf(" ");
        }
        for (int z = 0; z <= x; z++)
        {
            printf("#");
        }
        printf("  ");
        for (int z = 0; z <= x; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}
