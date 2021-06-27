#include <stdio.h>
#include <cs50.h>

//Prototype of the custom function get_hight.
int get_hight(void);

int main(void)
{
    //Prompt the user for hight of the pyramid.
    int hight = get_hight();

    //Create a pyramid of that hight.
    for (int i = 0; i < hight; i++)
    {
        for (int j = 0; j <  hight - (i + 1); j++)
        {
            //Print spaces to right align the left pyramid.
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        //print two spaces to seperate the pyramids.
        printf("  ");

        //print the left aligned right pyramid.
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}


//Create a function that avoids invalid inputs for hight.
int get_hight(void)
{
    int n;
    do
    {
        n = get_int("Hight: ");
    }
    while (n < 1 || n > 120);
    return n;
}

