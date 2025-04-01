#include <stdio.h>
void miaou(int n);
int get_int(char prompt[255]);

int main(void)
{
    int n = get_int("Give me a number ");
    miaou(n);
}

void miaou(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("miaou\n");
    }
}

int get_int(char prompt[255])
{
    int i;
    printf("%s", prompt);
    scanf("%i", &i);
    return i;
}
