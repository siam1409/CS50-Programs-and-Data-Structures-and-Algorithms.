#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char array1[4] = {'1', '2', '3', '\0'};

    char array2[4];

    strcpy(array2, array1);

    for (int i = 0; i < 3; i++)
    {
        printf("%c\n", array2[i]);
    }

    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf("%c\n", array1[i]);
    }


    return 0;
}


