#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copygray[height][width];
    float g = 0;
    int average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //putting a copy (only way it will work)
            copygray[i][j] = image[i][j];
            //getting the average of the three colours
            g = copygray[i][j].rgbtRed + copygray[i][j].rgbtGreen + copygray[i][j].rgbtBlue;
            g = g / 3;
            average = round(g);
            //making RGB the same
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed = 0;
    float sepiaBlue = 0;
    float sepiaGreen = 0;
    //making sure they are all set to zero at beginning
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //formula for sepia
            sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
            //ROUND THE NUMBERS
            sepiaRed = round(sepiaRed);
            sepiaBlue = round(sepiaBlue);
            sepiaGreen = round(sepiaGreen);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            //if they excede the max,they are capped
            //making the image, they same colour as what the formula said
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
    //finding middle
    float middle = width / 2;
    int tmp[3];
    //having temporary array of three for the three colours of each pixel
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < middle; j++)
        {
            //assigning original to the temp (these are the ones before halfway)
            tmp[0] = image[i][j].rgbtRed;
            tmp[1] = image[i][j].rgbtBlue;
            tmp[2] = image[i][j].rgbtGreen;
            //the ones originals are assigned to teh ones that come after the middle
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            //now the ones that come after the middle are given the value of the originals (successfully swapped)
            image[i][width - 1 - j].rgbtRed = tmp[0];
            image[i][width - 1 - j].rgbtBlue = tmp[1];
            image[i][width - 1 - j].rgbtGreen = tmp[2];

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    //need a copy one
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            //making sure to set these values to zero each time
            float ave_red = 0;
            float ave_blue = 0;
            float ave_green = 0;
            float num = 0.00;
            copy[h][w] = image[h][w];
            for (int i = -1; i < 2; i++)
            {
                if (h + i < 0 || h + i > height - 1)
                {
                    continue;
                    //you dont want the ones that are exceeding the limits of the image
                }
                for (int j = -1; j < 2; j++)
                {
                    if (w + j < 0 || w + j > width - 1)
                    {
                        continue;
                    }
                    num++;
                    ave_red += image[h + i][w + j].rgbtRed;
                    ave_blue += image[h + i][w + j].rgbtBlue;
                    ave_green += image[h + i][w + j].rgbtGreen;
                    //getting the sum that will be used in the mean
                }
            }
            copy[h][w].rgbtRed = round(ave_red / num);
            copy[h][w].rgbtGreen = round(ave_green / num);
            copy[h][w].rgbtBlue = round(ave_blue / num);
            //now the mean is calculated and rounded 
            //it is assigned to a copy because you cannot calculated it with the original
        }
    }
    for (int n = 0; n < height; n++)
    {
        for (int x = 0; x < width; x++)
        {
            image[n][x].rgbtRed = copy[n][x].rgbtRed;
            image[n][x].rgbtBlue = copy[n][x].rgbtBlue;
            image[n][x].rgbtGreen = copy[n][x].rgbtGreen;
            //the copies are all assigned to the actual pixels in the image
        }
    }
    return;
}

