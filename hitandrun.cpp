#include <shared.h>
#include <sample.h>

point random_sample(int n, point p_start, bool (*inside)(const point), int niter) {
	point p(n);
	p = p_start;

	point dir(n), p2(n);

	for(int iter = 0; iter < niter; iter++) {
		random_direction(&dir);

		real lo, hi, mid;

		hi = 1.0;
		do {
			hi *= 2.0;
			move_along_line(p, dir, hi, &p2);
		} while(inside(p2));
		lo = 0.0;
		while(lo + epsilon < hi) {
			mid = lo + 0.5 * (hi - lo);
			move_along_line(p, dir, mid, &p2);
			if(inside(p2))
				lo = mid;
			else
				hi = mid;
		}
		real s1 = lo;

		hi = 1.0;
		do {
			hi *= 2.0;
			move_along_line(p, dir, -hi, &p2);
		} while(inside(p2));
		lo = 0.0;
		while(lo + epsilon < hi) {
			mid = lo + 0.5 * (hi - lo);
			move_along_line(p, dir, -mid, &p2);
			if(inside(p2))
				lo = mid;
			else
				hi = mid;
		}
		real s2 = -lo;

		real s = rand_one_sided() * (s2 - s1) + s1;
		move_along_line(p, dir, s, &p);
	}

	return p;
}
