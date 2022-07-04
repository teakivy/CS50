#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

float calc_index(int let, int wor, int sen);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    int index = (int) round(calc_index(letters, words, sentences));

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Count letters in a string
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int c = (int) text[i];

        // Is alphabetical
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            count++;
        }
    }

    return count;
}

// Count words in a string
int count_words(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int c = (int) text[i];

        // Spaces
        if (c == ' ')
        {
            count++;
        }

        // End of text
        if (i == n - 1)
        {
            count++;
        }
    }

    return count;
}

// Count sentences in a string
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int c = (int) text[i];

        // End of sentences
        if (c == '.' || c == '?' || c == '!')
        {
            count++;
        }
    }

    return count;
}

// Calculate the index of a text by its letters, words, and sentences
// Based on Coleman-Liau Index of "index = 0.0588 * L - 0.296 * S - 15.8"
float calc_index(int let, int wor, int sen)
{
    float L = (let / (float) wor) * 100.0;
    float S = (sen / (float) wor) * 100.0;

    return 0.0588 * L - 0.296 * S - 15.8;
}