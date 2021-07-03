#include <stdio.h>
#include <cs50.h>
#include <math.h>

//declare the prototype of the function
float get_change(void);

//initialize all the coins with their names
const int quarter = 25;
const int dime = 10;
const int nickel = 5;
const int penny = 1;

int main(void)
{
    //prompt the user to input his owed change in dollar
    float dollars = get_change();

    //round the dollars to the nearest penny
    int cents = round(dollars * 100);

    //declare and initialize the 'coin' variable to keep track of how many coins used
    int coins = 0;

    //calculate the fewest numbers of coins to provide that amount fo change
    while (cents > 0)
    {
        while (cents >= quarter)
        {
            cents = cents - quarter;
            coins++;
        }
        while (cents >= dime)
        {
            cents = cents - dime;
            coins++;
        }
        while (cents >= nickel)
        {
            cents = cents - nickel;
            coins++;
        }
        while (cents >= penny)
        {
            cents = cents - penny;
            coins++;
        }
    }

    //print the number of coins used to give the change
    printf("%i\n", coins);
    
    //exit status of the program
    return 0;

}


//define the function that avoids invalid input for owed change
float get_change(void)
{
    float n;
    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0.0);
    return n;
}
