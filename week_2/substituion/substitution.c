#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool text_unique(string text);
char rotate(char letter, string sub);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    if (!text_unique(argv[1]))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    // get text to cipher
    string text_to_cipher = get_string("plaintext: ");

    // convert plaintext to ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text_to_cipher); i < n; i++)
    {
        printf("%c", rotate(text_to_cipher[i], argv[1]));
    }

    printf("\n");
    return 0;
}

bool text_unique(string text)
{
    // check if string is unique. If so, return true
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (tolower(text[i]) == tolower(text[j]))
            {
                return false;
            }
        }
    }
    return true;
}

char rotate(char letter, string sub)
{
    // check case and return proper character substitution
    if (isupper(letter))
    {
        return toupper(sub[(letter - 'A')]);
    }
    else if (islower(letter))
    {
        return tolower(sub[(letter - 'a')]);
    }
    else
    {
        return letter;
    }
}
