#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *array1 = "this";

    char array2[5];

    strcpy(array2, array1);

    for (int i = 0; i < 4; i++)
    {
        printf("%c\n", array2[i]);
    }

    printf("\n");

    printf("%s\n", array1);

    return 0;
}


