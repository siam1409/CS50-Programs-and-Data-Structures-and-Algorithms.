// Program for creation of a linked list and insertion in it (at specific position) and deleting data according to its position
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

//definition of a node
typedef struct node
{
    int number;
    struct node *next;
}__attribute__((__packed__))
node;

int main()
{
    // How many numbers the user is going to input
    int number_of_nodes;
    do
    {
        number_of_nodes = get_int("How many numbers do you want to insert?\n=> ");
    }
    while (number_of_nodes <= 0);

        //
        //    LINKED LIST CREATIION
        //

    node *head = NULL, *new_node = NULL;

    // take input from the user and create the linked list
    for (int i = 0; i < number_of_nodes; i++)
    {
        new_node = malloc(sizeof(node));
        new_node -> number = get_int("Number: ");
        new_node -> next = NULL;

        // if "head" is NULL, make it point to the first node (at which "n" is pointing currently)
        if (!head)
        {
            head = new_node;
        }
        else
        {
            //link the nodes from first to last
            node *tmp = head;
            while (true)
            {
                if (tmp -> next == NULL)
                {
                    tmp -> next = new_node;
                    break;
                }
                tmp = tmp -> next;
            }
        }
    }

    // print the list
    printf("\nList:\n");
    for (node *tmp = head; tmp; tmp = tmp -> next)
    {
        printf("%d\n", tmp -> number);
    }
    printf("\n");

        //
        //    DATA INSERTION
        //

    //the posiiton at which user wants to insert data
    int position = 0;

    do
    {
        position = get_int("At which position do you want to insert data?\n=> ");
    }
    while (position <= 0 || position > number_of_nodes + 1);

    //insert the new node into the list at user defined position
    int i = 0;

    for (node *tmp = head; tmp; tmp = tmp -> next)
    {
        node *_tmp;
        if (position == 1)
        {
            _tmp = head;
            new_node = malloc(sizeof(node));
            new_node -> number = get_int("Number: ");
            new_node -> next = _tmp;
            head = new_node;
            break;
        }
        else if (i == position - 2)
        {
            _tmp = tmp -> next;
            new_node = malloc(sizeof(node));
            new_node -> number = get_int("Number: ");
            new_node -> next = _tmp;
            tmp -> next = new_node;
        }
        i++;
    }

    // print the new list
    printf("\nNew list:\n");
    for (node *tmp = head; tmp; tmp = tmp -> next)
    {
        printf("%d\n", tmp -> number);
    }
    printf("\n");

        //
        //    DATA DELETION
        //

    // the position form which user wants to delete data
    int del_pos = get_int("Enter the position from which you want to delete number: ");
    i = 0;
    // delete the data from the given position
    for (node *tmp = head, *_tmp = head; tmp; tmp = tmp -> next, _tmp = _tmp -> next, i++)
    {
        if (del_pos == 1)
        {
            tmp = tmp -> next;
            free(head);
            head = tmp;
            break;
        }
        else if (i == del_pos - 2)
        {
            _tmp = _tmp -> next;
            tmp -> next = tmp -> next -> next;
            free(_tmp);
            break;
        }
    }

    // print the new list
    printf("\nNew list:\n");
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
