#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

long convert_to_lng(string s);
string cipher(string p, long k);

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

    long key = convert_to_lng(argv[1]);
    string p = get_string("Plain text :  ");
    string c = cipher(p, key);
    printf("Cipher text :  %s\n", c);

    free(c);
    return 0;
}

long convert_to_lng(string s)
{
    return strtol(s, (char **)NULL, 10) % 26;
}

string cipher(string p, long k)
{
    int l = strlen(p);
    char *c = malloc(l + 1);
    for (int i = 0; i < l; i++)
    {
        if (isalpha(p[i]))
        {
            char base = islower(p[i]) ? 'a' : 'A';
            c[i] = (p[i] - base + k) % 26 + base;
        }
        else
        {
            c[i] = p[i];
        }
    }
    c[l] = '\0';
    return c;
}
