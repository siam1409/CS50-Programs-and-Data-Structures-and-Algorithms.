#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *array1 = "this";

    char *array2 = malloc(strlen(array1) + 1);

    strcpy(array2, array1);

    printf("%s\n", array2);

    printf("%s\n", array1);
    
    free(array2);

    return 0;
}
