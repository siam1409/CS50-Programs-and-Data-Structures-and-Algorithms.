#include <stdio.h>
#include <cs50.h>

int fib(int n);

int main(void)
{
    int digit = get_int("At which index of the fibonacci sequence you want to look for? ");

    printf("The number at index %i of the fibonacci sequence is %i.\n", digit, fib(digit));

    return 0;
}




int fib(int n)
{
    if (n <= 3)
    {
        return 1;
    }

    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}
