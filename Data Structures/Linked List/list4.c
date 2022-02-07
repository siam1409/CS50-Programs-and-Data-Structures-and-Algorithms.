// Program for creation of a linked list and insertion in it (at specific position) and deleting data according to its position
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


// definition of all the functions
node *create_list(int *number_of_nodes, node *new_node, node *head);
void print_list(node *head);
node *insert_at_position(node *head, int position, node* new_node, int *number_of_nodes);
node *delete_from_position(node *head, int *number_of_nodes, bool *deleted);
node *delete_number(node *head, bool *deleted);
node *free_list(node *head);

int main()
{
    // How many numbers the user is going to input
    int number_of_nodes;
    do
    {
        number_of_nodes = get_int("How many numbers do you want to insert?\n=> ");
    }
    while (number_of_nodes < 0);

    if (number_of_nodes == 0)
    {
        return 0;
    }

    //
    //    LINKED LIST CREATIION
    //

    node *head = NULL, *new_node = NULL;

    // take input from the user and create the linked list
    head = create_list(&number_of_nodes, new_node, head);

    // print the list
    print_list(head);

    //
    //    DATA INSERTION
    //

    //the posiiton at which user wants to insert data
    int position = 0;

    do
    {
        position = get_int("At which position do you want to insert data? (If you don't want to do this, press 0) \n=> ");
    }
    while (position < 0 || position > number_of_nodes + 1);

    if (position != 0)
    {
        //insert the new node into the list at user defined position
        head = insert_at_position(head, position, new_node, &number_of_nodes);
    }
    else
    {
        printf("\n");
    }

    //
    //    DATA DELETION
    //

    int choice = 0;
    do
    {
        choice = get_int("According to what you want to delete data? (If you don't want to do this, press 0)\n1.Position\n2.Number\n=> ");
    }
    while (choice < 0 || choice > 2);

    bool deleted = false;

    if (choice == 1)
    {
        // the position form which user wants to delete data
        head = delete_from_position(head, &number_of_nodes, &deleted);
    }
    else if (choice == 2)
    {
        //the number which user wants to delete from the list
        head = delete_number(head, &deleted);
    }
    else
    {
        deleted = true;
    }

    if (deleted)
    {
        print_list(head);
    }
    else
    {
        printf("\nThe number you entered doesn't exist in the list.\n\n");
    }

    // free the list
    head = free_list(head);

    return 0;
}


            /*
                        <------------------ALL FUNCTIONS------------------>
                                                                                        */
node *create_list(int *number_of_nodes, node *new_node, node *head)
{
    // create a new list
    for (int i = 0; i < *number_of_nodes; i++)
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

    return head;
}

void print_list(node *head)
{
    // print the list
    printf("\nList:\n");
    for (node *tmp = head; tmp; tmp = tmp -> next)
    {
        printf("%d\n", tmp -> number);
    }
    printf("\n");
}

node *insert_at_position(node *head, int position, node* new_node, int *number_of_nodes)
{
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
            (*number_of_nodes)++;
            break;
        }
        else if (i == position - 2)
        {
            _tmp = tmp -> next;
            new_node = malloc(sizeof(node));
            new_node -> number = get_int("Number: ");
            new_node -> next = _tmp;
            tmp -> next = new_node;
            (*number_of_nodes)++;
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

    return head;
}

node *delete_from_position(node *head, int *number_of_nodes, bool *deleted)
{
    // the position form which user wants to delete data
    int del_pos;
    do
    {
        del_pos = get_int("Enter the position from which you want to delete number: ");
    }
    while (del_pos < 1 || del_pos > *number_of_nodes);

    int i = 0;
    // delete the data from the given position
    for (node *tmp = head, *_tmp = head -> next; tmp; tmp = tmp -> next, _tmp = _tmp -> next, i++)
    {
        if (del_pos == 1)
        {
            tmp = tmp -> next;
            free(head);
            *deleted = true;
            head = tmp;
            break;
        }
        else if (i == del_pos - 2)
        {
            tmp -> next = _tmp -> next;
            free(_tmp);
            *deleted = true;
            break;
        }
    }

        return head;
}

node *delete_number(node *head, bool *deleted)
{
    //the number which user wants to delete from the list
    int del_number = get_int("Enter the number you want to delete from the list: ");

    for (node *tmp = head, *_tmp = head -> next; _tmp; _tmp = tmp -> next)
    {
        // if the number is at the beginning
        if (head -> number == del_number)
        {
            free(head);
            *deleted = true;
            head = _tmp;
            tmp = _tmp;

        }
        else if (_tmp -> number == del_number)
        {
            if (_tmp -> next != NULL)
            {
                tmp -> next = _tmp -> next;
                free(_tmp);
                *deleted = true;
                break;
            }
            else
            {
                tmp -> next = NULL;
                free(_tmp);
                *deleted = true;
                _tmp = NULL;
                break;
            }
        }
        if (tmp -> next != NULL)
        {
            tmp = tmp -> next;
        }
    }

    return head;
}

node *free_list(node *head)
{
    // free the list
    while (head)
    {
        node *tmp = head -> next;
        free(head);
        head = tmp;
    }

    return head;
}
