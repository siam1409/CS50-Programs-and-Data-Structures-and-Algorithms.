#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <math.h>

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
                midindex = (start + end) / 2;

                if (array[midindex] == target)
                {
                    printf("Found! \n");
                    return 0;
                }
                else if (array[midindex] > target)
                {
                    end = midindex - 1;
                }
                else if (array[midindex] < target)
                {
                    start = midindex + 1;
                }
                else
                {
                    printf("not found\n");
                    return 1;
                }
                if (start > end)
                {
                    printf("not found\n");
                    return 1;
                }
            }
        }
        else
        {
            printf("You should input more than two numbers\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./binarysrch sorted number(s)\n");
        return 1;
    }
}
