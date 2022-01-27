// Program for creation of a linked list and insertion in it (at specific position)
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main()
{
    // How many nummbers the user is gonna input
    int number_of_nodes;
    do
    {
        number_of_nodes = get_int("How many numbers do you want to insert? => ");
    }
    while (number_of_nodes <= 0);

    node *head = NULL, *n = NULL;

    // take input from the user and create the linked list
    for (int i = 0; i < number_of_nodes; i++)
    {
        n = malloc(sizeof(node));
        n -> number = get_int("Number: ");
        n -> next = NULL;

        // if "head" is NULL, make it point to the first node (at which "n" is pointing currently)
        if (!head)
        {
            head = n;
        }
        else
        {
            //link the nodes
            node *tmp = head;
            while (true)
            {
                if (tmp -> next == NULL)
                {
                    tmp -> next = n;
                    break;
                }
                tmp = tmp -> next;
            }
        }
    }

    // print the list
    printf("\n");
    for (node *tmp = head; tmp; tmp = tmp -> next)
    {
        printf("%d\n", tmp -> number);
    }
    printf("\n");

    // the posiiton at which user wants to insert data
    int position = 0;

    do
    {
        position = get_int("At which position do you want to insert data? => ");
    }
    while (position <= 0 || position > number_of_nodes + 1);

    //insert the new node into the list at user defined position
    int i = 0;

    for (node *tmp = head; tmp; tmp = tmp -> next)
    {
        node *_tmp = tmp -> next;
        if (i == position - 2)
        {
            n = malloc(sizeof(node));
            n -> number = get_int("Number: ");
            n -> next = _tmp;
            tmp -> next = n;
        }
        i++;
    }

    // print the new list
    printf("\n");
    for (node *tmp = head; tmp; tmp = tmp -> next)
    {
        printf("%d\n", tmp -> number);
    }
    printf("\n");

    // free the list
    while (head)
    {
        node *tmp = head -> next;
        free(head);
        head = tmp;
    }
    return 0;
}
