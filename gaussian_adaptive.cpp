#include<sample.h>
#include<cmath>

void random_unit_ball(point*);

point random_sample(point p, bool (*inside)(const point), int niter) {
	point cur_point(p.n), next_point(p.n), delta(p.n);
	cur_point = p;
	real eps = 0.1;
	for(int iter = 0; iter < niter/2; iter++) {
		next_point = cur_point;
		random_direction(&delta);
		delta *= eps;
		next_point += delta;
		if(inside(next_point)) {
			cur_point = next_point;
			eps *= 1.5;
		} else {
			eps /= 1.5;
		}
	}
	for(int iter = 0; iter < niter/2; iter++) {
		next_point = cur_point;
		random_direction(&delta);
		delta *= eps;
		next_point += delta;
		if(inside(next_point)) {
			cur_point = next_point;
		}
	}
	return cur_point;
}
