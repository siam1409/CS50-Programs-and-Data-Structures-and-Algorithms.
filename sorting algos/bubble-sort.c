#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

// Prototype declaration of the function
void swap(int array[], int b);

int main(int argc, string argv[])
{
    // make sure the user provided more than a single cmd line argument
    if (argc > 1)
    {
        // count how many numbers the user provide for the unsorted array
        int length = argc - 1;

        // create an array for those many numbers
        int unsorted[length];

        // fill the array with the numbers that the user has input
        for (int i = 0; i < length; i++)
        {
            unsorted[i] = atoi(argv[i + 1]);
        }

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
                printf("sorted array: {");

                for (int j = 0;  j < length; j++)
                {
                    if (j == length - 1)
                    {
                        printf("%i}\n", unsorted[j]);
                    }
                    else
                    {
                        printf("%i, ", unsorted[j]);
                    }
                }

                return 0;
            }
        }

        printf("sorted: {");

        for (int j = 0;  j < length; j++)
        {
            if (j == length - 1)
            {
                printf("%i}\n", unsorted[j]);
            }
            else
            {
                printf("%i, ", unsorted[j]);
            }
        }

        return 0;
    }

    // if the user didn't provide any number(s), then guide for the usage and exit with status code 1
    else
    {
        printf("usage: ./bubble unsorted numbers\n");
        return 1;
    }
}







void swap(int array[], int b)
{
    int tmp = array[b];

    array[b] = array[b + 1];

    array[b  + 1] = tmp;
}
