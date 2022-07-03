#include <cs50.h>
#include <stdio.h>

void printStairs(int side, int i, int j);

int main(void)
{
    // Get the height of the pyramid between 1 and 8
    int height;
    do
    {
        height = get_int("How tall should the pyramids be? ");
    }
    while (height < 1 || height > 8);

    // Loop the columns
    for (int i = 0; i < height; i++)
    {
        // Loop the rows

        // Left stairs
        for (int j = height; j > 0; j--)
        {
            printStairs(1, i, j);
        }

        // Middle fault
        printf("  ");

        // Right stairs
        for (int j = 0; j < height; j++)
        {
            printStairs(0, i, j);
        }

        // Line break
        printf("\n");
    }
}

// 1 for left, 0 for right
void printStairs(int side, int i, int j)
{
    if (j > i + side)
    {
        if (side == 1)
        {
            printf(" ");
        }
    }
    else
    {
        printf("#");
    }
}