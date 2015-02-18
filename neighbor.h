// Name of Author(s): Derek Janzen 
// Course Number and Name: CSE 220, Programming for Computer Engineering 
// Semester: Fall 2014 // Lab Project Number: 3 
// Time Spent: 32 hours

#ifndef __NEIGH_H_
#define __NEIGH_H_

#include"car.h"

bool updateNeighbors(car** cars);
bool isNeighbor(car* c, car* neigh);
bool removeANeighbor(car*c, car* neigh);
bool addANeighbor(car* c, car* neigh);
bool InitializeNeighbors(car** cars);

#endif
