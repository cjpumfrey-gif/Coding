#include "helpers.h"
#include <math.h>

//function prototype
int cap(int value);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all rows
    for (int i = 0; i < height; i++)
    {
        // Loop over all pixels in the row
        for (int j = 0; j < width; j++)
        {
            // Get original color values
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            // Calculate the average value
            // Use 3.0 to ensure floating-point division
            int average = round((red + green + blue) / 3.0);

            // Set all color channels to the average value
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all rows
    for (int i = 0; i < height; i++)
    {
        // Loop over all pixels in the row
        for (int j = 0; j < width; j++)
        {
            // Get original color values
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // Calculate new sepia values using the given formulas
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // Cap the values at 255 (the maximum for an 8-bit color)
            // We can use a helper function or just check inline
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
    return;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all rows
    for (int i = 0; i < height; i++)
    {
        // Loop over the first half of the pixels in the row
        // Integer division (width / 2) handles both even and odd widths correctly
        for (int j = 0; j < width / 2; j++)
        {
            // Find the pixel on the opposite side
            int opposite_j = width - 1 - j;

            // Use a temporary variable to swap the pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][opposite_j];
            image[i][opposite_j] = temp;
        }
    }
    return;
}

// Blur imasge
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary 2D array to store the original pixel values
    // We must base our calculations on the original, un-blurred image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Loop over all rows
    for (int i = 0; i < height; i++)
    {
        // Loop over all pixels in the row
        for (int j = 0; j < width; j++)
        {
            // Reset counters for each new 3x3 box
            float totalRed = 0;
            float totalGreen = 0;
            float totalBlue = 0;
            int pixelCount = 0;

            // Loop for the 3x3 box around the current pixel
            // (di = delta row, dj = delta column)
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    // Calculate the coordinates of the neighbor pixel
                    int neighbor_i = i + di;
                    int neighbor_j = j + dj;

                    // Check if the neighbor is within the image boundaries
                    if (neighbor_i >= 0 && neighbor_i < height &&
                        neighbor_j >= 0 && neighbor_j < width)
                    {
                        // Add the neighbor's original color to the total
                        totalRed += temp[neighbor_i][neighbor_j].rgbtRed;
                        totalGreen += temp[neighbor_i][neighbor_j].rgbtGreen;
                        totalBlue += temp[neighbor_i][neighbor_j].rgbtBlue;

                        // Count this valid pixel
                        pixelCount++;
                    }
                }
            }

            // Calculate the average color for the new pixel
            image[i][j].rgbtRed = round(totalRed / pixelCount);
            image[i][j].rgbtGreen = round(totalGreen / pixelCount);
            image[i][j].rgbtBlue = round(totalBlue / pixelCount);
        }
    }
    return;
}
