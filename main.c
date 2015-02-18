// Name of Author(s): Derek Janzen 
// Course Number and Name: CSE 220, Programming for Computer Engineering 
// Semester: Fall 2014 // Lab Project Number: 3 
// Time Spent: 32 hours

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>
#include"main.h"

void printAll(car** cars, char* outfile) {

	int i = 0;
	FILE* ofp = fopen(outfile, "a");
	if (ofp == NULL) {
		printf("Error opening output file %s\n", outfile);
		return;
	}
	for (i = 0; i<TOTAL_CARS; i++) {
		car* ci = cars[i];
		if (VERBOSE == true) {
			printf("Vehicle %d ", ci->pid + 1);
			printf("at location %.2f, %.2f ", ci->xloc, ci->yloc);
			printf("moving with speed %.2f ", ci->speed);
			printf("its neighbors are: ");
			neighbors* n = ci->ptr->next;
			while (n != NULL) {
				printf("Vehicle %d, ", n->pid + 1);
				n = n->next;
			}
			printf("\n");
		}
		fprintf(ofp, "Vehicle %d ", ci->pid + 1);
		fprintf(ofp, "at location %.2f, %.2f ", ci->xloc, ci->yloc);
		fprintf(ofp, "moving with speed %.2f ", ci->speed);
		fprintf(ofp, "its neighbors are: ");
		neighbors* n = ci->ptr->next;
		while (n != NULL) {
			fprintf(ofp, "Vehicle %d, ", n->pid + 1);
			n = n->next;
		}
		fprintf(ofp, "\n");

	}
	fclose(ofp);
}

int lookup_args(int argc, char** argv, char* arg) {

	int i = 0;
	for (i = 0; i<argc; i++) {
		char* tmp = argv[i];
		if (strcmp(tmp, arg) == 0)
			return i + 1;
	}
	return -1;
}


int main(int argc, char* argv[]) {


	if (argc < 5 || argc > 8) {
		printf("Incorrect argument(s): Arguments allowed are -t seconds -f filename -o filename and -b/-s\n");
		return 0;
	}

	int t = lookup_args(argc, argv, "-t");
	if (t == -1)
	{
		printf("Error: Expecting argument -t\n");
		return 0;
	}

	sscanf(argv[t], "%d", &SLEEP_TIME);
	if (SLEEP_TIME < 0) {

		printf("Error: Expecting argument followig -t\n");
		return 0;
	}

	int f = lookup_args(argc, argv, "-f");
	if (f == -1)
	{
		printf("Error: Expecting argument -f\n");
		return 0;
	}
	if (f == argc) {

		printf("Error: Expecting argument followig -f\n");
		return 0;
	}

	char* infile = argv[f];

	int o = lookup_args(argc, argv, "-o");
	if (o == argc) {

		printf("Error: Expecting argument followig -f\n");
		return 0;
	}
	if (o != -1) {
		strcpy(outfile, argv[o]);
	}
	else
		strcpy(outfile, "result.txt");

	int b = lookup_args(argc, argv, "-b");
	int s = lookup_args(argc, argv, "-s");
	if (b != -1 && s != -1) {
		printf("Error: Expecting argument either -b OR -s\n");
		return 0;
	}
	if (s != -1) {
		VERBOSE = false;
	}

	InitializeVehicles(infile);
	InitializeNeighbors(&carList[0]);
	while (1) {
		printAll(&carList[0], outfile);
		updateLocations(&carList[0]);
		updateNeighbors(&carList[0]);

		sleep(SLEEP_TIME);
	}
	return 0;
}
