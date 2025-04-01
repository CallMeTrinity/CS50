#include <stdio.h>

int get_int(char prompt[255]);

int main(void)
{
    int n = get_int("Height: ");
    for (int row = 1; row < n + 1; row++)
    {
       for (int col = 1; col < n + 1; col++)
        {
           if (col <= n - row)
           {
               printf(" ");
           } else
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
    } while (n < 1);
    return n;
}