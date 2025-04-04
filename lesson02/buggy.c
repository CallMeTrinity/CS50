#include <stdio.h>

int get_int(char prompt[255]);
void print_column(int h);

int main(void)
{
    int h = get_int("Height : ");
    print_column(h);
}

int get_int(char prompt[255])
{
    int n;
    printf("%s", prompt);
    scanf("%i", &n);
    return n;
}

void print_column(int h)
{
    for (int i = 0; i < h; i++)
    {
        printf("#\n");
    }
}
