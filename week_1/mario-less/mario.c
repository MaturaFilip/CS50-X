#include <stdio.h>
#include <cs50.h>

int validate_input(void);
void pyramide(int n);

int main(void)
{
    // ask user for input and then output pyramide
    int height = validate_input();
    pyramide(height);
}

int validate_input(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);
    return n;
}

void pyramide(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            printf(" ");

        }
        for (int k = 0; k < (i + 1); k++)
        {
            printf("#");
        }

        printf("\n");
    }
}

