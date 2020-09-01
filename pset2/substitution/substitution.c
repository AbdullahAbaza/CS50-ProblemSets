#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool verify_key(string key);
int main(int argc, string argv[])
{
    //terminating the program if the key is not valid
    string key = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (! verify_key(key))
    {
        printf("Key must contain 26 characters.\nand there mustn't be any duplicate characters.\n");
        return 1;
    }
    // prompting the user for the plaintext
    string P = get_string("plaintext: ");
    printf("\nciphertext: ");
    for (int i = 0; i < strlen(P);)
    {
        if (isupper(P[i]) || isspace(P[i]) || ispunct(P[i]) || isdigit(P[i]))
        {
            for (int j = 65, A = 0; j < 91; j++, A++)
            {
                if (P[i] == j)
                {
                    P[i] = toupper(key[A]);
                    printf("%c", P[i]);
                    i++;
                }
                else if (isspace(P[i]) || ispunct(P[i]) || isdigit(P[i]))
                {
                    printf("%c", P[i]);
                    i++;
                }
            }
        }
        else if (islower(P[i]) || isspace(P[i]) || ispunct(P[i]) || isdigit(P[i]))
        {
            for (int x = 97, a = 0; x < 123; x++, a++)
            {
                if (P[i] == x)
                {
                    P[i] = tolower(key[a]);
                    printf("%c", P[i]);
                    i++;
                }
                else if (isspace(P[i]) || ispunct(P[i]) || isdigit(P[i]))
                {
                    printf("%c", P[i]);
                    i++;
                }
            }
        }
    }
    printf("\n");
}
//checking the validity of the key
bool verify_key(string key)
{
    int len = strlen(key);
    if (len != 26)
    {
        return false;
    }
    for (int i = 0; i < len; i++)
    {
        //handling invalid characters in key
        if (! isalpha(key[i]))
        {
            return false;
        }
        //handling duplicate characters in key
        for (int j = i + 1; j < len; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
    return true;
}