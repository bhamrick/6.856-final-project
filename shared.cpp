#include <cmath>
#include <crand>

typedef real double;

void random_direction(int n, real *vec) {
	for(int i = 0; i < n; i += 2) {
		real x, y, s;
		do {
			x = (real)(rand() - RAND_MAX/2) / (real)(RAND_MAX/2);
			y = (real)(rand() - RAND_MAX/2) / (real)(RAND_MAX/2);
			s = x*x + y*y;
		} while(s >= (real)1.0);
		s = sqrt(-log(s) / s);
		vec[i] = x * s;
		if(i + 1 < n)
			vec[i+1] = y * s;
	}
}

