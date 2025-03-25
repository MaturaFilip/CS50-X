#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string compare_score(string one, string two);
int total_score(string word);

int main(void)
{
    // Prompt the user for two words
    string player_1 = get_string("Player 1: ");
    string player_2 = get_string("Player 2: ");

    // Compute total score and compare the score between players. Return results
    string winner = compare_score(player_1, player_2);

    // Print the winner
    printf("%s\n", winner);
}

string compare_score(string one, string two)
{
    int player_one_score = total_score(one);
    int player_two_score = total_score(two);

    if (player_one_score > player_two_score)
        {
            return "Player 1 wins!";
        }
        else if (player_two_score > player_one_score)
        {
            return "Player 2 wins!";
        }
        else
        {
            return "Tie!";
        }
}


int total_score(string word)
{
    int sum = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (tolower(word[i]) == 'a' || tolower(word[i]) == 'e' || tolower(word[i]) == 'i' || tolower(word[i]) == 'l' || tolower(word[i]) == 'n' || tolower(word[i]) == 'o' || tolower(word[i]) == 'r' || tolower(word[i]) == 's' || tolower(word[i]) == 't' || tolower(word[i]) == 'u')
        {
            sum += 1;
        }
        else if (tolower(word[i]) == 'd' || tolower(word[i]) == 'g')
        {
            sum += 2;
        }
        else if (tolower(word[i]) == 'b' || tolower(word[i]) == 'c' || tolower(word[i]) == 'm' || tolower(word[i]) == 'p')
        {
            sum += 3;
        }
        else if (tolower(word[i]) == 'f' || tolower(word[i]) == 'h' || tolower(word[i]) == 'v' || tolower(word[i]) == 'w' || tolower(word[i]) == 'y')
        {
            sum += 4;
        }
        else if (tolower(word[i]) == 'k')
        {
            sum += 5;
        }
        else if (tolower(word[i]) == 'j' || tolower(word[i]) == 'x')
        {
            sum += 8;
        }
        else if (tolower(word[i]) == 'q' || tolower(word[i]) == 'z')
        {
            sum += 10;
        }
    }
    return sum;
}



// better solution:
/* int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
   
 int score = 0;

    // Compute score for each character
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {   // return position (for instance 98 - 97 in ascii = 1 -> position 1)
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score; */
