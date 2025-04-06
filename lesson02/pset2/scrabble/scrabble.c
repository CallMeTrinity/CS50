#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int compute_score(string word);

const int SCORES_DATA[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 8, 4, 10};
const int N = 2;

int main(void)
{

    string inputs[N];
    inputs[0] = get_string("player 1 : ");
    inputs[1] = get_string("player 2 : ");
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = compute_score(inputs[i]);
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

int compute_score(string word)
{
    int score = 0;
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        word[i] = tolower(word[i]);
        if (isalpha(word[i]))
        {
            score += SCORES_DATA[word[i] - 97];
        }
    }

    return score;
}