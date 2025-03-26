#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char rotate(char letter, int key);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    // Make sure every character in argv[1] is a digit
    if (argc == 2 && atoi(argv[1]) > 0)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string text_to_cipher = get_string("plaintext: ");

    // For each character in the plaintext:
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text_to_cipher); i < n; i++)
    {
        // Rotate the character if it's a letter
        printf("%c", rotate(text_to_cipher[i], key));
    }

    printf("\n");

    // success return 0
    return 0;
}

char rotate(char letter, int key)
{
    // check case and return shifted letter
    if (isupper(letter))
    {
        return (((letter - 'A') + key) % 26) + 'A';
    }
    else if (islower(letter))
    {
        return (((letter - 'a') + key) % 26) + 'a';
    }
    else
    {
        return letter;
    }
}
