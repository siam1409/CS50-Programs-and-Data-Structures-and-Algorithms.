#include <stdio.h>

void merge(int array[], int lb, int mid, int ub, int left[], int right[]);

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

void print_array(int array[], int l)
{
    // print the array
    printf("Sorted array: \n");
    for (int i = 0; i < l; i++)
    {
        printf("%d\n", array[i]);
    }
    printf("\n");
}
