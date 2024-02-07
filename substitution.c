#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Print and error and exit if 2 arguments aren't given
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Set the cypher to the second argument from the command line
    string cypher = argv[1];

    // Print an error message if the cypher is invalid by not being 26 characters
    int len = strlen(cypher);
    if (len != 26)
    {
        printf("Key must contain 26 letters only.\n");
        return 1;
    }
    int sum = 0;
    // Checks every letter in the cypher and capitalizes it for easier checking and comparison
    for (int i = 0; i <= len - 1; i++)
    {
        // Capitalizes every character
        cypher[i] = toupper(cypher[i]);
        //printf("%i", cypher[i]);
        // If the ASCII value of a character is outside the range of 65 and 90, then it is not a capital letter and is invalid
        if (cypher[i] < 65 || cypher[i] > 90)
        {
            printf("Please enter a valid key, letters only\n");
            return 1;
        }

        sum += cypher[i];

    }
    // We know that the sum of all the ascii values for any given key should always be 2015, no matter their order. If it is not 2015, then a character is missing or duplicated
    if (sum != 2015)
    {
        printf("Please enter a valid key, each letter appearing only once\n");
        return 1;
    }
    // Get the plain text string from the user
    string plain = get_string("plaintext: ");
    // Create a copy of the text to alter, without messing with the original
    char plainlen[strlen(plain)];
    string copy = strcpy(plainlen, plain);
    // Initialize the cypher text string as the plain for now
    string cyphertext = copy;
    // Creates an array of length plain to be used as the index of the cypher
    int index[strlen(copy)];

    // loops through each character in the plain text
    for (int i = 0; i < strlen(copy); i++)
    {
        // Capitalizes the copy of plain text for easy indexing
        copy[i] = toupper(copy[i]);
        // If the character in the string is alphabetical, subtract 65 from its value and that is the index of its substitution in the cypher
        if (isalpha(copy[i]))
        {
            index[i] = copy[i] - 65;
            cyphertext[i] = cypher[index[i]];
        }
        else
        {
            cyphertext[i] = copy[i];
        }


        // If the character is lower case in the original text, make it lower case in the cypher text
        if (islower(plain[i]))
        {
            //printf("lower");
            cyphertext[i] = tolower(cyphertext[i]);
        }
        else
        {
            //printf("upper");
            cyphertext[i] = cyphertext[i];
        }

    }

    //printf("%s\n", plain);
    printf("ciphertext: %s\n", cyphertext);
    return 0;

}