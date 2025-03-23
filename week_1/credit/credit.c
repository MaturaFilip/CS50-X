#include <cs50.h>
#include <stdio.h>

long validate_input(void);
int check_sum(long number);
int count_len(long number);
int is_valid(int number);
void identify_card(long number);
int first_two(long input);

int main(void)
{
    // Prompt the user for change owed, in cents
    long number = validate_input();
    identify_card(number);
}

long validate_input(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);
    return number;
}

int check_sum(long number)
{
    bool switcher = true;
    int sum = 0;

    while (number >= 1)
    {
        // poslední číslo
        long x = number % 10;
        if (switcher == true)
        {
            sum += x;
            switcher = false;
        }
        else
        {
            x *= 2;
            if (x > 9)
            {
                sum += (x % 10 + 1);
            }
            else
            {
                sum += x;
            }
            switcher = true;
        }
        number /= 10;
    }
    return sum;
}

int count_len(long number)
{
    if (number == 0)
        return 1;

    int count = 0;

    while (number != 0)
    {

        number = number / 10;
        ++count;
    }
    return count;
}

int is_valid(int number)
{
    return number % 10 == 0;
}

void identify_card(long number)
{
    int sum = check_sum(number);
    int valid = is_valid(sum);

    if (valid == 1)
    {
        int len = count_len(number);

        if (len == 15 && (first_two(number) == 34 || first_two(number) == 37))
        {
            printf("AMEX\n");
        }
        else if (len == 13)
        {
            printf("VISA\n");
        }
        else if (len == 16)
        {
            long first = number;
            while (first >= 10)
            {
                first = first / 10;
            }

            if (first == 4)
            {
                printf("VISA\n");
            }
            else if (first_two(number) == 51 || first_two(number) == 52 ||
                     first_two(number) == 53 || first_two(number) == 54 || first_two(number) == 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int first_two(long input)
{
    long local = input;

    while (local >= 100)
    {
        local /= 10;
    }

    return local;
}
