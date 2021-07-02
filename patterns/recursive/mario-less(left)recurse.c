#include <stdio.h>
#include <cs50.h>

void build(int n, int x, int y);

int main(void)
{
    int hight;
    do
    {
    hight = get_int("Enter the hight: ");
    }
    while (hight < 0);

    build(hight, 1, 0);
}


// the 'x' variable keeps track of rows and the 'y' variable keeps track of number of hashes in each row
void build(int n, int x, int y)
{
    if (x == n + 1)
    {
        return;
    }

    printf("#");
    y++;

    if (y == x)
    {
        printf("\n");
        return build(n, x + 1, 0);
    }
    else
    {
        return build(n, x, y);
    }
}
