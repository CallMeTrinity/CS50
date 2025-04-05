#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get_player_input(char prompt[]);

const int SCORES[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 8, 4, 10};

int main(void)
{
    char *player1 = get_player_input("Player 1 : ");
    char *player2 = get_player_input("Player 2 : ");
}

char *get_player_input(char prompt[])
{
    char input[] = "", *copy = malloc(8 * sizeof(input));
    printf("%s", prompt);
    scanf("%s", input);
    copy = input;
    return copy;
}
