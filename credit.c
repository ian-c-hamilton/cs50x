#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

//Function to get a digit in a specific place of a large number, found online

long get_digit(long number, int place)
{
    long x;

    x = number / pow(10, place);

    x = x % 10;

    return x;
}


int main(void)
{
    int valid = 0;
    long number = 0;
    int length = 0;
    int i;
    int nonmults = 0;
    int sum = 0;
    int num;
    int tot = 0;
    // Gets a long from the user
    number = get_long("Please Enter a Valid Credit Card Number:\n");
    // Finds the length of the number entered, found online
    length = floor(log10(labs(number))) + 1;

    // Multiplies every other digit by 2
    for (i = 1; i <= length; i += 2)
    {
        num = 2 * get_digit(number, i);
        // If the digit * 2 is greater than 9, it adds the digits of that together first
        if (num > 9)
        {
            // Add the two digits together before adding that total to the running sum
            sum = sum + get_digit(num, 0) + get_digit(num, 1);
        }
        else
        {
            sum += num;
        }
    }
    for (i = 0; i <= length; i += 2)
    {
        // Simply adds the numbers that weren't ultiplied by two together
        nonmults += get_digit(number, i);
    }
    tot = sum + nonmults;
    // Checks the modulus to see of the result was divisible by ten
    if (tot % 10 == 0)
    {
        valid = 1;
    }
    // Gets the first and second numbers of the card to check which type it is
    int first = get_digit(number, length - 1);
    int second = get_digit(number, length - 2);
    if (valid == 1 && length == 15 && first == 3 && (second == 4 || second == 7))
    {
        printf("AMEX\n");
    }
    else if (valid == 1 && length == 16 && first == 5 && (second == 1 || second == 2 || second == 3 || second == 4 || second == 5))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && first == 4 && valid == 1)
    {
        printf("VISA\n");
    }
    else
    {
        valid = 0;
    }
    if (valid == 0)
    {
        printf("INVALID\n");
    }
}