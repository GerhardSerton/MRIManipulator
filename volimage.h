#ifndef VOLIMAGE_H
#define VOLIMAGE_H

#include <vector>
#include <string>
class VolImage
{
private:

  int width, height, bytesize, imageno;
  std::string prefix;
  std::vector<unsigned char**> slices;

public:

  VolImage();
  ~VolImage();

  bool readImages(std::string baseName);

  void diffmap(int sliceI, int sliceJ, std::string output_prefix);

  void extract(int sliceId, std::string output_prefix);

  int volImageSize(void);

  void readHeader(void);

  void initializeSlices(void);

};

#endif
