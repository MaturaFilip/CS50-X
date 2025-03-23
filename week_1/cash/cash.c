#include <cs50.h>
#include <stdio.h>

int validate_input(void);
void calculate_coins(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents = validate_input();
    calculate_coins(cents);
    // Calculate how many quarters you should give customer
    // Subtract the value of those quarters from cents

    // Calculate how many dimes you should give customer
    // Subtract the value of those dimes from remaining cents

    // Calculate how many nickels you should give customer
    // Subtract the value of those nickels from remaining cents

    // Calculate how many pennies you should give customer
    // Subtract the value of those pennies from remaining cents

    // Sum the number of quarters, dimes, nickels, and pennies used
    // Print that sum
}

int validate_input(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents <= 0);
    return cents;
}

void calculate_coins(int cents)
{
    if (cents == 0)
    {
        printf("%i\n", cents);
    }

    int coins = 0;
    if (cents >= 25)
    {
        while (cents >= 25)
        {
            cents -= 25;
            coins += 1;
        }
    }

    if (cents >= 10)
    {
        while (cents >= 10)
        {
            cents -= 10;
            coins += 1;
        }
    }

    if (cents >= 5)
    {
        while (cents >= 5)
        {
            cents -= 5;
            coins += 1;
        }
    }

    if (cents >= 1)
    {
        while (cents >= 1)
        {
            cents -= 1;
            coins += 1;
        }
    }
    printf("%i\n", coins);
}
