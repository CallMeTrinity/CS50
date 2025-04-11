#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float get_avg_letters(string text);
int get_letter_count(string word);
int get_word_count(string text);
int get_sentence_count(string t);
int get_index(int l, int s, int w);

int main(void)
{
    string text = get_string("Text : ");
    int lcount = get_letter_count(text);
    int wcount = get_word_count(text);
    int scount = get_sentence_count(text);
    int index = get_index(lcount, scount, wcount);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int get_index(int l, int s, int w)
{
    l = (100 * l) / w;
    s = (100 * s) / w;
    return round((0.0588 * l) - (0.296 * s) - 15.8);
}

int get_letter_count(string s)
{
    int counter = 0;
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        if (isalpha(s[i]))
        {
            counter++;
        }
    }
    return counter;
}

// compter les espaces est une solution correcte pour cs50 mais dans l'idéal il faudrait plutôt compter les transition non-espace -> espace.
int get_word_count(string text)
{
    int counter = 1; // on compte les espaces pour déterminer le nombre de mots donc on rajoute 1 pour le premier mot.
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (text[i] == ' ')
        {
            counter++;
        }
    }
    return counter;
}

int get_sentence_count(string t)
{
    int c = 0;
    for (int i = 0, l = strlen(t); i < l; i++)
    {
        if (t[i] == '.' || t[i] == '?' || t[i] == '!')
        {
            c++;
        }
    }
    return c;
}