#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <math.h>

void binary(int destinationValue, int first, int last, int mid, int arr[]);

int main(int argc, string argv[])
{
    if (argc > 1)
    {
        if (argc > 3)
        {
            int length = argc - 1;

            int array[length];

            for (int i = 0; i < length; i++)
            {
                array[i] = atoi(argv[i + 1]);
            }

            int target = get_int("Enter the number that you are looking for ");

            int start = 0, end = length - 1, midindex = 0;

            binary(target, start, end, midindex, array);
        }
        else
        {
            printf("You should input more than two numbers\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./binaryrecurse sorted number(s)\n");
        return 1;
    }
}






void binary(int destinationValue, int first, int last, int mid, int arr[])
{
    if (arr[mid] == destinationValue)
    {
        printf("Found!\n");

        return;
    }
    else if (arr[mid] > destinationValue)
    {
        last = mid - 1;
    }
    else if (arr[mid] < destinationValue)
    {
        first = mid + 1;
    }
    else
    {
        printf("not found\n");
        return;
    }
    if (first > last)
    {
        printf("not found\n");
        return;
    }

    binary(destinationValue, first, last, (first + last) / 2, arr);
}
