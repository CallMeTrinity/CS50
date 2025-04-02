#include <stdio.h>

int get_int(char prompt[255]);
int calculate_change(int n);

// cents : 25 | 10 | 5 | 1

int main(void)
{
    int n = get_int("Change owned : ");
    printf("%i\n", calculate_change(n));
}

int get_int(char prompt[255])
{
    int n;
    do
    {
        printf("%s", prompt);
        scanf("%i", &n);
    } while (n < 0);

    return n;
}

int calculate_change(int n)
{
    int counter = 0;

    while (n >= 25)
    {
        n -= 25;
        counter++;
    }
    while (n >= 10)
    {
        n -= 10;
        counter++;
    }
    while (n >= 5)
    {
        n -= 5;
        counter++;
    }
    while (n >= 1)
    {
        n -= 1;
        counter++;
    }

    return counter;
}