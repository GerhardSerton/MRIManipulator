#include "volimage.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

VolImage::VolImage()
{
  width = 0;
  height = 0;
  bytesize = 0;
  imageno = 0;
  prefix = "";

}

VolImage::~VolImage()
{}

bool VolImage::readImages(std::string baseName)
{
  prefix = baseName;
  readHeader();
  initializeSlices();
  std::cout << (int)slices[1][1][1];

  return false;
}

void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix)
{}

void VolImage::extract(int sliceId, std::string output_prefix)
{}
//8 bytes per pointer
int VolImage::volImageSize(void)
{
  int pointermemory = 8 * height * imageno;
  int charmemory = width * height * imageno;
  return pointermemory + charmemory;
}

void VolImage::readHeader(void)
{
  std::ifstream inFile;
  std::string headerfile = prefix + ".data";
  inFile.open(headerfile);
  if (!inFile)
  {
    std::cout << "VOLCLASS ERROR: Unable to open header file\n";
    exit(1);
  }
  inFile >> width;
  inFile >> height;
  inFile >> imageno;
  std::cout << "Width, Height, Imageno: " << width << " " << height << " " << imageno << "\n";
}

void VolImage::initializeSlices(void)
{
    for (int i = 0; i < 10; i ++)
    {
        unsigned char ** b = new unsigned char * [height];
        for (int j = 0; j < 10; j++)
        {
            unsigned char * c = new unsigned char [width];
            b[j] = c;
        }
        slices.push_back(b);
    }
    slices[1][1][1] = (unsigned char)28;

}
