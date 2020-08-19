//Greedy Algorithms

#include <stdio.h>
#include <cs50.h>
#include <math.h>

float change(void);

int main(void)
{
    float n = change();
    //round cents to the nearest penny
    int cents = round(n * 100);
    int coins = 0;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    //starting loops to subtract cents and add 1 to coins for every subtarction
    for (int i = 0; cents >= 25; i++)
    {
        cents = cents - 25;
        coins++;
        quarters++;
    }
    for (int j = 0; cents >= 10; j++)
    {
        cents = cents - 10;
        coins++;
        dimes++;
    }
    for (int x = 0; cents >= 5; x++)
    {
        cents = cents - 5;
        coins++;
        nickels++;
    }
    for (int y = 0; cents >= 1; y++)
    {
        cents = cents - 1;
        coins++;
        pennies++;
    }
    //print num of coins
    printf("number of coins you should give to the customer: %i\n", coins);
    //print how many quarters, dimes, nickels, pennies
    printf("%i quarters.\n%i dimes.\n%i nickels.\n%i pennies.\n", quarters, dimes, nickels, pennies);
}
//prompt the user for change
float change(void)
{
    float n;
    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0.001);
    return n;
}

/*we can use while loops for simplicity*/