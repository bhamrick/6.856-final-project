#include<sample.h>
#include<cmath>

point random_sample(int n, point p, bool (*inside)(const point), int niter) {
	
}

void random_unit_ball(point* p) {
	random_direction(p);
	real r = rand_one_sided();
	r = pow(r,p->n-1);
	(*p) *= r;
}
