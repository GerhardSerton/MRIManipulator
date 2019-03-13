#include <iostream>
#include <string>
#include "volimage.h"

using namespace std;
int main(int argc, char* argv[])
{
  VolImage image;
  string header = argv[1];
  image.readImages(header);
  return 0;
}
