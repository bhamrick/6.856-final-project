#include<sample.h>
#include<cstdio>
#include<cstdlib>

int main() {
	int ndims = 5;
	int dims[5] = {2,3,4,10,100};
	//cubes
	for(int i = 0; i<ndims; i++) {
		
	}
}

bool cube_separation_oracle(point p) {
	for(int i = 0; i<p.n; i++) {
		if(p.x[i] <= -1 || p.x[i] >= 1) return false;
	}
	return true;
}

bool sphere_separation_oracle(point p) {
	real square_norm = 0.0;
	for(int i = 0; i<p.n; i++) {
		square_norm += p.x[i] * p.x[i];
	}
	return square_norm < 1.0;
}
