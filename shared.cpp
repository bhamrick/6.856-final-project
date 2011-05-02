#include <cmath>
#include <cstdlib>
#include <cassert>
#include <shared.h>

void random_direction(int n, point *p) {
	p->n = n;
	p->x = new real[n];
	for(int i = 0; i < n; i += 2) {
		real x, y, s;
		do {
			x = (real)(rand() - RAND_MAX/2) / (real)(RAND_MAX/2);
			y = (real)(rand() - RAND_MAX/2) / (real)(RAND_MAX/2);
			s = x*x + y*y;
		} while(s >= (real)1.0);
		s = sqrt(-log(s) / s);
		p->x[i] = x * s;
		if(i + 1 < n)
			p->x[i+1] = y * s;
	}
}

point::point(int n) {
	this->n = n;
	this->x = new real[n];
}

point & point::operator+=(point other) {
	assert(this->n == b.n);
	for(int i = 0; i < n; i++)
		this->x[i] += other.x[i];
	return *this;
}

void move_along_line(point a, point dir, real s, point* result) {
	assert(a.n == b.n && a.n == result->n);
	for(int i = 0; i < n; i++)
		result->x[i] = a.x[i] + dir.x[i] * s;
}
