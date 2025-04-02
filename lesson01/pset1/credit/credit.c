#include <stdio.h>
#include <stdbool.h>

long get_long(char prompt[255]);
char *get_card_type(long n);
long get_first_digits(long n);
bool luhn_alg(long n);
int length_of_card_number(long n);

int main(void)
{
    long credit_card_number;
    bool luhn;
    credit_card_number = get_long("Credit card number : ");
    char *card_type = get_card_type(credit_card_number);
    printf("%s\n", card_type);
}

int length_of_card_number(long n)
{
    int counter = 0;
    while (n >= 1)
    {
        n /= 10;
        counter++;
    }
    return counter;
}

long get_long(char prompt[255])
{
    long n;
    do
    {
        printf("%s", prompt);
        scanf("%li", &n);
    } while (n < 0);

    return n;
}

char *get_card_type(long n)
{
    char *c;

    long first_digits = get_first_digits(n);
    int l = length_of_card_number(n);
    c = "INVALID";
    if (luhn_alg(n))
    {
        if ((first_digits == 34 || first_digits == 37) && l == 15)
        {
            c = "AMEX";
        }
        else if ((first_digits >= 51 && first_digits <= 55) && l == 16)
        {
            c = "MASTERCARD";
        }
        else if ((first_digits / 10 == 4) && (l == 13 || l == 16))
        {
            c = "VISA";
        }
    }
    return c;
}

long get_first_digits(long n)
{
    while (n >= 100)
    {
        n /= 10;
    }
    return n;
}

bool luhn_alg(long n)
{
    int doubled_digits = 0;
    int summed_digits = 0;

    int pos = 0;
    while (n >= 1)
    {
        if (pos % 2 == 0)
        {
            summed_digits += n % 10;
        }
        else
        {
            int doubled = n % 10 * 2;
            if (doubled >= 10)
            {
                doubled_digits += doubled % 10 + doubled / 10;
            }
            else
            {
                doubled_digits += doubled;
            }
        }
        pos++;
        n /= 10;
    }
    return (summed_digits + doubled_digits) % 10 == 0;
}