// Quicksort alogrithm, pivot at start, using start and end position
#include <stdio.h>
#include <cs50.h>

void quicksort(int array[], int start, int end);
int partition(int array[], int start, int end);
void swap(int array[], int a, int b);

int main()
{
    int length;
    do
    {
        length = get_int("Length: ");
    }
    while(length < 2);

    int array[length];

    for (int i = 0; i < length; i++)
    {
        array[i] = get_int("Number: ");
    }

    quicksort(array, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        printf("%d  \n", array[i]);
    }

    printf("\n");

    return 0;
}

void quicksort(int array[], int start, int end)
{
    int location;
    if (start < end)
    {
        location = partition(array, start, end);
        quicksort(array, start, location - 1);
        quicksort(array, location + 1, end);
    }
    return;
}

int partition(int array[], int start, int end)
{
    int pivot = array[start], lb = start;

    while(start < end)
    {
        while (array[start] <= pivot)
        {
            start++;
        }
        while (array[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(array, start, en// Quicksort alogrithm, pivot at start, using start and end position
#include <stdio.h>
#include <cs50.h>

void quicksort(int array[], int start, int end);
int partition(int array[], int start, int end);
void swap(int array[], int a, int b);

int main()
{
    int length;
    do
    {
        length = get_int("Length: ");
    }
    while(length < 2);

    int array[length];

    for (int i = 0; i < length; i++)
    {
        array[i] = get_int("Number: ");
    }

    quicksort(array, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        printf("%d  \n", array[i]);
    }

    printf("\n");

    return 0;
}

void quicksort(int array[], int start, int end)
{
    int location;
    if (start < end)
    {
        location = partition(array, start, end);
        quicksort(array, start, location - 1);
        quicksort(array, location + 1, end);
    }
    return;
}

int partition(int array[], int start, int end)
{
    int pivot = array[start], lb = start;

    while(start < end)
    {
        while (array[start] <= pivot)
        {
            start++;
        }
        while (array[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(array, start, end);
        }
    }
    swap(array, lb, end);
    return end;
}

void swap(int array[], int a, int b)
{
    int tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}d);
        }
    }
    swap(array, lb, end);
    return end;
}

void swap(int array[], int a, int b)
{
    int tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}
