#include <iostream>
#include <string.h>

#include <stb_image.h>
#include <stb_image_write.h>
#include <Eigen/Dense>

#include "Ray.h"

using namespace Eigen;

Vector3d ray_color(const Ray& ray)
{
    Vector3d unitDirection = ray.direction().normalized();
    double t = 0.5 * (unitDirection.y() + 1.0);
    return (1.0-t)*Vector3d(1.0, 1.0, 1.0) + t * Vector3d(0.5, 0.7, 1.0);
}

int main()
{
    // Image parameter.
    const double imageAspectRatio = 16.0/9.0;
    const int imageWidth = 400;
    const int imageHeight = static_cast<int>(imageWidth/imageAspectRatio);
    const int CHANNEL_NUM = 3;
    std::string imagePath;

    // Image path and data buffer.
    std::cout << "Please input the output image path." << std::endl;
    std::cin >> imagePath;
    std::cout << "output path is: " << imagePath << std::endl;
    const char* outputPath = imagePath.c_str();
    char* outputData = new char[imageWidth * imageHeight * CHANNEL_NUM];

    // Camera parameter.
    double viewportHeight = 2.0;
    double viewportWidth = imageAspectRatio * viewportHeight;
    double focalLength = 1.0;

    Vector3d origin(0, 0, 0);
    Vector3d horizontal(viewportWidth, 0, 0);
    Vector3d vertical(0, viewportHeight, 0);
    Vector3d lowerLeftCorner = origin - horizontal/2 -  vertical/2 - Vector3d(0, 0, focalLength);

    int index = 0;
    for(int j = imageHeight - 1; j >= 0; j--)
    {
        for(int i=0; i<imageWidth; i++)
        {
            double r = double(i) / (imageWidth - 1);
            double g = double(j) / (imageHeight - 1);
            double b = 0.25;

            outputData[index++] = static_cast<int>(255.999*r);
            outputData[index++] = static_cast<int>(255.999*g);
            outputData[index++] = static_cast<int>(255.999*b);
        }
    }

    Vector3f v;

    stbi_write_png(outputPath, imageWidth, imageHeight, 3, static_cast<void*>(outputData), CHANNEL_NUM*imageWidth);

    return 0;
}