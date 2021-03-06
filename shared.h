#ifndef SHARED_H
#define SHARED_H

typedef double real;

struct point {
	int n;
	real* x;
	point & operator+=(point other);
	point & operator*=(real s);
	point & operator=(point other);
	point(int n);
};

void random_direction(point* p);

void move_along_line(point a, point dir, real s, point* result);

real rand_symmetric();
real rand_one_sided();

#endif
