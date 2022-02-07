#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

//definition of a node
typedef struct node
{
    int number;
    struct node *next;
} __attribute__((__packed__))
node;

// declaration of all the variables
node *head = NULL, *new_node = NULL;
bool malloc_err = false;
int number_of_nodes = 0;

            /*            <------------------ALL FUNCTIONS------------------>           */

void create_list()
{
    // How many numbers the user is going to input
    do
    {
        number_of_nodes = get_int("How many numbers do you want to insert?\n=> ");
    }
    while (number_of_nodes < 0);

    if (number_of_nodes == 0)
    {
        return;
    }

    // create a new list
    for (int i = 0; i < number_of_nodes; i++)
    {
        new_node = malloc(sizeof(node));
        if (!new_node)
        {
            malloc_err = true;
            return;
        }
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
}

void print_list()
{
    // print the list
    printf("\nList:\n");
    for (node *tmp = head; tmp; tmp = tmp -> next)
    {
        printf("%d\n", tmp -> number);
    }
    printf("\n");
}

void free_list()
{
    // free the list
    while (head)
    {
        node *tmp = head -> next;
        free(head);
        head = tmp;
    }
}

void reverse_list()
{
    node *tmp = head, *tmp_prev = NULL, *tmp_next = head -> next;

    // reverse the list
    while (tmp)
    {
        if (head -> next != NULL)
        {
            head -> next = NULL;
        }
        else
        {
            tmp -> next = tmp_prev;
        }

        tmp_prev = tmp;

        if (tmp_next -> next == NULL)
        {
            tmp_next -> next = tmp;
            break;
        }
        else
        {   tmp = tmp_next;
            tmp_next = tmp_next -> next;
        }
    }

    head = tmp_next;
}
