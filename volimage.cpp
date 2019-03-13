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
{
  for (int i = 0; i < imageno; i++)
  {
    for (int j = 0; j < height; j++)
    {
      delete [] slices[i][j];
    }
    delete [] slices[i];
  }
}

bool VolImage::readImages(std::string baseName)
{
  prefix = baseName;
  readHeader();
  initializeSlices();
  //slices[428][302][122] = (unsigned char)48;
  //std::cout << (int)slices[428][302][122];
  for (int i = 0; i < imageno; i++)
  {
      std::ifstream filein;
      std::string currentimage = prefix + std::to_string(i) + ".raw";
      filein.open(currentimage, std::ios::in | std::ios::binary);
      for (int j = 0; j < height; j++)
      {
        filein.read((char*)slices[i][j], width);
      }
      filein.close();
  }

  return false;
}

void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix)
{
  unsigned char output [height][width];
  for (int i = 0; i < height; i ++)
  {
    for (int j = 0; j < width; j++)
    {
      output[i][j] = (unsigned char)(abs((float)slices[sliceI][i][j] - (float)slices[sliceJ][i][j])/2);
    }
  }

  std::ofstream fileout;
  fileout.open(output_prefix + ".raw", std::ios::out | std::ios::binary);
  for (int i = 0; i < height; i++)
  {
    fileout.write((char*)output[i], width);
  }
  fileout.close();
}

void VolImage::extract(int sliceId, std::string output_prefix)
{
  unsigned char output [height][width];
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      output[i][j] = slices[sliceId][i][j];
    }
  }

  std::ofstream fileout;
  fileout.open(output_prefix + ".raw", std::ios::out | std::ios::binary);
  for (int i = 0; i < height; i++)
  {
    fileout.write((char*)output[i], width);
  }
  fileout.close();
}
//8 bytes per pointer
int VolImage::volImageSize(void)
{
  int pointermemory = 8 * height * imageno;
  int charmemory = width * height * imageno;
  int total = pointermemory + charmemory;
  std::cout << "Number of images: " << imageno << "\n";
  std::cout << "Number of bytes required: " << total << "\n";
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
    for (int i = 0; i < imageno; i ++)
    {
        unsigned char ** b = new unsigned char * [height];
        for (int j = 0; j < height; j++)
        {
            unsigned char * c = new unsigned char [width];
            b[j] = c;
        }
        slices.push_back(b);
    }

}
