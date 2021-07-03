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

            string cipher_text;

            // Prompt the user for a ciphertext
            do
            {
                cipher_text = get_string("ciphertext: ");
            }
            while (strlen(cipher_text) == 0);

            //find out the length of the ciphertext
            int textlength = strlen(cipher_text);

            // generate the plain text by reversely rotating each alphabet by user provided position
            for (int i = 0; i < textlength; i++)
            {
                // decrypt the each i'th element of the plaintext only if that is an alphabet
                if (isalpha(cipher_text[i]))
                {
                    if (isupper(cipher_text[i]))
                    {
                        cipher_text[i] = (((cipher_text[i] - 'A') - key) % 26) + 'A';
                    }
                    else if (islower(cipher_text[i]))
                    {
                        cipher_text[i] = (((cipher_text[i] - 'a') - key) % 26) + 'a';
                    }
                }
            }
            // print a new line after the whole  plaintexttext
            printf("plaintext: %s\n", cipher_text);

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
