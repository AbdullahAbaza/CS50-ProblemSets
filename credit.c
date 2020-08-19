#include <stdio.h>
#include <cs50.h>
// recall functions
bool check_validity(long number);
int find_length(long number);
bool checksum(long number);
void print_brand(long number);

int main(void)
{
    // prompting the user for input
    long number;
    do
    {
        number = get_long("Number: ");

    }
    while (number < 0);
    // printing the brand if the check validity function returns true, if not printing invalid
    if (check_validity(number) == true)
    {
        print_brand(number);
    }
    else
    {
        printf("INVALID\n");
    }

}
/* checking the validity of the card by comparing the credit number's length to the standard length
and making sure that the checksum function returns true at the same time */

bool check_validity(long number)
{
    int len = find_length(number);

    return (len == 13 || len == 15 || len == 16) && checksum(number);
}

// finding the length of the input card number
int find_length(long number)
{
    // deviding the card number by 10 and adding 1 to the variable len for each time untill the number becomes 0
    int len;
    for (len = 0; number != 0; len++)
    {
        number /= 10;
    }
    return len;
}

// calculating the checksum
bool checksum(long number)
{
    /* initiating the variable len as an int and assigning it to 0 the starting a for loop that
    initiates a variable i that starts from 0 and add 1 to it every time the card number is
    devided by 10 */
    int sum = 0;
    for (int i = 0; number != 0; i++, number /= 10)
    {
        if (i % 2 == 0)
        {
            sum += number % 10;
        }
        /* making sure that every other number from the seconed to the last digit when multiplied
            by 2 the and the result is a 2 digit number to split them and add them then add the result to the sum variable */
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
    // the (e+number) refers to how many zeros after the number befor e
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