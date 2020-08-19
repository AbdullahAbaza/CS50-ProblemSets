
#include <cs50.h>
#include <stdio.h>

void print(char c, int n);

int main(void)
{
    int n;
    do
    {
        // prompt user for input
        n = get_int("Hieght: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j < n - 1)
                printf(" ");
                else
                printf("#");

        }

        printf("  ");
        print('#', i + 1);
        printf("\n");
    }
}
void print(char c, int n)
{
    for (int x = 0; x < n; x++)
    {
        printf("%c", c);
    }
}
