#ifndef _CIRCUIT_H
#define _CIRCUIT_H

#include "vector.h"
#include "matrix.h"

/* Data Structures */

typedef enum {
	resistor,
	voltage,
	current
} CompType;

typedef struct {
	char name[10];
	CompType type; 
	unsigned int n1;
	unsigned int n2;
	double value;
} Component;

typedef struct {
	unsigned int nN;
	unsigned int nC;
	unsigned int nR;
	unsigned int nI;
	unsigned int nV;
	Component *comp;
} Circuit;

/* Interfaces */

Circuit createCircuitFromFile(const char *filename);
void destroyCircuit(Circuit c);
void analyseCircuit(const Circuit c);
Vector solveLinearSystem(Matrix A, Vector b);

#endif
