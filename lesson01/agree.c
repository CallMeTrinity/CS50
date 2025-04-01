#include <stdio.h>

int main(void)
{
    char answer[1];
    printf("Hello user, is today a sunny day ? Y/n ");
    scanf("%c", answer);
    if (*answer == 'y' || *answer == 'Y')
    {
        printf("Agree \n");
    }
    else if (*answer == 'n')
    {
        printf("Disagree \n");
    }
    else {
        printf("Unrecognized answer \n");
    }
}