#include <stdio.h>
#include <cs50.h>
#include <math.h>

int find_length(long n);

int main(void)
{
    // Get the card number from the user
    long card_number = get_long("Number: ");

    // Make a copy of the number to apply the checksum
    long cardcp = card_number;

    // Find out the length of the number
    int length = find_length(card_number);

    // otherdigits[] array will store every other digit and multiply all by 2 indivudually.
    // restsum will the store the sum of the numbers which weren't multiplied by 2
    int otherdigits[length], restsum = 0;

    // Set every element of the otherdigit[] array to 0
    for (int i = 0; i < length; i++)
    {
        otherdigits[i] = 0;
    }

    for (int i = 1; i <= length; i++)
    {
        // Check if the last number is in an other position
        if (i % 2 == 0)
        {
            // Multiply the digit by 2
            otherdigits[i - 1] = (cardcp % 10) * 2;
        }
        else
        {
            // If the last number is not in an other position then add them to the restsum
            restsum += cardcp % 10;
        }
        // Update the copy of the card_number to get the next last digit (Befriend with Truncation)
        cardcp /= 10;
    }

    // othersum will store the sum of every products' digit of the othersum[] array
    // totalsum will store the sum of othersum and restsum
    // dig1 and dig2 will the store the digits of any othersum[] element with two digits respectively
    int othersum = 0, totalsum = 0, dig1 = 0, dig2 = 0;

    // Add all the digits of every element of othersum[]
    for (int i = 0; i < length; i++)
    {
        if (otherdigits[i] < 10)
        {
            othersum += otherdigits[i];
        }
        else
        {
            dig1 = otherdigits[i] % 10;
            dig2 = otherdigits[i] / 10;
            othersum += dig1;
            othersum += dig2;
        }
    }

    // Find the totalsum
    totalsum = othersum + restsum;

    bool valid = false;

    // If the last digit of totalsum is 0, that means the check sum is satisfied
    if (totalsum % 10 == 0)
    {
        valid = true;
    }

    // Check the final validity of the card number

    if (length == 13 && card_number / 1000000000000 == 4 && valid)
    {
        // If the length is 13, and the last digit is 4, and it satisfies the checksum then it must be a VISA card
        printf("VISA\n");
        return 0;
    }
    else if (length == 15 && (card_number / 10000000000000 == 34 || card_number / 10000000000000 == 37) && valid)
    {
        // If the length is 15 and last two digits of card number is 34 or 37 and the checksum is satisfied then it must be an American express card
        printf("AMEX\n");
        return 0;
    }
    else if (length == 16)
    {
        // If the lenght is 16, it might be a VISA or a MASTERCARD
        if (card_number / 1000000000000000 == 4 && valid)
        {
            // If the last digit is 4 and checksum is satisfied it must a VISA card
            printf("VISA\n");
            return 0;
        }
        else if (card_number / 100000000000000 < 56 && card_number / 100000000000000 > 50 && valid)
        {
            // If the last two digits are in-between 56 and 50 and the checksum is statisfied it must be a MASTERCARD instead
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
            // If none of the conditions are true that means the card number is invalid
            printf("INVALID\n");
            return 0;
        }
    }

    // If any of the conditions above were not true the card number must be invalid
    printf("INVALID\n");
    return 0;
}

int find_length(long n)
{
    int length;

    for (length = 0; n != 0; length++)
    {
        n /= 10;
    }

    return length;
}
