#include <cs50.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int s;
    int m;
    do
    {
        s = get_int("starting number: ");
        m = get_int("the maximum number to count to: ");
    }
    while (s >= m || s < 0);
    for (int i = s ; m >= i; i++)
    {
        printf("%i\n", i);
        sleep(1);
    }
}