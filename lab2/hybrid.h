#ifndef __HYBRID_H__
#define __HYBRID_H__
#define EPS_X 1e-10
#define EPS_F 1e-10
#define ITER_MAX 100000

typedef double(*TargetFunc)(double);


int hybrid(int *ninter, double *xstar, double x0, double x1, TargetFunc f);
#endif
