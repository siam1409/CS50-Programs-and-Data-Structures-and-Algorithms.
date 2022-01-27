// Create a linked list 
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
    const int number_of_nodes = get_int("How many numbers do you want to insert? ");

    node *head = NULL, *n = NULL;

    // take input from the user and create the linked list
    for (int i = 0; i < number_of_nodes; i++)
    {
        n = malloc(sizeof(node));
        n -> number = get_int("Number: ");
        n -> next = NULL;

        if (!head)
        {
            head = n;
        }
        else
        {
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
    for (node *tmp = head; tmp; tmp = tmp -> next)
    {
        printf("%d\n", tmp -> number);
    }

    // free the list
    while(head)
    {
        node *tmp = head -> next;
        free(head);
        head = tmp;
    }
    return 0;
}
