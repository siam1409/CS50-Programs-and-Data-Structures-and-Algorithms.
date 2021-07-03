#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Prototype declaration for the function
bool isvalid(string array[], int n);

int main(int argc, string argv[])
{
    // make sure the user provided only 2 command line argument
    if (argc == 2)
    {
        //find the length of the cipher key input string
        int lengthofkey = strlen(argv[1]);

        //check if all the charecters of the key input string is a digit
        if (isvalid(argv, lengthofkey))
        {
            // convert the cipher key input of command line argument from string to that number
            int key = atoi(argv[1]);

            string plain_text;

            // Prompt the user for a plaintext
            do
            {
                plain_text = get_string("plaintext: ");
            }
            while (strlen(plain_text) == 0);

            //find out the length of the plaintext
            int textlength = strlen(plain_text);

            // generate the ciphertext by rotating each alphabet by user provided position
            for (int i = 0; i < textlength; i++)
            {
                // enchipher the each i'th element of the string only if that is an alphabet
                if (isalpha(plain_text[i]))
                {
                    if (isupper(plain_text[i]))
                    {
                        plain_text[i] = (((plain_text[i] - 'A') + key) % 26) + 'A';
                    }
                    else if (islower(plain_text[i]))
                    {
                        plain_text[i] = (((plain_text[i] - 'a') + key) % 26) + 'a';
                    }
                }
            }
            // print a new line after the whole cipher text
            printf("ciphertext: %s\n", plain_text);

            //exit status of the "main" function
            return 0;
        }
        else
        {
            // if all the charecters of the key input string is not digit then exit
            printf("invalid cipher key\n");

            return 1;
        }
    }
    else
    {
        // if the user didn't provide the cipher key at all then show the instruction and exit
        printf("Usage: ./caesar key\n");

        return 1;
    }
}




bool isvalid(string array[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (isdigit(array[1][i]))
        {
            count++;
        }
    }
    if (count == n)
    {
        return true;
    }
    return false;
}
