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

// all variables
int number_of_nodes;
node *head = NULL, *new_node = NULL;
bool deleted = false;
bool malloc_err = false;

// function defiintions
void create_list();
void print_list();
void insert_at_position(int position);
void delete_from_position();
void delete_number();
void free_list();

int main()
{
    // How many numbers the user is going to input
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

    // take input from the user and create the linked list
    create_list();

    if (malloc_err)
    {
        printf("An error occured! :(\n");
        return 1;
    }

    // print the list
    print_list();

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
        insert_at_position(position);

        if (malloc_err)
        {
            printf("An error occured! :(\n");
            return 1;
        }
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

    if (choice == 1)
    {
        // the position form which user wants to delete data
        delete_from_position();
    }
    else if (choice == 2)
    {
        //the number which user wants to delete from the list
        delete_number();
    }
    else
    {
        deleted = true;
    }

    if (deleted)
    {
        print_list();
    }
    else
    {
        printf("\nThe number you entered doesn't exist in the list.\n\n");
    }

    // free the list
    free_list();

    return 0;
}


            /*
                        <------------------ALL FUNCTIONS------------------>
                                                                                        */
void create_list()
{
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

void insert_at_position(int position)
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
            if (!new_node)
            {
                malloc_err = true;
                return;
            }
            new_node -> number = get_int("Number: ");
            new_node -> next = _tmp;
            head = new_node;
            number_of_nodes++;
            break;
        }
        else if (i == position - 2)
        {
            _tmp = tmp -> next;
            new_node = malloc(sizeof(node));
            if (!new_node)
            {
                malloc_err = true;
                return;
            }
            new_node -> number = get_int("Number: ");
            new_node -> next = _tmp;
            tmp -> next = new_node;
            number_of_nodes++;
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
}

void delete_from_position()
{
    // the position form which user wants to delete data
    int del_pos;
    do
    {
        del_pos = get_int("Enter the position from which you want to delete number: ");
    }
    while (del_pos < 1 || del_pos > number_of_nodes);

    int i = 0;
    // delete the data from the given position
    for (node *tmp = head, *_tmp = head -> next; tmp; tmp = tmp -> next, _tmp = _tmp -> next, i++)
    {
        if (del_pos == 1)
        {
            tmp = tmp -> next;
            free(head);
            deleted = true;
            head = tmp;
            break;
        }
        else if (i == del_pos - 2)
        {
            tmp -> next = _tmp -> next;
            free(_tmp);
            deleted = true;
            break;
        }
    }
}

void delete_number()
{
    //the number which user wants to delete from the list
    int del_number = get_int("Enter the number you want to delete from the list: ");

    for (node *tmp = head, *_tmp = head -> next; _tmp; _tmp = tmp -> next)
    {
        // if the number is at the beginning
        if (head -> number == del_number)
        {
            free(head);
            deleted = true;
            head = _tmp;
            tmp = _tmp;
        }
        else if (_tmp -> number == del_number)
        {
            if (_tmp -> next != NULL)
            {
                tmp -> next = _tmp -> next;
                free(_tmp);
                deleted = true;
                break;
            }
            else
            {
                tmp -> next = NULL;
                free(_tmp);
                deleted = true;
                _tmp = NULL;
                break;
            }
        }
        if (tmp -> next != NULL)
        {
            tmp = tmp -> next;
        }
    }
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
