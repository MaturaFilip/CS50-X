#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    int idx = round(0.0588 * (((float) letters / (float) words)) * 100 -
                    0.296 * (((float) sentences / (float) words)) * 100 - 15.8);
    // Print the grade level
    if (idx >= 1 && idx <= 16)
    {
        printf("Grade %i\n", idx);
    }
    else if (idx > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

int count_letters(string text)
{
    // Return the number of letters in text
    int sum = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalnum(text[i]))
        {
            sum += 1;
        }
    }
    return sum;
}

int count_words(string text)
{
    // Return the number of words in text
    int sum = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            sum += 1;
        }
    }
    return sum + 1;
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    int sum = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sum += 1;
        }
    }
    return sum;
}
