#include <stdio.h>
#include <cs50.h>
#include <unistd.h>

int main(void)
{
    int x = get_int("x == ");
    int y = get_int("y == ");
    if (x < y)
    {
    printf("x is less than y\n");
    }
    else if (x > y)
    {
    printf("x is greater than y\n");
    }
    else
    {
    printf("x is equal to y\n");
    }

    int i = 0;
    while (i < 10)
    {
    printf("i is less than 10\n");
    sleep(1);
    i++;
    }
    for (int l = 0; l < 10; l++)
    {
    printf("this is a for loop\n");
    sleep(1);
    }
}