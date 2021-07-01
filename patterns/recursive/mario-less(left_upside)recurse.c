#include <stdio.h>
#include <cs50.h>

void build(int n, int x, int y);

int main(void)
{
    // prompt the user for hight of the pyrramid
    int hight;
    do
    {
        hight = get_int("Enter the hight: ");
    }
    while (hight < 0);
    
    build(hight, 1, 0);

    // exit with status code 0
    return 0;
}

void build(int n, int x, int y)
{
    if (x == n + 1)
    {
        return;
    } 
    
    printf("#");
    y++;
    
    if (y == n - (x - 1))
    {
        printf("\n");
        build(n, x + 1, 0);
    }
    else
    {
        build(n, x, y);
    }
}
