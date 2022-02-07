#include <stdio.h>
#include "list.h"

int main()
{
    // create the list
    create_list();

    if (number_of_nodes == 0)
    {
        printf("\n");
        return 0;
    }

    // if run out of memory, exit
    if (malloc_err)
    {
        printf("An error occured! :(\n");
        return 1;
    }

    // print the list
    print_list();

    // reverse the list
    reverse_list();

    // pass a success message
    printf("Reversed the list successfully!\n");

    // print the list
    print_list();

    // free the list
    free_list();

    return 0;
}
