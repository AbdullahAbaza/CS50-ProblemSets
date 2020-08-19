#include <stdio.h>
#include <cs50.h>

bool check_validity(long number);
int find_length(long number);
bool checksum(long number);
void print_brand(long number);

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");

    }
    while (number < 0);

    if (check_validity(number) == true)
    {
        print_brand(number);
    }
    else
    {
        printf("INVALID\n");
    }

}

bool check_validity(long number)
{
    int len = find_length(number);

    return (len == 13 || len == 15 || len == 16) && checksum(number);
}

int find_length(long number)
{
    int len;
    for (len = 0; number != 0; len++)
    {
        number /= 10;
    }
    return len;
}

bool checksum(long number)
{
    int sum = 0;
    for (int i = 0; number != 0; i++, number /= 10)
    {
        if (i % 2 == 0)
        {
            sum += number % 10;
        }
        else
        {
            int digit = (number % 10) * 2;
            sum += digit / 10 + digit % 10;
        }
    }
    return (sum % 10) == 0;
}
//brand function takes the credit card number and checks for the brand
void print_brand(long number)
{
    if ((number >= 34e13 && number < 35e13) || (number >= 37e13 && number < 38e13))
    {
        printf("AMEX\n");
    }
    else if (number >= 51e14 && number < 56e14)
    {
        printf("MASTERCARD\n");
    }
    else if ((number >= 4e15 && number < 5e15) || (number >= 4e12 && number < 5e12))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}