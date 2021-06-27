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
    for (int i = 0; i < hight; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    
    // exit with status code 0
    return 0;
}

