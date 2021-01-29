#include <iostream>
#include <string.h>

#include <stb_image.h>
#include <stb_image_write.h>

int main()
{
    // Image parameter.
    const int image_width = 256;
    const int image_height = 256;
    const int CHANNEL_NUM = 3;
    std::string imagePath;

    std::cout << "Please input the output image path." << std::endl;
    std::cin >> imagePath;
    std::cout << "output path is: " << imagePath << std::endl;

    const char* outputPath = imagePath.c_str();

    char* outputData = new char[image_width * image_height * CHANNEL_NUM];

    int index = 0;
    for(int i = 0; i< image_height; i++)
    {
        for(int j=0; j<image_width; j++)
        {
            double r = double(i) / (image_width - 1);
            double g = double(j) / (image_height - 1);
            double b = 0.25;

            outputData[index++] = static_cast<int>(255.999*r);
            outputData[index++] = static_cast<int>(255.999*g);
            outputData[index++] = static_cast<int>(255.999*b);
        }
    }

    stbi_write_png(outputPath, image_width, image_height, 3, static_cast<void*>(outputData), CHANNEL_NUM*image_width);

    return 0;
}