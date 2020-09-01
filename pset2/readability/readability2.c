#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int index(string text);
int main(void)
{
    string text = get_string("Text: ");
    int grade = index(text);
    //printing Grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
int index(string text)
{
    //store letters, words and sentences as a float
    int l, w, s;
    l = s = 0, w = 1;
    // calculate letters, words and sentences
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // calculate letters
        if (isalpha(text[i]))
        {
            l++;
        }
        // calculate words
        else if (isblank(text[i]))
        // if (( text[i] == 0 && text[i] == ' ') || ( (text[i] != n -1 && text[i] == ' ' && text[i + 1] != ' '))
        {
            w++;
        }
        // calculate sentences
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            s++;
        }

    }
    // calculate L = Letters ÷ Words × 100
    float L = ((float)l / (float)w) * 100;
    // calculate S = Sentences ÷ Words × 100
    float S = ((float)s / (float)w) * 100;
    //calculate index = 0.0588 * L - 0.296 * S - 15.8
    float I = (0.0588 * L) - (0.296 * S) - 15.8;
    float INDEX = roundf(I);
    return INDEX;
}