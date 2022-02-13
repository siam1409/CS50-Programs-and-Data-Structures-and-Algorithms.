// header for bubble sort
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

void swap(int array[], int b)
{
    int tmp = array[b];

    array[b] = array[b + 1];

    array[b + 1] = tmp;
}

void bubble_sort(int unsorted[], int length)
{
    int swaps;

    for (int k = length - 1; k >= 0; k--)
    {
        swaps = - 1;

        for (int l = 0; l < k; l++)
        {
            if (unsorted[l] > unsorted[l + 1])
            {
                swap(unsorted, l);

                swaps++;// header for bubble sort
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

void swap(int array[], int b)
{
    int tmp = array[b];

    array[b] = array[b + 1];

    array[b + 1] = tmp;
}

void bubble_sort(int unsorted[], int length)
{
    int swaps;

    for (int k = length - 1; k >= 0; k--)
    {
        swaps = - 1;

        for (int l = 0; l < k; l++)
        {
            if (unsorted[l] > unsorted[l + 1])
            {
                swap(unsorted, l);

                swaps++;
            }
        }

        if (swaps < 0)
        {
            return;
        }
    }
    return;

}


            }
        }

        if (swaps < 0)
        {
            return;
        }
    }
    return;

}

