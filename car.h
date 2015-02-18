// Name of Author(s): Derek Janzen 
// Course Number and Name: CSE 220, Programming for Computer Engineering 
// Semester: Fall 2014 // Lab Project Number: 3 
// Time Spent: 32 hours

#ifndef __CAR_H
#define __CAR_H

typedef struct LLIST {
	int pid;
	struct LLIST* next;
} neighbors;

typedef struct car_t {
	int pid;
	float xloc;
	float yloc;
	float speed;
	float theta;
	neighbors* ptr;
} car;


int SLEEP_TIME;
#define PI 3.14159265
car* carList[100];
int TOTAL_CARS;

bool InitializeVehicles(char* inputFile);
bool updateLocations(car** cars);
float carDistance(car* one, car* two);


#endif
