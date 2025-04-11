#include <stdio.h>
int get_int(char prompt[255]);
void print_average(int scores[], int array_size);

int main(void)
{
    int array_size = get_int("How many grades do you want to enter ? ");
    int scores[array_size];
    for (int i = 0; i < array_size; i++)
    {
        scores[i] = get_int("Grade : ");
    }

    // print average
    print_average(scores, array_size);
}

void print_average(int scores[], int array_size)
{
    float average = 0;
    for (int i = 0; i < array_size; i++)
    {
        average += scores[i];
    }
    printf("Average : %.2f\n", average / (float)array_size);
}

int get_int(char prompt[255])
{
    int n;
    printf("%s", prompt);
    scanf("%i", &n);
    return n;
}
