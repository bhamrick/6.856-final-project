#ifndef SHARED_H
#define SHARED_H

typedef double real;

struct point {
	int n;
	real* x;
};

void random_direction(int n, point* p);

#endif
