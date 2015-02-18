// Name of Author(s): Derek Janzen 
// Course Number and Name: CSE 220, Programming for Computer Engineering 
// Semester: Fall 2014 // Lab Project Number: 3 
// Time Spent: 32 hours

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"neighbor.h"



bool updateNeighbors(car** cars) {

	int i = 0;
	for (i = 0; i<TOTAL_CARS; i++) {
		car* ci = cars[i];
		neighbors* ni = ci->ptr->next;
		while (ni != NULL) {
			neighbors* tmp = ni->next;
			free(ni);
			ni = tmp;
		}
		ci->ptr->next = NULL;
	}
	InitializeNeighbors(cars);
	return true;
}

bool isNeighbor(car* c, car* neigh) {

	int id = neigh->pid;
	neighbors* tmp = c->ptr;
	while (tmp != NULL) {
		if (tmp->pid == id)
			return true;

		tmp = tmp->next;
	}
	return false;
}


bool removeANeighbor(car*c, car* neigh) {

	int id = neigh->pid;
	neighbors* tmp = c->ptr;
	if (isNeighbor(c, neigh) == false)
	{
		printf("car %d does not have %d as neighbor\n", c->pid, id);
		return true;
	}

	while (tmp->next != NULL) {
		if (tmp->next->pid == id)
		{
			neighbors* t = tmp->next;
			tmp->next = t->next;
			free(t);
			return true;
		}
	}
	return true;
}


bool addANeighbor(car* c, car* neigh) {

	int id = neigh->pid;
	neighbors* tmp = c->ptr;
	if (isNeighbor(c, neigh) == true)
		return true;

	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

	neighbors* newNeigh = (neighbors*)malloc(sizeof(neighbors));
	newNeigh->pid = id;
	newNeigh->next = NULL;
	tmp->next = newNeigh;
	return true;
}


bool InitializeNeighbors(car** cars) {

	//we need to look for all the cars which are neighbors and add them
	int i = 0;
	int j = 0;
	for (i = 0; i<TOTAL_CARS; i++) {
		car* ci = cars[i];
		for (j = 0; j<TOTAL_CARS; j++) {
			if (i == j)
				continue;

			car* cj = cars[j];
			if (carDistance(ci, cj) <= 250)
				addANeighbor(ci, cj);
		}
	}
	return true;
}

