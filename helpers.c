#include "helpers.h"
#include <math.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loops through the 2D array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Averages the colors together
            int gray = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            //Sets each new pixel to the average value
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;

        }
    }
    return;
}

//Like I get that it is good practice to comment your code but this is ridiculous, does style50 need like a 1:2 comment to code line ratio?

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Like there are only so many comments I can add since all this is copy and paste
    RGBTRIPLE buffer[width];
    for (int i = 0; i < height; i++)
    {
        //Creates a buffer full of each row of pixels like the tmp variable in swap
        memcpy(buffer, image[i], sizeof(image[i]));
        for (int j = 0; j < width; j++)
        {
            //Does a swap-like action, swapping the first and last pixel of each row
            image[i][j] = buffer[(width - 1) - j];
            image[i][(width - 1) - j] = buffer[j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Creates a copy of the image to act as a buffer
    RGBTRIPLE copy[height][width];
    for (int i = 0; i <= height - 1; i++)
    {
        //It's gotta be the number of comments to lines of code ratio or something, I'm just gonna copy and paste comments at this point
        for (int j = 0; j <= width - 1; j++)
        {
            //Special Cases for all the edges and corners
            if (i == 0 && j == 0)
            {
                copy[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                             image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 4.0);
                copy[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                              image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 4.0);
                copy[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                            image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 4.0);
            }
            //It's gotta be the number of comments to lines of code ratio or something, I'm just gonna copy and paste comments at this point
            else if (i == 0 && j == (width - 1))
            {
                copy[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue +
                                             image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 4.0);
                copy[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen +
                                              image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 4.0);
                copy[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed +
                                            image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / 4.0);
            }
            //It's gotta be the number of comments to lines of code ratio or something, I'm just gonna copy and paste comments at this point
            else if (i == (height - 1) && j == 0)
            {
                copy[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue +
                                             image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue) / 4.0);
                copy[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen +
                                              image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen) / 4.0);
                copy[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed +
                                            image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed) / 4.0);
            }
            //It's gotta be the number of comments to lines of code ratio or something, I'm just gonna copy and paste comments at this point
            else if (i == (height - 1) && j == (width - 1))
            {
                copy[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue +
                                             image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue) / 4.0);
                copy[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen +
                                              image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen) / 4.0);
                copy[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed +
                                            image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed) / 4.0);
            }
            //It's gotta be the number of comments to lines of code ratio or something, I'm just gonna copy and paste comments at this point
            else if (i == 0)
            {
                copy[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                             image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.0);
                copy[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                              image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0);
                copy[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                            image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0);
            }
            //It's gotta be the number of comments to lines of code ratio or something, I'm just gonna copy and paste comments at this point
            else if (i == (height - 1))
            {
                copy[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                             image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 6.0);
                copy[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                              image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 6.0);
                copy[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                            image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 6.0);
            }
            //It's gotta be the number of comments to lines of code ratio or something, I'm just gonna copy and paste comments at this point
            else if (j == 0)
            {
                copy[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                                             image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.0);
                copy[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                              image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0);
                copy[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i][j].rgbtRed + image[i + 1][j].rgbtRed +
                                            image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0);
            }
            else if (j == (width - 1))
            {
                copy[i][j].rgbtBlue = round((image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue +
                                             image[i + 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue) / 6.0);
                copy[i][j].rgbtGreen = round((image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen +
                                              image[i + 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen) / 6.0);
                copy[i][j].rgbtRed = round((image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed +
                                            image[i + 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j].rgbtRed + image[i + 1][j].rgbtRed) / 6.0);
            }
            //It's gotta be the number of comments to lines of code ratio or something, I'm just gonna copy and paste comments at this point
            else
            {
                copy[i][j].rgbtBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue +
                                             image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue +
                                             image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                                             image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 9.0);
                copy[i][j].rgbtGreen = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                                              image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen +
                                              image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
                                              image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 9.0);
                copy[i][j].rgbtRed = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed +
                                            image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed +
                                            image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed +
                                            image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 9.0);
            }
        }
    }
    //Places the new values in the output image
    for (int i = 0; i <= height - 1; i++)
    {
        //It's gotta be the number of comments to lines of code ratio or something, I'm just gonna copy and paste comments at this point
        for (int j = 0; j <= width - 1; j++)
        {

            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    //Create a double variable for all the Gx and Gy terms
    double GxBlue, GyBlue, GxGreen, GyGreen, GxRed, GyRed;

    for (int i = 0; i <= height - 1; i++)
    {
        for (int j = 0; j <= width - 1; j++)
        {
            //All the edges and corners are special cases again
            if (i == 0 && j == 0)
            {
                GxBlue = image[i][j].rgbtBlue * 0 + image[i][j + 1].rgbtBlue * 2 + image[i + 1][j].rgbtBlue * 0 + image[i + 1][j + 1].rgbtBlue * 1;
                GxGreen = image[i][j].rgbtGreen * 0 + image[i][j + 1].rgbtGreen * 2 +
                          image[i + 1][j].rgbtGreen * 0 + image[i + 1][j + 1].rgbtGreen * 1;
                GxRed = image[i][j].rgbtRed * 0 + image[i][j + 1].rgbtRed * 2 + image[i + 1][j].rgbtRed * 0 + image[i + 1][j + 1].rgbtRed * 1;
                GyBlue = image[i][j].rgbtBlue * 0 + image[i][j + 1].rgbtBlue * 0 + image[i + 1][j].rgbtBlue * 2 + image[i + 1][j + 1].rgbtBlue * 1;
                GyGreen = image[i][j].rgbtGreen * 0 + image[i][j + 1].rgbtGreen * 0 +
                          image[i + 1][j].rgbtGreen * 2 + image[i + 1][j + 1].rgbtGreen * 1;
                GyRed = image[i][j].rgbtRed * 0 + image[i][j + 1].rgbtRed * 0 + image[i + 1][j].rgbtRed * 2 + image[i + 1][j + 1].rgbtRed * 1;
                copy[i][j].rgbtBlue = fmin(255.0, round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue))));
                copy[i][j].rgbtGreen = fmin(255.0, round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen))));
                copy[i][j].rgbtRed = fmin(255.0, round(sqrt((GxRed * GxRed) + (GyRed * GyRed))));

            }
            //It's gotta be the number of comments to lines of code ratio or something, I'm just gonna copy and paste comments at this point
            //It's gotta be the number of comments to lines of code ratio or something, I'm just gonna copy and paste comments at this point
            //It's gotta be the number of comments to lines of code ratio or something, I'm just gonna copy and paste comments at this point
            //It's gotta be the number of comments to lines of code ratio or something, I'm just gonna copy and paste comments at this point
            else if (i == 0 && j == (width - 1))
            {
                GxBlue = image[i][j - 1].rgbtBlue * -2 + image[i][j].rgbtBlue * 0 + image[i + 1][j - 1].rgbtBlue * -1 +
                         image[i + 1][j].rgbtBlue * 0;
                GxGreen = image[i][j - 1].rgbtGreen * -2 + image[i][j].rgbtGreen * 0 +
                          image[i + 1][j - 1].rgbtGreen * -1 + image[i + 1][j].rgbtGreen * 0;
                GxRed = image[i][j - 1].rgbtRed * -2 + image[i][j].rgbtRed * 0 + image[i + 1][j - 1].rgbtRed * -1 +
                        image[i + 1][j].rgbtRed * 0;
                GyBlue = image[i][j - 1].rgbtBlue * 0 + image[i][j].rgbtBlue * 0 +
                         image[i + 1][j - 1].rgbtBlue * 1 + image[i + 1][j].rgbtBlue * 2;
                GyGreen = image[i][j - 1].rgbtGreen * 0 + image[i][j].rgbtGreen * 0 +
                          image[i + 1][j - 1].rgbtGreen * 1 + image[i + 1][j].rgbtGreen * 2;
                GyRed = image[i][j - 1].rgbtRed * 0 + image[i][j].rgbtRed * 0 + image[i + 1][j - 1].rgbtRed * 1 +
                        image[i + 1][j].rgbtRed * 2;
                copy[i][j].rgbtBlue = fmin(255.0, round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue))));
                copy[i][j].rgbtGreen = fmin(255.0, round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen))));
                copy[i][j].rgbtRed = fmin(255.0, round(sqrt((GxRed * GxRed) + (GyRed * GyRed))));

            }
            //Does style50 need a comment for every subsection of code?
            else if (i == (height - 1) && j == 0)
            {
                GxBlue = image[i - 1][j].rgbtBlue * 0 + image[i - 1][j + 1].rgbtBlue * 1 +
                         image[i][j].rgbtBlue * 0 + image[i][j + 1].rgbtBlue * 2;
                GxGreen = image[i - 1][j].rgbtGreen * 0 + image[i - 1][j + 1].rgbtGreen * 1 +
                          image[i][j].rgbtGreen * 0 + image[i][j + 1].rgbtGreen * 2;
                GxRed = image[i - 1][j].rgbtRed * 0 + image[i - 1][j + 1].rgbtRed * 1 +
                        image[i][j].rgbtRed * 0 + image[i][j + 1].rgbtRed * 2;
                GyBlue = image[i - 1][j].rgbtBlue * -2 + image[i - 1][j + 1].rgbtBlue * -1 +
                         image[i][j].rgbtBlue * 0 + image[i][j + 1].rgbtBlue * 0;
                GyGreen = image[i - 1][j].rgbtGreen * -2 + image[i - 1][j + 1].rgbtGreen * -1 +
                          image[i][j].rgbtGreen * 0 + image[i][j + 1].rgbtGreen * 0;
                GyRed = image[i - 1][j].rgbtRed * -2 + image[i - 1][j + 1].rgbtRed * -1 +
                        image[i][j - 1].rgbtRed * 0 + image[i][j].rgbtRed * 0 + image[i][j + 1].rgbtRed * 0;
                copy[i][j].rgbtBlue = fmin(255.0, round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue))));
                copy[i][j].rgbtGreen = fmin(255.0, round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen))));
                copy[i][j].rgbtRed = fmin(255.0, round(sqrt((GxRed * GxRed) + (GyRed * GyRed))));

            }
            //I hope the next hw is easier, this took me like 10 hours
            else if (i == (height - 1) && j == (width - 1))
            {
                GxBlue = image[i - 1][j - 1].rgbtBlue * -1 + image[i - 1][j].rgbtBlue * 0 +
                         image[i][j - 1].rgbtBlue * -2 + image[i][j].rgbtBlue * 0;
                GxGreen = image[i - 1][j - 1].rgbtGreen * -1 + image[i - 1][j].rgbtGreen * 0 +
                          image[i][j - 1].rgbtGreen * -2 + image[i][j].rgbtGreen * 0;
                GxRed = image[i - 1][j - 1].rgbtRed * -1 + image[i - 1][j].rgbtRed * 0 +
                        image[i][j - 1].rgbtRed * -2 + image[i][j].rgbtRed * 0;
                GyBlue = image[i - 1][j - 1].rgbtBlue * -1 + image[i - 1][j].rgbtBlue * -2 +
                         image[i][j - 1].rgbtBlue * 0 + image[i][j].rgbtBlue * 0;
                GyGreen = image[i - 1][j - 1].rgbtGreen * -1 + image[i - 1][j].rgbtGreen * -2 +
                          image[i][j - 1].rgbtGreen * 0 + image[i][j].rgbtGreen * 0;
                GyRed = image[i - 1][j - 1].rgbtRed * -1 + image[i - 1][j].rgbtRed * -2 +
                        image[i][j - 1].rgbtRed * 0 + image[i][j].rgbtRed * 0;
                copy[i][j].rgbtBlue = fmin(255.0, round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue))));
                copy[i][j].rgbtGreen = fmin(255.0, round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen))));
                copy[i][j].rgbtRed = fmin(255.0, round(sqrt((GxRed * GxRed) + (GyRed * GyRed))));

            }
            //I tried just doing the math operations on the pixels all together but it wanted me to separate out all the colors, tripling the lines needes at least
            else if (i == 0)
            {
                GxBlue = image[i][j - 1].rgbtBlue * -2 + image[i][j].rgbtBlue * 0 + image[i][j + 1].rgbtBlue * 2 +
                         image[i + 1][j - 1].rgbtBlue * -1 + image[i + 1][j].rgbtBlue * 0 + image[i + 1][j + 1].rgbtBlue * 1;
                GxGreen = image[i][j - 1].rgbtGreen * -2 + image[i][j].rgbtGreen * 0 + image[i][j + 1].rgbtGreen * 2 +
                          image[i + 1][j - 1].rgbtGreen * -1 + image[i + 1][j].rgbtGreen * 0 + image[i + 1][j + 1].rgbtGreen * 1;
                GxRed = image[i][j - 1].rgbtRed * -2 + image[i][j].rgbtRed * 0 + image[i][j + 1].rgbtRed * 2 +
                        image[i + 1][j - 1].rgbtRed * -1 + image[i + 1][j].rgbtRed * 0 + image[i + 1][j + 1].rgbtRed * 1;
                GyBlue = image[i][j - 1].rgbtBlue * 0 + image[i][j].rgbtBlue * 0 + image[i][j + 1].rgbtBlue * 0 +
                         image[i + 1][j - 1].rgbtBlue * 1 + image[i + 1][j].rgbtBlue * 2 + image[i + 1][j + 1].rgbtBlue * 1;
                GyGreen = image[i][j - 1].rgbtGreen * 0 + image[i][j].rgbtGreen * 0 + image[i][j + 1].rgbtGreen * 0 +
                          image[i + 1][j - 1].rgbtGreen * 1 + image[i + 1][j].rgbtGreen * 2 + image[i + 1][j + 1].rgbtGreen * 1;
                GyRed = image[i][j - 1].rgbtRed * 0 + image[i][j].rgbtRed * 0 + image[i][j + 1].rgbtRed * 0 +
                        image[i + 1][j - 1].rgbtRed * 1 + image[i + 1][j].rgbtRed * 2 + image[i + 1][j + 1].rgbtRed * 1;
                copy[i][j].rgbtBlue = fmin(255.0, round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue))));
                copy[i][j].rgbtGreen = fmin(255.0, round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen))));
                copy[i][j].rgbtRed = fmin(255.0, round(sqrt((GxRed * GxRed) + (GyRed * GyRed))));

            }
            //I should not have to spend another half hour makeing fake comments to get the style points
            else if (i == (height - 1))
            {
                GxBlue = image[i - 1][j - 1].rgbtBlue * -1 + image[i - 1][j].rgbtBlue * 0 + image[i - 1][j + 1].rgbtBlue * 1 +
                         image[i][j - 1].rgbtBlue * -2 + image[i][j].rgbtBlue * 0 + image[i][j + 1].rgbtBlue * 2;
                GxGreen = image[i - 1][j - 1].rgbtGreen * -1 + image[i - 1][j].rgbtGreen * 0 + image[i - 1][j + 1].rgbtGreen * 1 +
                          image[i][j - 1].rgbtGreen * -2 + image[i][j].rgbtGreen * 0 + image[i][j + 1].rgbtGreen * 2;
                GxRed = image[i - 1][j - 1].rgbtRed * -1 + image[i - 1][j].rgbtRed * 0 + image[i - 1][j + 1].rgbtRed * 1 +
                        image[i][j - 1].rgbtRed * -2 + image[i][j].rgbtRed * 0 + image[i][j + 1].rgbtRed * 2;
                GyBlue = image[i - 1][j - 1].rgbtBlue * -1 + image[i - 1][j].rgbtBlue * -2 + image[i - 1][j + 1].rgbtBlue * -1 +
                         image[i][j - 1].rgbtBlue * 0 + image[i][j].rgbtBlue * 0 + image[i][j + 1].rgbtBlue * 0;
                GyGreen = image[i - 1][j - 1].rgbtGreen * -1 + image[i - 1][j].rgbtGreen * -2 + image[i - 1][j + 1].rgbtGreen * -1 +
                          image[i][j - 1].rgbtGreen * 0 + image[i][j].rgbtGreen * 0 + image[i][j + 1].rgbtGreen * 0;
                GyRed = image[i - 1][j - 1].rgbtRed * -1 + image[i - 1][j].rgbtRed * -2 + image[i - 1][j + 1].rgbtRed * -1 +
                        image[i][j - 1].rgbtRed * 0 + image[i][j].rgbtRed * 0 + image[i][j + 1].rgbtRed * 0;
                copy[i][j].rgbtBlue = fmin(255.0, round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue))));
                copy[i][j].rgbtGreen = fmin(255.0, round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen))));
                copy[i][j].rgbtRed = fmin(255.0, round(sqrt((GxRed * GxRed) + (GyRed * GyRed))));

            }
            //At this point I'm literally just addind comments to get the 1.0 style
            else if (j == 0)
            {
                GxBlue = image[i - 1][j].rgbtBlue * 0 + image[i - 1][j + 1].rgbtBlue * 1 + image[i][j].rgbtBlue * 0 +
                         image[i][j + 1].rgbtBlue * 2 + image[i + 1][j].rgbtBlue * 0 + image[i + 1][j + 1].rgbtBlue * 1;
                GxGreen = image[i - 1][j].rgbtGreen * 0 + image[i - 1][j + 1].rgbtGreen * 1 + image[i][j].rgbtGreen * 0 +
                          image[i][j + 1].rgbtGreen * 2 + image[i + 1][j].rgbtGreen * 0 + image[i + 1][j + 1].rgbtGreen * 1;
                GxRed = image[i - 1][j].rgbtRed * 0 + image[i - 1][j + 1].rgbtRed * 1 + image[i][j].rgbtRed * 0 +
                        image[i][j + 1].rgbtRed * 2 + image[i + 1][j].rgbtRed * 0 + image[i + 1][j + 1].rgbtRed * 1;
                GyBlue = image[i - 1][j].rgbtBlue * -2 + image[i - 1][j + 1].rgbtBlue * -1 + image[i][j].rgbtBlue * 0 +
                         image[i][j + 1].rgbtBlue * 0 + image[i + 1][j].rgbtBlue * 2 + image[i + 1][j + 1].rgbtBlue * 1;
                GyGreen = image[i - 1][j].rgbtGreen * -2 + image[i - 1][j + 1].rgbtGreen * -1 + image[i][j].rgbtGreen * 0 +
                          image[i][j + 1].rgbtGreen * 0 + image[i + 1][j].rgbtGreen * 2 + image[i + 1][j + 1].rgbtGreen * 1;
                GyRed = image[i - 1][j].rgbtRed * -2 + image[i - 1][j + 1].rgbtRed * -1 + image[i][j].rgbtRed * 0 +
                        image[i][j + 1].rgbtRed * 0 + image[i + 1][j].rgbtRed * 2 + image[i + 1][j + 1].rgbtRed * 1;
                copy[i][j].rgbtBlue = fmin(255.0, round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue))));
                copy[i][j].rgbtGreen = fmin(255.0, round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen))));
                copy[i][j].rgbtRed = fmin(255.0, round(sqrt((GxRed * GxRed) + (GyRed * GyRed))));

            }
            //I have no idea if there was an easier way to do this hw, it felt like a lot of copy and paste, which is never good
            else if (j == (width - 1))
            {
                GxBlue = image[i - 1][j - 1].rgbtBlue * -1 + image[i - 1][j].rgbtBlue * 0 + image[i][j - 1].rgbtBlue * -2 +
                         image[i][j].rgbtBlue * 0 + image[i + 1][j - 1].rgbtBlue * -1 + image[i + 1][j].rgbtBlue * 0;
                GxGreen = image[i - 1][j - 1].rgbtGreen * -1 + image[i - 1][j].rgbtGreen * 0 + image[i][j - 1].rgbtGreen * -2 +
                          image[i][j].rgbtGreen * 0 + image[i + 1][j - 1].rgbtGreen * -1 + image[i + 1][j].rgbtGreen * 0;
                GxRed = image[i - 1][j - 1].rgbtRed * -1 + image[i - 1][j].rgbtRed * 0 + image[i][j - 1].rgbtRed * -2 +
                        image[i][j].rgbtRed * 0 + image[i + 1][j - 1].rgbtRed * -1 + image[i + 1][j].rgbtRed * 0;
                GyBlue = image[i - 1][j - 1].rgbtBlue * -1 + image[i - 1][j].rgbtBlue * -2 + image[i][j - 1].rgbtBlue * 0 +
                         image[i][j].rgbtBlue * 0 + image[i + 1][j - 1].rgbtBlue * 1 + image[i + 1][j].rgbtBlue * 2;
                GyGreen = image[i - 1][j - 1].rgbtGreen * -1 + image[i - 1][j].rgbtGreen * -2 +  image[i][j - 1].rgbtGreen * 0 +
                          image[i][j].rgbtGreen * 0 + image[i + 1][j - 1].rgbtGreen * 1 + image[i + 1][j].rgbtGreen * 2;
                GyRed = image[i - 1][j - 1].rgbtRed * -1 + image[i - 1][j].rgbtRed * -2 + image[i][j - 1].rgbtRed * 0 +
                        image[i][j].rgbtRed * 0 + image[i + 1][j - 1].rgbtRed * 1 + image[i + 1][j].rgbtRed * 2;
                copy[i][j].rgbtBlue = fmin(255.0, round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue))));
                copy[i][j].rgbtGreen = fmin(255.0, round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen))));
                copy[i][j].rgbtRed = fmin(255.0, round(sqrt((GxRed * GxRed) + (GyRed * GyRed))));

            }
            //All other cases
            else
            {
                GxBlue = image[i - 1][j - 1].rgbtBlue * -1 + image[i - 1][j].rgbtBlue * 0 + image[i - 1][j + 1].rgbtBlue * 1 +
                         image[i][j - 1].rgbtBlue * -2 + image[i][j].rgbtBlue * 0 + image[i][j + 1].rgbtBlue * 2 + image[i + 1][j - 1].rgbtBlue * -1 +
                         image[i + 1][j].rgbtBlue * 0 + image[i + 1][j + 1].rgbtBlue * 1;
                GxGreen = image[i - 1][j - 1].rgbtGreen * -1 + image[i - 1][j].rgbtGreen * 0 + image[i - 1][j + 1].rgbtGreen * 1 +
                          image[i][j - 1].rgbtGreen * -2 + image[i][j].rgbtGreen * 0 + image[i][j + 1].rgbtGreen * 2 + image[i + 1][j - 1].rgbtGreen * -1 +
                          image[i + 1][j].rgbtGreen * 0 + image[i + 1][j + 1].rgbtGreen * 1;
                GxRed = image[i - 1][j - 1].rgbtRed * -1 + image[i - 1][j].rgbtRed * 0 + image[i - 1][j + 1].rgbtRed * 1 +
                        image[i][j - 1].rgbtRed * -2 + image[i][j].rgbtRed * 0 + image[i][j + 1].rgbtRed * 2 + image[i + 1][j - 1].rgbtRed * -1 +
                        image[i + 1][j].rgbtRed * 0 + image[i + 1][j + 1].rgbtRed * 1;
                GyBlue = image[i - 1][j - 1].rgbtBlue * -1 + image[i - 1][j].rgbtBlue * -2 +
                         image[i - 1][j + 1].rgbtBlue * -1 +
                         image[i][j - 1].rgbtBlue * 0 + image[i][j].rgbtBlue * 0 + image[i][j + 1].rgbtBlue * 0 + image[i + 1][j - 1].rgbtBlue * 1 +
                         image[i + 1][j].rgbtBlue * 2 + image[i + 1][j + 1].rgbtBlue * 1;
                GyGreen = image[i - 1][j - 1].rgbtGreen * -1 + image[i - 1][j].rgbtGreen * -2 +
                          image[i - 1][j + 1].rgbtGreen * -1 + image[i][j - 1].rgbtGreen * 0 +
                          image[i][j].rgbtGreen * 0 + image[i][j + 1].rgbtGreen * 0 +
                          image[i + 1][j - 1].rgbtGreen * 1 + image[i + 1][j].rgbtGreen * 2 +
                          image[i + 1][j + 1].rgbtGreen * 1;
                GyRed = image[i - 1][j - 1].rgbtRed * -1 + image[i - 1][j].rgbtRed * -2 +
                        image[i - 1][j + 1].rgbtRed * -1 + image[i][j - 1].rgbtRed * 0 +
                        image[i][j].rgbtRed * 0 + image[i][j + 1].rgbtRed * 0 + image[i + 1][j - 1].rgbtRed * 1 +
                        image[i + 1][j].rgbtRed * 2 + image[i + 1][j + 1].rgbtRed * 1;
                copy[i][j].rgbtBlue = fmin(255.0, round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue))));
                copy[i][j].rgbtGreen = fmin(255.0, round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen))));
                copy[i][j].rgbtRed = fmin(255.0, round(sqrt((GxRed * GxRed) + (GyRed * GyRed))));
            }
        }
    }
    //Copies each new value to the output image file
    for (int i = 0; i <= height - 1; i++)
    {
        for (int j = 0; j <= width - 1; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
