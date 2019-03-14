Assignment 2: VolImage
Pieter Gerhard Serton

Currently, the application has 3 files:
driver.cpp: This file contains the main function, and is what is used to run the program. It instances a
            volimage object, and depending on the user's input calls some of it's functions.

volimage.cpp: This file defines the volimage class. This class builds a 3D array of unsigned chars, representing
              the submitted .raw files. Then, it can either:
              1)  Read out the number of files stored and the amount of memory
                  (including pointers) used by them.
              2)  Create a difference map from 2 files, and output it to another file.
              3)  Extract a single file from the array, and output it to another file.
volimage.h: Header file for volimage.cpp.
