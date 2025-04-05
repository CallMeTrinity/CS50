#include <stdio.h>
#include <string.h>

char *get_string(char prompt[255]);

int main(void)
{
    char *s = get_string("Input : ");
    printf("Output : ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}

char *get_string(char prompt[255])
{
    char input[255];
    printf("%s", prompt);
    scanf("%s", input);
    return input;
}
