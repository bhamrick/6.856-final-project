#ifndef SAMPLE_H
#define SAMPLE_H

#include<shared.h>

#define epsilon 1.0e-12

point random_sample(int n, point p, bool (*inside)(const point), int niter);

#endif
