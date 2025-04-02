#include <stdio.h>
#include <stdbool.h>

long get_long(char prompt[255]);
char *get_card_type(long n);
long get_first_digits(long n);
bool luhn_alg(long n);

int main(void)
{
    long credit_card_number;
    bool luhn;
    do
    {
        credit_card_number = get_long("Credit card number : ");
        luhn = luhn_alg(credit_card_number);
    } while (!luhn);
    if (luhn)
    {
        char *card_type = get_card_type(credit_card_number);
        printf("%s\n", card_type);
    }
    else
    {
        printf("Invalid credit card number");
    }
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

    if (first_digits == 34 || first_digits == 37)
    {
        c = "AMEX";
    }
    else if (first_digits >= 51 && first_digits <= 55)
    {
        c = "MASTERCARD";
    }
    else if (first_digits / 10 == 4)
    {
        c = "VISA";
    }
    else
    {
        c = "INVALID";
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
    long iterator_1 = n;
    long iterator_2 = n;
    n /= 10;
    while (n >= 1)
    {
        iterator_1 = n;
        iterator_1 %= 10;
        int doubled = iterator_1 * 2;
        if (doubled > 10)
        {
            doubled_digits += doubled % 10 + doubled / 10;
        }
        else
        {
            doubled_digits += iterator_1 * 2;
        }
        n /= 100;
    }
    while (iterator_2 >= 1)
    {
        summed_digits += iterator_2 % 10;
        iterator_2 /= 100;
    }
    if ((summed_digits + doubled_digits) % 10 == 0)
    {
        return 1;
    }
    return 0;
}