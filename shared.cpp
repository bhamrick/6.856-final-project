#include <cmath>
#include <cstdlib>
#include <cassert>
#include <shared.h>

void random_direction(point *p) {
	for(int i = 0; i < p->n; i += 2) {
		real x, y, s;
		do {
			x = rand_symmetric();
			y = rand_symmetric(); 
			s = x*x + y*y;
		} while(s >= (real)1.0);
		s = sqrt(-log(s) / s);
		p->x[i] = x * s;
		if(i + 1 < p->n)
			p->x[i+1] = y * s;
	}
}

real rand_symmetric() {
	return (real)(rand() - RAND_MAX/2)/(real)(RAND_MAX/2);
}

real rand_one_sided() {
	return (real)rand()/(real)RAND_MAX;
}

point::point(int n) {
	this->n = n;
	this->x = new real[n];
}

point & point::operator+=(point other) {
	assert(this->n == other.n);
	for(int i = 0; i < n; i++)
		this->x[i] += other.x[i];
	return *this;
}

point & point::operator*=(real s) {
	for(int i = 0; i<n; i++) {
		this->x[i] *= s;
	}
	return *this;
}

point & point::operator=(point other) {
	assert(this->n == other.n);
	for(int i = 0; i < n; i++) {
		this->x[i] = other.x[i];
	}
	return *this;
}

void move_along_line(point a, point dir, real s, point* result) {
	assert(a.n == dir.n && a.n == result->n);
	for(int i = 0; i < a.n; i++)
		result->x[i] = a.x[i] + dir.x[i] * s;
}
