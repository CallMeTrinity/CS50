#include <cs50.h>
#include <stdio.h>
#include <string.h>
int get_avg_letters(string text);
int get_letter_count(string word);
int main(void)
{
    string text = get_string("Text : ");
    printf("%i\n", get_letter_count(text));
    printf("%i\n", get_avg_letters(text));
    // return the avg number of letters per words in the text
}

// index = 0.0588 * L - 0.296 * S - 15.8
// L = avg nb of letter, S = average number of sentence per 100 words

int get_avg_letters(string text)
{
    string words[255];

    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (text[i] != ' ')
        {
            printf("text[%i] : %c\n", i, text[i]);
            words[i] += text[i];
            printf("words[%i] : %s\n", i, words[i]);
        }
    }
    int sum = 0;
    for (int i = 0, l = sizeof(words); i < l; i++)
    {
        sum += strlen(words[i]);
    }

    return sum / sizeof(words);
}

// compte le nombre de lettre dans un string sans les espaces, a voir mais si je peux séparer les mots tout est faisable avec strlen.
int get_letter_count(string word)
{
    int counter = 0;
    for (int i = 0, l = strlen(word); i < l; i++)
    {
        if (word[i] != 32)
        {
            counter++;
        }
    }
    return counter;
}
