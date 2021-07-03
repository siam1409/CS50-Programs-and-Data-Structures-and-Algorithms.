#include <stdio.h>

unsigned long long int fact(int n);

int main (void)
{
    int digit;

    printf("Which number's factorial do you want to know? ");

    scanf("%i", &digit);

    printf("The factorial of %i is %llu.\n", digit, fact(digit));

    return 0;
}





unsigned long long int fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}
