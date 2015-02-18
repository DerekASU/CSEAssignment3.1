// Name of Author(s): Derek Janzen 
// Course Number and Name: CSE 220, Programming for Computer Engineering 
// Semester: Fall 2014 // Lab Project Number: 3 
// Time Spent: 32 hours

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"car.h"


bool InitializeVehicles(char* inputFile) {

	FILE* fp = fopen(inputFile, "r");
	if (fp == NULL)
	{
		printf("Error opening input file\n");
		return false;
	}
	char line[100] = { '\0' };
	int idx = 0;
	while (fgets(line, 100, fp) != NULL) {
		car* newCar = (car*)malloc(sizeof(car));
		char* pch;

		pch = strtok(line, ",");
		sscanf(pch, "%f", &newCar->xloc);
		pch = strtok(NULL, ",");
		sscanf(pch, "%f", &newCar->yloc);
		pch = strtok(NULL, ",");
		sscanf(pch, "%f", &newCar->speed);
		pch = strtok(NULL, ",");
		sscanf(pch, "%f", &newCar->theta);
		carList[idx] = newCar;
		newCar->pid = idx;
		idx++;

		newCar->ptr = (neighbors*)malloc(sizeof(neighbors));
		newCar->ptr->pid = -1; // make first neighbor as dummy
		newCar->ptr->next = NULL;
	}
	TOTAL_CARS = idx;
	fclose(fp);
	return true;
}

bool updateLocations(car** cars) {

	int i = 0;
	for (i = 0; i<TOTAL_CARS; i++) {
		car* ci = cars[i];
		ci->xloc = ci->xloc + ((ci->speed)*(SLEEP_TIME)*cos((ci->theta)*(PI / 180.0)));
		ci->yloc = ci->yloc + ((ci->speed)*(SLEEP_TIME)*sin((ci->theta)*(PI / 180.0)));
	}
	return true;
}



float carDistance(car* one, car* two) {

	if (one->pid == two->pid)
		return 0;

	float dist = sqrt((pow((one->xloc - two->xloc), 2)) + (pow((one->yloc - two->yloc), 2)));
	return dist;
}

