#include<math.h>
#include<stdio.h>
#include "hybrid.h"
/* ----------------------------------------------------------------------------------	*/
/* 			HYBRID ALGORITHM 						*/
/* ----------------------------------------------------------------------------------	*/
/* This file contains the full description of the function hybrid. Hybridizes   	*/
/* the bisection and the regula falsi methods by choosing at every step the smallest 	*/
/* subinterval produced by the before mentioned methods					*/


int hybrid(int *niter, double *xstar, double x0, double x1, TargetFunc f){
double x_l, x_r;    /*   computing the left end point of the interval */
double f_l, f_r;    /* the corresponding values of the function */\

/* Computation of these values */
x_l = fmin(x0,x1);
x_r = fmax(x0,x1);
f_l = f(x_l);
f_r = f(x_r);
 

if ( fabs(f_l) < EPS_F ) {
	*xstar = x_l;
	return 1;
	}

if ( fabs(f_r) < EPS_F ) {
*xstar = x_r;
return 1;
}
 
  if ( f_l * f_r > 0.0 ){
        return 0;
 }
/* ---------------------------------------------------------------------- */
/* Here is where the hybrid algorithm starts                              */
/* DEFINITIONS:                                                           */
/* xb_m = middle point of the interval [ x _l, x_r ]                      */
/* xf_m = x-intersect of the interpolaing line containing the points:     */
/* ( x_l,f_l ) and ( x_r , f_r )                                          */
/* ---------------------------------------------------------------------- */
/* ---------------------------------------------------------------------- */

while ( *niter < ITER_MAX && fabs(x_r -x_l)> EPS_X && fabs(f_r-f_l)>EPS_F){
*niter = *niter + 1;
/* first we compute the subinterval containing the bisection: */
	double x_bis = 0.5*(x_r + x_l);
	double x_falsi = (x_l*f_r-f_l*x_r)/(f_r-f_l);
	double f_bis = f(x_bis);
	double f_falsi = f(x_falsi);
	double f_m = (-fabs(f_bis - f_falsi)+f_bis+f_falsi)*0.5; /*computing the minimum */
	double xb_l;
	double xb_r;
	double xf_l;
	double xf_r;

if( (f_bis)*(f_l) < 0 ){
	xb_r = x_bis;
	xb_l = x_l;
}
	else {
	xb_l = x_bis;
	xb_r = x_r;
	}

/* now we compute the subinterval using the regula falsi */


if((f_falsi)*(f_l) < 0){
	xf_r = x_falsi;
	xf_l = x_r;
	}
    else{
	xf_l = x_falsi;
	xf_r = x_r;
	}

/* comparing the two resulting subinitervals */
	if(fabs(xb_r - xb_l) < fabs( xf_r-xf_l ) ){
	x_l = xb_l;
	x_r = xb_r;
	*xstar = 0.5*(xb_r+xb_l);
}
	else{
	x_l = xf_l;
	x_r = xf_r;
        *xstar = (x_l*f_r - f_l*x_r)/(f_r-f_l);
         }
	f_l = f(x_l);
	f_r = f(x_r);
//	printf("xstar = %f\n", *xstar);
}
// printf("Number of iterations:%d \n",*niter); 
         return 0;

} /* end of the function */
