#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hybrid.h"
#include <Python.h>

double eps_x = 1e-10;
double eps_f = 1e-10;
int iter_max=100000;

PyObject* py_f = NULL;
PyObject* py_df = NULL;

double gen_f( double );
double gen_df( double );

int main( int argc, char** argv ) {

  double x_l = atof(argv[3]);
  double x_r = atof(argv[4]);

  int niter;
  double x;
  int success;

  Py_Initialize();
  FILE* fp = fopen( argv[1], "r" );
  PyRun_SimpleFile( fp, argv[1] );

  PyObject* py_main = PyImport_AddModule("__main__");
  PyObject* py_dict = PyModule_GetDict(py_main);

  py_f = PyDict_GetItemString(py_dict, argv[2]);
  if ( argc > 3 )
    py_df = PyDict_GetItemString(py_dict, argv[3]);

  
  fprintf( stdout, "\tHybrid Method: \n");
  success = hybrid( &niter, &x, x_l, x_r, &gen_f );
  fprintf( stdout, "\t\t%s with %d iterations, final solution: %lf.\n", (success) ? "Success" : "Fail", niter, x );

  Py_Finalize();

  return 0;
}

double gen_f( double x ) {
  PyObject* args = PyTuple_Pack( 1, PyFloat_FromDouble(x) );
  PyObject* sols = PyObject_CallObject( py_f, args );
  return PyFloat_AsDouble( sols );
}

double gen_df( double x ) {
  if ( py_df == NULL ) return 1.0;
  PyObject* args = PyTuple_Pack( 1, PyFloat_FromDouble(x) );
  PyObject* sols = PyObject_CallObject( py_df, args );
  return PyFloat_AsDouble( sols );
}

