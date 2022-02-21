#include <stdio.h>
#include <cs50.h>

// function declarations
void mergesort(int array[], int lb, int ub);
void merge(int array[], int lb, int mid, int ub, int left[], int right[]);

int main(void)
{
    // take input for the size of the unsorted array
    int size;
    do
    {
        size = get_int("size: ");
    }
    while (size < 2);

    // create the array and fill it with user inputs
    int array[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = get_int("Number: ");
    }

    // sort the array
    mergesort(array, 0, size - 1);

    // print the array
    printf("Array: \n");

    for (int i = 0; i < size; i++)
    {
        printf("%i\n", array[i]);
    }

    return 0;
}

void mergesort(int array[], int lb, int ub)
{
    // sort the array if it contains more than one element
    if (lb < ub)
    {
        int i, l = (ub - lb) + 1, mid = (lb + ub) / 2, llen = mid - lb + 1, rlen = ub - mid, left[llen], right[rlen];

        // create the left half the array
        for (i = 0; i < llen; i++)
        {
            left[i] = array[i];
        }

        // create the right half of the array
        for (int j = 0; j < rlen; i++, j++)
        {
            right[j] = array[i];
        }

        // sort the left half of the array
        mergesort(left, lb, mid);
        // sort the right half of the array
        mergesort(right, mid + 1, ub);
        // merge the sorted halves
        merge(array, lb, mid, ub, left, right);
    }
    return;
}

void merge(int array[], int lb, int mid, int ub, int left[], int right[])
{
    int i, j, k, rlen = ub - mid, llen = mid - lb + 1;

    // iterate over the two arrays (left and right halves of the array at any particular scope) and create the new sorted array
    for (i = 0, j = 0, k = 0; i < llen && j < rlen; k++)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
    }

    // copy the rest of the left or right array if remaining
    if (i < llen && j >= rlen)
    {
        while (i < llen)
        {
            array[k] = left[i];
            k++, i++;
        }
    }
    else if (i >= llen && j < rlen)
    {
        while (j < rlen)
        {
            array[k] = right[j];
            k++, j++;
        }
    }
}
