// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>

#include "dictionary.h"



// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

void free_list(node *head);

int word_count = 0;         // Count total number of words in the dictionary
FILE *file = NULL;          // file pointer for file I/Os

// TODO: Choose number of buckets in hash table
const unsigned int N = 12000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Convert all the characters in the word to lowercase
    char checkee_word[strlen(word) + 1];

    for (int i = 0, n = strlen(word) + 1; i < n; i++)
    {
        checkee_word[i] = tolower(word[i]);
    }

    // Search the hash table for that word
    for (node *tmp = table[hash(checkee_word)]; tmp; tmp = tmp -> next)
    {
        if (strcasecmp(tmp -> word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // This hash function will cube the value of every character in a word and add all those cubes to make the sum and return the mod of the sum
    long sum = 0;
    for (int i = 0, n = strlen(word) + 1; i < n; i++)
    {
        sum += pow(word[i], 3);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the dictionary file
    file = fopen(dictionary, "r");

    // If the file wasn't opened, exit
    if (!file)
    {
        return false;
    }

    // Traverse the dictionary and read every word in the c[] array and check the dictionary for that word
    char c[LENGTH];

    while (fscanf(file, "%s", c) != EOF)
    {
        // Create a new node for storing the word in the hash table
        node *new_node = malloc(sizeof(node));
        // If the node wasn't created for memory issues, exit
        if (!new_node)
        {
            return false;
        }

        // Copy that word from c[] to the new node
        strcpy(new_node -> word, c);
        new_node -> next = NULL;

        // Update the word counter by 1 after adding each word to the table
        word_count++;

        // Insert the new node into the hash table at its respective index determined by the hash function
        int index = hash(c);

        if (table[index] == NULL)
        {
            table[index] = new_node;
        }
        else
        {
            node *tmp = table[index];

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
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // Return the total number of words in the dictionary
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Free the each element in the hash table
    node *tmp;
    for (int i = 0; i < N; i++)
    {
        tmp = table[i];
        // Free the list existing at current bucket
        free_list(tmp);
    }

    // Close the file
    fclose(file);

    return true;
}

void free_list(node *head)
{
    // Free the linked list starting with "head" pointer
    while (head)
    {
        node *tmp = head -> next;
        free(head);
        head = tmp;
    }
}