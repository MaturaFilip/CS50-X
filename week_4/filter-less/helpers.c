#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < (height); i++)
    {
        for (int j = 0; j < (width); j++)
        {
            int rounded_avg = (int) round(((float) (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)) / 3.0);
            image[i][j].rgbtRed = rounded_avg;
            image[i][j].rgbtBlue = rounded_avg;
            image[i][j].rgbtGreen = rounded_avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < (height); i++)
    {
        for (int j = 0; j < (width); j++)
        {
            int sepiaRed = (int) round((image[i][j].rgbtRed * 0.393 + image[i][j].rgbtBlue * 0.189 + image[i][j].rgbtGreen * 0.769));
            int sepiaGreen = (int) round((image[i][j].rgbtRed * 0.349 + image[i][j].rgbtBlue * 0.168 + image[i][j].rgbtGreen * 0.686));
            int sepiaBlue = (int) round((image[i][j].rgbtRed * 0.272 + image[i][j].rgbtBlue * 0.131 + image[i][j].rgbtGreen * 0.534));

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // need length of row and create tmp
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int tmp_red = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width-1-j].rgbtRed;
            image[i][width-1-j].rgbtRed = tmp_red;

            int tmp_blue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width-1-j].rgbtBlue;
            image[i][width-1-j].rgbtBlue = tmp_blue;

            int tmp_green = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width-1-j].rgbtGreen;
            image[i][width-1-j].rgbtGreen = tmp_green;



        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // change picture to plur (calculate pixels from copy!)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int divide_by = 0;
            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;

            // 3x3
            // check surounding cells 3x3 + itself
            for (int x = i - 1; x < (i + 2); x++)
            {
                for (int y = j - 1; y < (j + 2); y++)
                {
                    if (x < 0 || x > height -1)
                    {
                        continue;
                    }
                    else if (y < 0 || y > width -1)
                    {
                        continue;
                    }
                    else
                    {
                        sum_red += copy[x][y].rgbtRed;
                        sum_green += copy[x][y].rgbtGreen;
                        sum_blue += copy[x][y].rgbtBlue;
                        divide_by += 1;
                    }
                }
            }
            image[i][j].rgbtRed = round(sum_red / (float) divide_by);
            image[i][j].rgbtGreen = round(sum_green / (float) divide_by);
            image[i][j].rgbtBlue = round(sum_blue / (float) divide_by);
        }
    }
    return;
}
