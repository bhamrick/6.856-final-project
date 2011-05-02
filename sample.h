#ifndef SAMPLE_H
#define SAMPLE_H

#include<shared.h>

#define epsilon 1.0e-12

point random_sample(point p, bool (*inside)(point), int niter);

#endif
