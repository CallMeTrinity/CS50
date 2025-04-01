#include <stdio.h>

int get_int(char prompt[255]);

int main(void)
{
    int n = get_int("Give a number between 1 and 8 : ");
    // lenght of line 2*n + 2
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= 2 * n + 1; col++)
        {
            if(col == n+1)
            {
                printf("  ");
            } else if (col <= n - row || col >= n + row + 2)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

int get_int(char prompt[255])
{
    int n;
    int result;
    do
    {
        printf("%s", prompt);
        result  = scanf("%i", &n);
        if (result == 0){
            return 0;
        }
    } while (n < 1 || n > 8);
    return n;
}