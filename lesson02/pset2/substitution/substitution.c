#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool check_for_each_letter_in_key(string k);
string cipher(string p, string k);
char get_ciphered_char(string k, char c);
bool isAlpha(string s);
bool is_in_string(string s, char c);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./subsitution KEY\n");
        return 1;
    }
    else if (!isAlpha(argv[1]))
    {
        printf("Key must only contain letters\n");
        return 1;
    }
    else if (strlen(argv[1]) < 26)
    {
        printf("Key must contain 26 characters, you have %lu\n", strlen(argv[1]));
        return 1;
    }
    else if (!check_for_each_letter_in_key(argv[1]))
    {
        printf("Key must contain each letter exactly once\n");
        return 1;
    }

    string key = argv[1];
    string plain_text = get_string("plaintext : ");
    printf("ciphertext : %s\n", cipher(plain_text, key));
    return 0;
}

bool isAlpha(string s)
{
    unsigned long l = strlen(s);
    for (int i = 0; i < (int)l; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

string cipher(string p, string k)
{
    unsigned long l = strlen(p);
    string c = malloc(l + 1); // 1 for '\0'

    for (int i = 0; i < (int)l; i++)
    {
        if (isalpha(p[i]))
        {
            c[i] = get_ciphered_char(k, p[i]);
        }
        else
        {
            c[i] = p[i];
        }
    }
    c[l] = '\0';
    return c;
}

char get_ciphered_char(string k, char c)
{
    char ciphered = '\0';

    int base = isupper(c) ? 65 : 97;
    for (int i = 0; i < 26; i++)
    {
        if ((c - base) == i)
        {
            ciphered = isupper(c) ? toupper(k[i]) : tolower(k[i]);
            break;
        }
    }
    return ciphered;
}

bool check_for_each_letter_in_key(string k)
{
    int l = (int)strlen(k);
    string check = malloc(l + 1);
    for (int i = 0; i < l; i++)
    {
        if (!is_in_string(check, k[i]))
        {
            check[i] = k[i];
        }
        else
        {
            break;
        }
    }
    if (strlen(check) == 26)
    {
        return true;
    }
    return false;
}

bool is_in_string(string s, char c)
{
    int l = (int)strlen(s);
    for (int i = 0; i < l; i++)
    {
        if (c == s[i])
        {
            return true;
            break;
        }
    }
    return false;
}