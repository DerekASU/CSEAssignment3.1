// Name of Author(s): Derek Janzen 
// Course Number and Name: CSE 220, Programming for Computer Engineering 
// Semester: Fall 2014 // Lab Project Number: 3 
// Time Spent: 32 hours

#ifndef __MAIN__H
#define __MAIN__H 

#include"neighbor.h"
#include"car.h"

bool VERBOSE = true;
char outfile[100];


void printAll(car** cars, char* outfile);
int lookup_args(int argc, char** argv, char* arg);

#endif
