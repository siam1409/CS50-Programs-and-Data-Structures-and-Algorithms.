#include <math.h>
#include <stdio.h>
#include "helpers.h"

// Creat a struct of ints to store the channel values
typedef struct
{
    int rgbtBlue;
    int rgbtGreen;
    int rgbtRed;
}
RGBTRIPLEINT;

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average = 0, tmp[3] = {0, 0, 0};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the average value of all the colors in each pixel
            tmp[0] = image[i][j].rgbtBlue;
            tmp[1] = image[i][j].rgbtGreen;
            tmp[2] = image[i][j].rgbtRed;

            average = (int)round((tmp[0] + tmp[1] + tmp[2]) / 3);

            // Rewrite the values of each pixel with the average color
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary array to store the revesve values of the pixels
    RGBTRIPLE imagesample[height][width];

    // Write all the pixels in a temporary array (2D) in reverse order
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imagesample[i][width - (j + 1)].rgbtBlue = image[i][j].rgbtBlue;
            imagesample[i][width - (j + 1)].rgbtGreen = image[i][j].rgbtGreen;
            imagesample[i][width - (j + 1)].rgbtRed = image[i][j].rgbtRed;
        }
    }

    // Rewrite all the pixels to the orginal array (2D) from the temporary array which is in the reversed order (horizontally)

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = imagesample[i][j].rgbtBlue;
            image[i][j].rgbtGreen = imagesample[i][j].rgbtGreen;
            image[i][j].rgbtRed = imagesample[i][j].rgbtRed;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // creat a temporary array to store the new value of each pixel
    RGBTRIPLE imagesample[height][width];

    // Create a struct variable to store the average value of each color BYTE
    RGBTRIPLE average;
    average.rgbtBlue = 0;
    average.rgbtGreen = 0;
    average.rgbtRed = 0;

    // Create a struct array to store all the color information of each pixel
    RGBTRIPLE color[9];

    int color_count = 0;

    // Create float type variables to store the sum of each byte of each pixel
    float sumBlue = 0, sumGreen = 0, sumRed = 0;

    // Write new vaules to the temporary array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize color array on every iteration to make sure the absence of garbage values
            for (int l = 0; l < 9; l++)
            {
                color[l].rgbtBlue = 0;
                color[l].rgbtGreen = 0;
                color[l].rgbtRed = 0;
            }

            int row = i, column = j;

            // Read the adjacent pixels of the current row
            color[color_count].rgbtBlue = image[i][j].rgbtBlue;
            color[color_count].rgbtGreen = image[i][j].rgbtGreen;
            color[color_count].rgbtRed = image[i][j].rgbtRed;
            color_count++;

            column = j + 1;
            if (column < width)
            {
                color[color_count].rgbtBlue = image[i][column].rgbtBlue;
                color[color_count].rgbtGreen = image[i][column].rgbtGreen;
                color[color_count].rgbtRed = image[i][column].rgbtRed;
                color_count++;
            }
            column = j - 1;

            if (column > -1)
            {
                color[color_count].rgbtBlue = image[i][column].rgbtBlue;
                color[color_count].rgbtGreen = image[i][column].rgbtGreen;
                color[color_count].rgbtRed = image[i][column].rgbtRed;;
                color_count++;
            }
            column = j;



            // Read the adjacent pixels of the next row
            row = i + 1;
            if (row < height)
            {
                color[color_count].rgbtBlue = image[row][j].rgbtBlue;
                color[color_count].rgbtGreen = image[row][j].rgbtGreen;
                color[color_count].rgbtRed = image[row][j].rgbtRed;
                color_count++;

                column = j + 1;
                if (column < width)
                {
                    color[color_count].rgbtBlue = image[row][column].rgbtBlue;
                    color[color_count].rgbtGreen = image[row][column].rgbtGreen;
                    color[color_count].rgbtRed = image[row][column].rgbtRed;
                    color_count++;
                }
                column = j - 1;

                if (column > -1)
                {
                    color[color_count].rgbtBlue = image[row][column].rgbtBlue;
                    color[color_count].rgbtGreen = image[row][column].rgbtGreen;
                    color[color_count].rgbtRed = image[row][column].rgbtRed;
                    color_count++;
                }
            }
            column = j;
            row = i;



            // Read the the adjacent pixels of the previous row
            row = i - 1;
            if (row > -1)
            {
                color[color_count].rgbtBlue = image[row][j].rgbtBlue;
                color[color_count].rgbtGreen = image[row][j].rgbtGreen;
                color[color_count].rgbtRed = image[row][j].rgbtRed;
                color_count++;

                column = j + 1;
                if (column < width)
                {
                    color[color_count].rgbtBlue = image[row][column].rgbtBlue;
                    color[color_count].rgbtGreen = image[row][column].rgbtGreen;
                    color[color_count].rgbtRed = image[row][column].rgbtRed;
                    color_count++;
                }
                column = j - 1;

                if (column > -1)
                {
                    color[color_count].rgbtBlue = image[row][column].rgbtBlue;
                    color[color_count].rgbtGreen = image[row][column].rgbtGreen;
                    color[color_count].rgbtRed = image[row][column].rgbtRed;
                    color_count++;
                }
            }


            // Calculate the new values to put in the temporary array
            for (int k = 0; k < 9; k++)
            {
                sumBlue = sumBlue + color[k].rgbtBlue;
                sumGreen = sumGreen + color[k].rgbtGreen;
                sumRed = sumRed + color[k].rgbtRed;
            }

            // Calculate the average of all the channel values
            average.rgbtBlue = round(sumBlue / color_count);
            average.rgbtGreen = round(sumGreen / color_count);
            average.rgbtRed = round(sumRed / color_count);

            // Write new values to the temporary array
            imagesample[i][j].rgbtBlue = average.rgbtBlue;
            imagesample[i][j].rgbtGreen = average.rgbtGreen;
            imagesample[i][j].rgbtRed = average.rgbtRed;

            // Initialize all the varaible to zero
            average.rgbtBlue = 0;
            average.rgbtGreen = 0;
            average.rgbtRed = 0;

            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;

            color_count = 0;

        }
    }

    // Rewrite the values of the orginal array from the temporary array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = imagesample[i][j].rgbtBlue;
            image[i][j].rgbtGreen = imagesample[i][j].rgbtGreen;
            image[i][j].rgbtRed = imagesample[i][j].rgbtRed;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // creat a temporary array to store the new value of each pixel
    RGBTRIPLE imagesample[height][width];

    // Create a struct array to store all the color information of each pixel
    RGBTRIPLEINT color[9];

    int color_count = 0;

    RGBTRIPLEINT G, Gx, Gy;

    // Iterate over all the pixels of the image and detect the edges
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize color array on every iteration to make sure the absence of garbage values
            for (int l = 0; l < 9; l++)
            {
                color[l].rgbtBlue = 0;
                color[l].rgbtGreen = 0;
                color[l].rgbtRed = 0;
            }

            // Initialize all the variables to clear previous data
            color_count = 0;

            G.rgbtBlue = 0;
            G.rgbtGreen = 0;
            G.rgbtRed = 0;

            Gx.rgbtBlue = 0;
            Gx.rgbtGreen = 0;
            Gx.rgbtRed = 0;

            Gy.rgbtBlue = 0;
            Gy.rgbtGreen = 0;
            Gy.rgbtRed = 0;

            // Create a multiplier variable
            int multiplier = 0;

            int row = i, column = j;

            /*
                Gx CALCULATIONS ******************************************
            */

            // Read the adjacent pixels of the current row. The values which are supposed to be multiplied by zero are avoided

            column = j + 1;
            if (column < width)
            {
                multiplier = 2;
                color[color_count].rgbtBlue = image[i][column].rgbtBlue * multiplier;
                color[color_count].rgbtGreen = image[i][column].rgbtGreen * multiplier;
                color[color_count].rgbtRed = image[i][column].rgbtRed * multiplier;
                color_count++;

            }
            column = j - 1;

            if (column > -1)
            {
                multiplier = -2;
                color[color_count].rgbtBlue = image[i][column].rgbtBlue * multiplier;
                color[color_count].rgbtGreen = image[i][column].rgbtGreen * multiplier;
                color[color_count].rgbtRed = image[i][column].rgbtRed * multiplier;
                color_count++;
            }
            column = j;



            // Read the adjacent pixels of the next row
            row = i + 1;
            if (row < height)
            {
                column = j + 1;
                if (column < width)
                {
                    color[color_count].rgbtBlue = image[row][column].rgbtBlue;
                    color[color_count].rgbtGreen = image[row][column].rgbtGreen;
                    color[color_count].rgbtRed = image[row][column].rgbtRed;
                    color_count++;
                }
                column = j - 1;

                if (column > -1)
                {
                    multiplier = -1;
                    color[color_count].rgbtBlue = image[row][column].rgbtBlue * multiplier;
                    color[color_count].rgbtGreen = image[row][column].rgbtGreen * multiplier;
                    color[color_count].rgbtRed = image[row][column].rgbtRed * multiplier;
                    color_count++;
                }
            }
            column = j;
            row = i;



            // Read the adjacent pixels of the previous row
            row = i - 1;
            if (row > -1)
            {
                column = j + 1;
                if (column < width)
                {
                    color[color_count].rgbtBlue = image[row][column].rgbtBlue;
                    color[color_count].rgbtGreen = image[row][column].rgbtGreen;
                    color[color_count].rgbtRed = image[row][column].rgbtRed;
                    color_count++;
                }
                column = j - 1;

                if (column > -1)
                {
                    multiplier = -1;
                    color[color_count].rgbtBlue = image[row][column].rgbtBlue * multiplier;
                    color[color_count].rgbtGreen = image[row][column].rgbtGreen * multiplier;
                    color[color_count].rgbtRed = image[row][column].rgbtRed * multiplier;
                    color_count++;
                }
            }

            // Calculate the new values to put in the temporary array
            for (int k = 0; k < 9; k++)
            {
                Gx.rgbtBlue += color[k].rgbtBlue;
                Gx.rgbtGreen += color[k].rgbtGreen;
                Gx.rgbtRed += color[k].rgbtRed;
            }



            /*

                Gy CALCULATIONS ******************************************

            */

            // Initialize the color array and the variables for the Gy calculations
            for (int l = 0; l < 9; l++)
            {
                color[l].rgbtBlue = 0;
                color[l].rgbtGreen = 0;
                color[l].rgbtRed = 0;
            }

            color_count = 0;

            multiplier = 0;

            // Read the adjacent pixels of the current row. All will be multiplied by zero, so don't need to take those

            column = j;



            // Read the adjacent pixels of the next row
            row = i + 1;
            if (row < height)
            {
                multiplier = 2;
                color[color_count].rgbtBlue = image[row][j].rgbtBlue * multiplier;
                color[color_count].rgbtGreen = image[row][j].rgbtGreen * multiplier;
                color[color_count].rgbtRed = image[row][j].rgbtRed * multiplier;
                color_count++;


                column = j + 1;
                if (column < width)
                {
                    color[color_count].rgbtBlue = image[row][column].rgbtBlue;
                    color[color_count].rgbtGreen = image[row][column].rgbtGreen;
                    color[color_count].rgbtRed = image[row][column].rgbtRed;
                    color_count++;
                }
                column = j - 1;

                if (column > -1)
                {
                    color[color_count].rgbtBlue = image[row][column].rgbtBlue;
                    color[color_count].rgbtGreen = image[row][column].rgbtGreen;
                    color[color_count].rgbtRed = image[row][column].rgbtRed;
                    color_count++;
                }
            }
            column = j;
            row = i;



            // Read the adjacent pixels of the previous row
            row = i - 1;
            if (row > -1)
            {
                multiplier = -2;
                color[color_count].rgbtBlue = image[row][j].rgbtBlue * multiplier;
                color[color_count].rgbtGreen = image[row][j].rgbtGreen * multiplier;
                color[color_count].rgbtRed = image[row][j].rgbtRed * multiplier;
                color_count++;


                column = j + 1;
                if (column < width)
                {
                    multiplier = -1;
                    color[color_count].rgbtBlue = image[row][column].rgbtBlue * multiplier;
                    color[color_count].rgbtGreen = image[row][column].rgbtGreen * multiplier;
                    color[color_count].rgbtRed = image[row][column].rgbtRed * multiplier;
                    color_count++;
                }
                column = j - 1;

                if (column > -1)
                {
                    multiplier = -1;
                    color[color_count].rgbtBlue = image[row][column].rgbtBlue * multiplier;
                    color[color_count].rgbtGreen = image[row][column].rgbtGreen * multiplier;
                    color[color_count].rgbtRed = image[row][column].rgbtRed * multiplier;
                    color_count++;
                }
            }

            // Calculate the new values to put in the temporary array
            for (int k = 0; k < 9; k++)
            {
                Gy.rgbtBlue += color[k].rgbtBlue;
                Gy.rgbtGreen += color[k].rgbtGreen;
                Gy.rgbtRed += color[k].rgbtRed;
            }



            /*
                G CALCULATION ******************************************
            */

            // Calculate the values of G for each channel
            G.rgbtBlue = round(sqrt(pow(Gx.rgbtBlue, 2) + pow(Gy.rgbtBlue, 2)));
            G.rgbtGreen = round(sqrt(pow(Gx.rgbtGreen, 2) + pow(Gy.rgbtGreen, 2)));
            G.rgbtRed = round(sqrt(pow(Gx.rgbtRed, 2) + pow(Gy.rgbtRed, 2)));

            // If channel value of G is past the boundary of channel value then cap it inside 255
            if (G.rgbtBlue > 255)
            {
                G.rgbtBlue = 255;
            }
            if (G.rgbtGreen > 255)
            {
                G.rgbtGreen = 255;
            }
            if (G.rgbtRed > 255)
            {
                G.rgbtRed = 255;
            }

            // Write the new G values to the sample array
            imagesample[i][j].rgbtBlue = G.rgbtBlue;
            imagesample[i][j].rgbtGreen = G.rgbtGreen;
            imagesample[i][j].rgbtRed = G.rgbtRed;
        }
    }


    // Write all the new values from the sample array to the orginal image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = imagesample[i][j].rgbtBlue;
            image[i][j].rgbtGreen = imagesample[i][j].rgbtGreen;
            image[i][j].rgbtRed = imagesample[i][j].rgbtRed;
        }
    }

    return;
}
