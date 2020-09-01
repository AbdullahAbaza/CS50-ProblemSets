#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
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
// calculate letters
int count_letters(string text)
{
    int L = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            L++;
        }
    }
    return L;
}
// calculate words
int count_words(string text)
{
    int W = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isblank(text[i]))
        {
            W++;
        }
    }
    return W;
}
// calculate sentences
int count_sentences(string text)
{
    int S = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            S++;
        }
    }
    return S;
}
int index(string text)
{
    //store letters, words and sentences as a float
    float l = count_letters(text);
    float w = count_words(text);
    float s = count_sentences(text);
    // calculate L = Letters ÷ Words × 100
    float L = (l / w) * 100;
    // calculate S = Sentences ÷ Words × 100
    float S = (s / w) * 100;
    //calculate index = 0.0588 * L - 0.296 * S - 15.8
    float I = (0.0588 * L) - (0.296 * S) - 15.8;
    float INDEX = roundf(I);
    return INDEX;
}