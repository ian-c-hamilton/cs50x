#include <cs50.h>
#include <stdio.h>

void printSpaces(int s);
void printHashes(int h);

int main(void)
{
    int height;
    int spaces;
    int hashes;
    int row;
    do
    {
        height = get_int("How tall would you like the pyramid? ");
    }
    while (height < 1 || height > 8);
    row = 1;
    hashes = 1;
    spaces = height - row;
    while (row <= height)
    {
        printSpaces(spaces);
        printHashes(hashes);
        printf("  ");
        printHashes(hashes);
        printf("\n");
        row++;
        hashes++;
        spaces--;
    }
}

// Create a function to print spaces a given number of times
void printSpaces(int s)
{
    for (int i = 0; i < s; i++)
    {
        printf(" ");
    }
}

// Create a function that prints hashes a given number of times
void printHashes(int h)
{
    for (int j = 0; j < h; j++)
    {
        printf("#");
    }
}
