#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

// Prototype declaration of the function
void swap(int min, int array[], int index, int element);

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

        // create a tracker variable to keep track of the index of the element that has the lowest value
        int tracker;

        // create a variable to keep track of how many times any element of the array was considered to be the smallest
        int valexchange;

        for (int l = 0; l < length - 1; l++)
        {
            // initialize the number of exchanges of the value of minimum number to 0
            valexchange = 0;

            // consider the l'th element (after each iteration the number in the first place should be sorted so it will be eliminated) as the lowest valued element in the array
            int currently_minimum = unsorted[l];

            for (int k = l; k < length; k++)
            {
                // check for lower valued element(s) then the l'th element in the array
                if (unsorted[k] < currently_minimum)
                {
                    // if any element is lower that the previously lowest considered number then consider that element as the lowest number
                    currently_minimum = unsorted[k];

                    // change number of value enchanges by 1
                    valexchange++;

                    // update the tracker variable to keep track of the index of the lowest number found so far
                    tracker = k;
                }
            }

            // If the number of value exchange is zero, that means the l'th element is in the sorted position
            if (valexchange > 0)
            {
                // swap the l'th element and the lowest number
                swap(currently_minimum, unsorted, l, tracker);
            }

        }

        // print the sorted array element by element
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

        // exit from main with status code 0
        return 0;
    }

    // if the user didn't provide any number(s), then guide for the usage and exit with status code 1
    else
    {
        printf("usage: ./selection 'unsorted number(s)'\n");
        return 1;
    }
}









void swap(int min, int array[], int index, int element)
{
    // temporarily store the value of the element that is to be swaped with the smallest number
    int tmp = array[index];

    // change the value of that element to the smallest number
    array[index] = min;

    // set the value of the element at the index of the lowest number to the value of the temporary variable
    array[element] = tmp;
}
