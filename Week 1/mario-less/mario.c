#include <cs50.h>
#include <stdio.h>

void print_stairs(int height);

int main(void)
{
    // Get the height of the pyramid between 1 and 8
    int height;
    do
    {
        height = get_int("How tall should the pyramids be? ");
    }
    while (height < 1 || height > 8);

    print_stairs(height);
}

// Print stairs
void print_stairs(int height)
{
    for (int i = 0; i < height; i++)
    {
        // Loop the rows
        for (int j = height; j > 0; j--)
        {
            // Print the stair
            if (j > i + 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        // Line break
        printf("\n");
    }
}