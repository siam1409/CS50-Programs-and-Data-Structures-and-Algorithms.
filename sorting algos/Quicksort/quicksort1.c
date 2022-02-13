// Quicksort alogrithm, pivot at start, using i (initialized to start position of the giver array) and j (initialized to i + 1)
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
    int pivot = array[start];

    int i = start;

    for (int j = i + 1; j < end + 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array, i ,j);
        }
    }
    swap(array, i, start);

    return i;
}

void swap(int array[], int a, int b)
{
    int tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}
