#include <iostream>
#include <string>
#include "volimage.h"

using namespace std;
int main(int argc, char* argv[])
{
  VolImage image;
  string header = argv[1];
  //string header = "brain_mri_raws/MRI";
  image.readImages(header);
  //cout << "Header: " << header << "\n";
  if (argc == 2)
  {
    image.volImageSize();
  }
  else
  {
    string command = argv[2];
    //cout << "Command: " << command << "\n";
    if (command == "-d")
    {
      int sliceI = strtol(argv[3], NULL, 10);
      int sliceJ = strtol(argv[4], NULL, 10);
      //cout << "-d numbers: " << sliceI << " " << sliceJ << "\n";
      string filename = argv[5];

      image.diffmap(sliceI, sliceJ, filename);
    }
    else if (command == "-x")
    {
      int chosenSlice = strtol(argv[3], NULL, 10);
      //cout << "-x numbers: " << chosenSlice << "\n";
      string filename = argv[4];
      image.extract(chosenSlice, filename);
    }
  }
    return 0;
}
