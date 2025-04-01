#include <stdio.h>

int main(void)
{
    int n;
    printf("Give me an int: ");
    int result = scanf("%d", &n);
    printf("result: %d\n", result);
    printf("n: %d\n", n);
}