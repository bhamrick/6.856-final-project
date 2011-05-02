#include<sample.h>
#include<cmath>

void random_unit_ball(point*);

point random_sample(point p, bool (*inside)(const point), int niter) {
	point cur_point(p.n), next_point(p.n), delta(p.n);
	cur_point = p;
	real eps = 0.1;
	for(int iter = 0; iter < niter; iter++) {
		next_point = cur_point;
		random_unit_ball(&delta);
		delta *= eps;
		next_point += delta;
		if(inside(next_point)) {
			cur_point = next_point;
		}
	}
	return cur_point;
}

void random_unit_ball(point* p) {
	random_direction(p);
	real r = rand_one_sided();
	r = pow(r,p->n-1);
	(*p) *= r;
}
