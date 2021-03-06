#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt the user for start size
    int start;
    do
    {
        start = get_int("Enter the starting size of the population: ");
    }
    while (start < 9);
    //Prompt the user for end size
    int end;
    do
    {
        end = get_int("Enter the ending size of the population: ");
    }
    while (end < start);

    //Calculate number of years until we reach threshold
    int years = 0;

    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }
    //Print number of years
    printf("Years: %i\n", years);
}
