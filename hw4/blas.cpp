/*
BLAS Level 1 function definitions
*/

#include <iostream>
#include <cmath>
#include "blas.h"

//using namespace std;

int amax(const double* x, const unsigned int len) {
    double max = 0;
	int maxIndex = 0;
	if (len == 0) {
		return -1;
	} else {
		for (unsigned int i = 0; i < len; ++i) {
			if (abs(x[i]) > max) {
				max = abs(x[i]);
				maxIndex = i;
			}
		}
		//cout << maxIndex;
	return maxIndex;
	}
}

double asum(const double* x, const unsigned int len) {
    double tempSum = 0;
	if (len == 0) {
		return 0;
	} else {
		for (unsigned int i = 0; i < len; ++i) {
			tempSum += abs(x[i]);
		}
		//cout << tempSum;
	return tempSum;
	}
}

void axpy(const double a, const double* x, double* y, const unsigned int len) {
	for (unsigned int i = 0; i < len; ++i) {
		y[i] = a * x[i] + y[i];
	}
}

void copy(const double* src, double* dest, const unsigned int len) {
    for (unsigned int i = 0; i < len; ++i) {
		dest[i] = src[i];
	}
}

double dot(const double* x, const double* y, const unsigned int len) {
    if (len == 0) {
		return 0;
	} else {
		double dotProduct = 0;
		for (unsigned int i = 0; i < len; ++i) {
			dotProduct += x[i] * y[i];
		}
	return dotProduct;
	}
}

double norm2(const double* x, const unsigned int len) {
	double magnitude = 0;
	double vectNorm = 0;
	if (len == 0) {
		return 0;
	} else {
		for (unsigned int i = 0; i < len; ++i) {
			magnitude += x[i] * x[i];
		}
		vectNorm = sqrt(magnitude);
	return vectNorm;
	}
}

void scale(const double a, double* x, const unsigned int len) {
    for (unsigned int i = 0; i < len; ++i) {
		x[i] *= a;
	}
}

void swap(double* x, double* y, const unsigned int len) {
	double tempVector[255];
	for (unsigned int i = 0; i < len; ++i) {
		tempVector[i] = x[i];
		x[i] = y[i];
		y[i] = tempVector[i];
	}
    
}