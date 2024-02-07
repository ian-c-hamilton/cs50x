#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>


int main(void)
{
    // Initializes all the variables
    int letters = 0;
    int words = 0;
    int sentences = 0;
    // Gets the text to analyze from the user
    string text = get_string("Text: ");
    // Goes through the text one character at a time
    for (int i = 0; i < strlen(text); i++)
    {
        // If the character is an english letter, increase letters
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
        // If the character is a space or the null character (for the very last word) increase words
        if (text[i] == 32 || text[i + 1] == 0)
        {
            words++;
        }
        // If the characters is a . ? or !, increase sentences
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }
    // Calculate the values L and S for the index
    float L = letters / (words / 100.0);
    float S = sentences / (words / 100.0);
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    //printf("%i letter(s)\n%i word(s)\n%i sentences\n", letters, words, sentences);

}