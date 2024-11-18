#include <iostream>
#include <cmath>
#include "Header.h"
using namespace std;

int NOD(int a, int b) {
	a = abs(a);
	b = abs(b);

	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

double Sokr(double a, double b) {
	int nod = NOD(int(a), int(b));
	a /= nod;
	b /= nod;

	if (b < 0) {
		a = -a;
		b = -b;
	}

	return a / b;
}

double Summ(double a, double b) {
	return  (a + b);
}

double Mult(double a, double b) {
	return (a * b);
}