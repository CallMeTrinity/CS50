#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int convert_to_int(string s);
string cipher(string p, int k);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage : ./caesar key\n");
        return 1;
    }
    for (int i = 0, l = strlen(argv[1]); i < l; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Please provide a valid positive integer.\n");
            return 1;
        }
    }

    long key = convert_to_int(argv[1]);
    string p = get_string("Plain text :  ");
    string c = cipher(p, key);
    printf("Cipher text :  %s\n", c);
}

int convert_to_int(string s)
{
    return (int)strtol(s, (char **)NULL, 10) % 26;
}

string cipher(string p, int k)
{
    int l = strlen(p);
    char *c = malloc(l + 1);
    for (int i = 0; i < l; i++)
    {
        c[i] = p[i] + k;
        while ((islower(p[i]) && c[i] > 122) || (isupper(p[i]) && c[i] > 90))
        {
            c[i] -= 26;
        }
        c[l] = '\0';
    }
    return c;
}