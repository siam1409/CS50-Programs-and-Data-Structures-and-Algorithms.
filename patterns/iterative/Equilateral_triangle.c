#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // prompt the user for hight of the pyramid
    int hight;
    do
    {
        hight = get_int("Enter the hight: ");
    }
    while (hight < 0);

    // print a pyramid of that hight
    for (int i = 1; i <= hight; i++)
    {
        for (int j = 0; j < hight - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < (2 * i) - 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }

    // exit with status code 0
    return 0;
}

