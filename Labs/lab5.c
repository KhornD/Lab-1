#include <stdio.h>
int countOfDigits(int n)
{
    if (!n) return 1;
    int count_of_dg = 0;
    while (n)
    {
        count_of_dg++;
        n /= 10;
    }
    return count_of_dg;
}

int rec_countOfDigits(int n)
{
    if (n / 10)
        return 1 + rec_countOfDigits(n / 10);
    else
        return 1;
}

int main() {
    int number;
    printf("Enter integer number: ");
    scanf("%d", &number);
    printf("Count of digits:\n");
    printf("Cycle: %d\n", countOfDigits(number));
    printf("Recursion: %d\n", rec_countOfDigits(number));
    return 0;
}
