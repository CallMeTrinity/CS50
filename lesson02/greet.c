#include <stdio.h>

int main(int argc, char *argv[])
{
    char *name;

    if (argc == 2)
    {
        name = argv[1];
    }
    else
    {
        char buffer[255];
        printf("Please provide a name for the greeting : ");
        scanf("%s", buffer);
        name = buffer;
    }
    printf("hello, %s\n", name);
    return 0;
}
