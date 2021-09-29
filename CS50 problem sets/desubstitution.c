#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Prototype declaration for the functions
bool isvalid(string array[]);
int sumofkeychars(string key[]);
int position(char letter, string argarray[]);


int main(int argc, string argv[])
{
    // declare a string for zero indexing all the alphabets
    string allAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // make sure that the user provided only 2 command line arguments
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
                    // prompt the user for a ciphertext
                    string ciphertext;
                    do
                    {
                        ciphertext = get_string("ciphertext: ");
                    }
                    while (strlen(ciphertext) == 0);

                    // decrypt the ciphertext using the key that the user provided
                    for (int i = 0, n = strlen(ciphertext); i < n; i++)
                    {
                        // substitute each charecter if and only if that is an alphabet
                        if (isalpha(ciphertext[i]))
                        {
                            // decrypt the ciphertext perserving case
                            if (isupper(ciphertext[i]))
                            {
                                // convert the i'th character to the character at the index of "i'th character's position in cipher key" in allAlpha string preserving case
                                ciphertext[i] = toupper(allAlpha[position(ciphertext[i], argv)]);
                            }
                            else
                            {
                                ciphertext[i] = tolower(allAlpha[position(ciphertext[i], argv)]);
                            }
                        }
                    }

                    // print the plaintext
                    printf("plaintext: %s\n", ciphertext);

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
        printf("Usage: ./desubstitution KEY\n");
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




int position(char letter, string argarray[])
{
    int pos = 0;

    for (int i = 0; i < 26; i++)
    {
        if (toupper(argarray[1][i]) == toupper(letter))
        {
            pos = i;
        }
    }

    return pos;
}
