#Makefile
#Pieter Gerhard Serton
#05/04/19

CC=g++

driver: volimage.o driver.o
	$(CC) -o volimage driver.o volimage.o

volimage.o: volimage.cpp volimage.h
	$(CC) -c -o volimage.o volimage.cpp

driver.o: driver.cpp
	$(CC) -c -o driver.o driver.cpp


clean:
	@rm -f *.o

debug: volimage.o driver.o
	$(CC) -g driver.cpp volimage.cpp -o debug
