#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int verify_digit(string argv[]);

int main(int argc, string argv[])
{
    //Check that program was run with one command-line argument
    while (argc != 2 || verify_digit(argv) == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Convert argv[1]  from a string to an int
    int K = atoi(argv[1]);

    //Prompt user for plaintext
    string P = get_string("plaintext: ");
    printf("\nciphertext: ");

    //ci = (pi + k) % 26
    //pi is the ith character in p
    // k is a secret key a non-negative integer
    //each letter, ci, in the ciphertext, c
    for (int i = 0, n = strlen(P); i < n; i++)
    {
        if (isupper(P[i]))
        {
            P[i] = (((P[i] - 'A') + K) % 26 + 'A');
            printf("%c", P[i]);
        }
        else if (islower(P[i]))
        {
            P[i] = (((P[i] - 'a') + K) % 26 + 'a');
            printf("%c", P[i]);
        }
        else
        {
            printf("%c", P[i]);
        }
    }
    printf("\n\nNote: If you want to decipher your text just substitute your key from 26 and use the result as the decipher key.\n");
}

//Iterate over the provided argument to make sure all characters are digits
int verify_digit(string argv[])
{
    int ver = 0;
    string key = argv[1];
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (! isdigit(key[i]))
        {
            return ver = 1;
        }
    }
    return ver;
}
