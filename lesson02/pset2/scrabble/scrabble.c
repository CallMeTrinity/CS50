#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

const int SCORES_DATA[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 8, 4, 10};

const int number_player = 2;
int main(void)
{

    string inputs[number_player];
    inputs[0] = get_string("player 1 : ");
    inputs[1] = get_string("player 2 : ");
    int scores[2];
    for (int i = 0; i < number_player; i++)
    {
        scores[i] = 0;
        for (int j = 0, lenght = strlen(inputs[i]); j < lenght; j++)
        {
            inputs[i][j] = tolower(inputs[i][j]);
            if (inputs[i][j] >= 96 && inputs[i][j] <= 122)
            {
                scores[i] += SCORES_DATA[inputs[i][j] - 97];
            }
        }
    }
    if (scores[0] > scores[1])
    {
        printf("Player 1 wins !\n");
    }
    else if (scores[0] < scores[1])
    {
        printf("Player 2 wins !\n");
    }
    else
    {
        printf("Tie !\n");
    }

    return 0;
}
