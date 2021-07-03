#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Prototype declaration for the functions
bool isvalid(string array[]);
int sumofkeychars(string key[]);

int main(int argc, string argv[])
{
    // make sure that the user provided only 2 command line argument
    if (argc == 2)
    {
        // find the length of the cipher key input string
        int keylength = strlen(argv[1]);

        // make sure that the key contains 26 charecters
        if (keylength == 26)
        {
            // make sure that all the charecters of the key is an alphabet
            if (isvalid(argv))
            {
                // make sure that the key does not contain any repeated charecters by comparing the sum of their ASCII value
                if (sumofkeychars(argv) == 2015)
                {
                    // prompt the user for a plaintext
                    string plaintext;
                    do
                    {
                        plaintext = get_string("plaintext: ");
                    }
                    while (strlen(plaintext) == 0);

                    // enchipher the plaintext using the key that the user provided
                    for (int i = 0, n = strlen(plaintext); i < n; i++)
                    {
                        // enchipher each charecter if and only if that is an alphabet
                        if (isalpha(plaintext[i]))
                        {
                            // enchipher the plaintext perserving case
                            if (isupper(plaintext[i]))
                            {
                                plaintext[i] = toupper(argv[1][plaintext[i] - 'A']);
                            }
                            else
                            {
                                plaintext[i] = tolower(argv[1][plaintext[i] - 'a']);
                            }
                        }
                    }

                    // print the ciphertext
                    printf("ciphertext: %s\n", plaintext);

                    // exit from the main function with status code 0
                    return 0;
                }
                else
                {
                    // if the key contains repeated charecters, then report that and exit with status code 1
                    printf("key should not contain repeated charecters\n");
                    return 1;
                }
            }
            else
            {
                // if the key contains non-alphabetic charecters, then report that and exit with status code 1
                printf("key must contain only alphabetic charecters\n");
                return 1;
            }
        }
        else
        {
            // if the key contains less then 26 charecters, then report that and exit with status code 1
            printf("Key must contain only 26 charecters\n");
            return 1;
        }
    }
    else
    {
        // if the user didn't provide the at all or provided more command line arguments, then show the usage and exit with status code 1
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
}






bool isvalid(string array[])
{
    int count = 0;

    for (int i = 0; i < 26; i++)
    {
        if (isalpha(array[1][i]))
        {
            count++;
        }
    }
    if (count == 26)
    {
        return true;
    }
    return false;
}




int sumofkeychars(string key[])
{
    int sum = 0;

    for (int i = 0; i < 26; i++)
    {
        sum += toupper(key[1][i]);
    }
    return sum;
}

