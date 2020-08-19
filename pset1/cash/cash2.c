//Greedy Algorithms

#include <stdio.h>
#include <cs50.h>
#include <math.h>

float change(void);

int main(void)
{
    float n = change();
    int cents = round(n * 100);
    int coins = 0;

    int denominations[] = {25, 10, 5, 1};
    int size = sizeof(denominations)/sizeof(int);
    for (int i = 0; i < size; i++)
    {
        coins += cents / denominations[i];
        cents %= denominations[i];
    }
    printf("%i\n", coins);
}

float change(void)
{
    float n;
    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0);
    return n;
}

/*while (number > 0)
    {
    int digit = number%10;
    number /= 10;
    printf("%i\n", digit);
    }
    /*