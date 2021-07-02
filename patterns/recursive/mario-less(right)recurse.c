
#include <stdio.h>

void build(int n, int x, int s, int y);

int main(void)
{
    int hight;

    printf("Enter the hight: ");

    scanf("%d", &hight);

    build(hight, 1, 0, 0);

    return 0;
}


void build(int n, int x, int s, int y)
{
    if (n == y)
    {
        printf("\n");
        return;
    }
    if (y == x)
    {
        printf("\n");
        return build(n, x + 1, 0, 0);
    }

    if (y == 0 && x < n)
    {
        printf(" ");
        s++;
    }

    if (s == (n - 1) - (x - 1))
    {
        printf("#");
        y++;
        return build(n, x, s, y);
    }
    else
    {
        return build(n, x, s, y);
    }
}





