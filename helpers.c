#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // cycle through each pixel in image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // for each pixel, take average of red, green and blue values
            float grey = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;

            // set average as new rgb value (grey)
            image[i][j].rgbtRed = round(grey);
            image[i][j].rgbtGreen = round(grey);
            image[i][j].rgbtBlue = round(grey);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // cycle through each pixel in image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            // temp = left pixel
            RGBTRIPLE temp = image[i][j];

            // left pixel = right pixel
            image[i][j] = image[i][width - 1 - j];

            // right pixel = temp
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create a copy of the image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // apply blur to pixels
    // cycle through pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int counter = 0;
            float sumRed, sumGreen, sumBlue;
            sumRed = sumGreen = sumBlue = 0;

            // calculate average of surrounding pixels from copy
            for (int l = -1; l < 2; l++)
            {
                for (int m = -1; m < 2; m++)
                {
                    // handle edges
                    if (i + l < 0 || i + l > height - 1)
                    {
                        continue;
                    }

                    if (j + m < 0 || j + m > width - 1)
                    {
                        continue;
                    }

                    // calculate averages
                    sumRed += copy[i + l][j + m].rgbtRed;
                    sumGreen += copy[i + l][j + m].rgbtGreen;
                    sumBlue += copy[i + l][j + m].rgbtBlue;
                    counter++;
                }
            }

            // apply average to image pixels
            image[i][j].rgbtRed = round(sumRed / counter);
            image[i][j].rgbtGreen = round(sumGreen / counter);
            image[i][j].rgbtBlue = round(sumBlue / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // create a copy of the image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    // store kernels as 2D arrays
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // detect edges
    // cycle through pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int GxRed = 0;
            int GyRed = 0;
            int GxGreen = 0;
            int GyGreen = 0;
            int GxBlue = 0;
            int GyBlue = 0;

            // calculate average of surrounding pixels from copy
            for (int l = -1; l < 2; l++)
            {
                for (int m = -1; m < 2; m++)
                {
                    // handle edges
                    if (i + l < 0 || i + l > height - 1)
                    {
                        continue;
                    }
                    if (j + m < 0 || j + m > width - 1)
                    {
                        continue;
                    }

                    GxRed += copy[i + l][j + m].rgbtRed * Gx[l + 1][m + 1];
                    GyRed += copy[i + l][j + m].rgbtRed * Gy[l + 1][m + 1];

                    GxGreen += copy[i + l][j + m].rgbtGreen * Gx[l + 1][m + 1];
                    GyGreen += copy[i + l][j + m].rgbtGreen * Gy[l + 1][m + 1];

                    GxBlue += copy[i + l][j + m].rgbtBlue * Gx[l + 1][m + 1];
                    GyBlue += copy[i + l][j + m].rgbtBlue * Gy[l + 1][m + 1];
                }
            }

            // calculate Solbel value
            int sumRed = round(sqrt((GxRed * GxRed) + (GyRed * GyRed)));
            int sumGreen = round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen)));
            int sumBlue = round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue)));

            // cap at 255
            if (sumRed > 255)
            {
                sumRed = 255;
            }

            if (sumGreen > 255)
            {
                sumGreen = 255;
            }

            if (sumBlue > 255)
            {
                sumBlue = 255;
            }

            // apply average to image pixels
            image[i][j].rgbtRed = sumRed;
            image[i][j].rgbtGreen = sumGreen;
            image[i][j].rgbtBlue = sumBlue;
        }
    }

    return;
}
