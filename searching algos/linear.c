#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

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

            int target = get_int("Enter the number that you are looking for "), start = 0, end = length - 1, midindex;

            for (int i = 0; i < length; i++)
            {
                if (array[i] == target)
                {
                    printf("%i is found in the array. And it is at index %i.\n", target, i + 1);
                    return 0;
                }
                   
            }
            printf("%i is not at the array\n", target);
            return 1;
        }
        else
        {
            printf("You must input more than 2 numbers\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./linear 'array'\n");
        return 1;
    }
}
