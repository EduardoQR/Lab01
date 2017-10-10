#include <stdio.h>
// -----------------------------------------------------------------
//              VARIABLES AND FUNCTION DEFINITION
// -----------------------------------------------------------------


//double alpha(int);                  // bessel expression definition
double x_val;                       // x-value in Bessel function
// double x = x_val/2.0;
int n;                              // n parameter in Bessel function
double eps;                         // toleance

// ------------------------------------------------------------------
//                          MAIN FUNCTION
// ------------------------------------------------------------------


int main(int argc, const char * argv[]) {

    //--------------------------------------------------------------
    //     		INPUT FORM THE CONSOLE
    // -------------------------------------------------------------
    printf("Introduce the value of n: \n");
    scanf("%d", &n);
    printf("Introduce the value of x: \n");
    scanf("%le", &x_val);
    printf("Introduce the value of tol \n");
    scanf("%le",&eps);
    // -------------------------------------------------------------
    // 		EVALUATION OF THE BESSEL FUNCTION
    //--------------------------------------------------------------
    
    double x = x_val/2.0;
    double first_factor = 1;
    for (int i = 1; i< n+1; i++)
    {
        double prod = x/i;
        first_factor = prod*(first_factor);
    }
    double second_factor = 1 ;
    double third_factor = 1 ;
    double expr = 1;
    int m = 1;
    double sum =0;
    while(expr >= eps)
    {
        double prod = x/m;
        second_factor =  prod*second_factor;
        third_factor = third_factor * x/(n+m);
        expr = first_factor*(second_factor)*(third_factor);
        sum =sum + expr;
                        m = m + 1;
    }
    
    
    printf("Number of iterations -> %d \n ",m);
    printf("The value of the error -> %le \n ",eps);	
    printf("The value of the Bessel function -> %le \n",sum);	



    //std::cout << "Number of iterations -> "<< m << "\n"<< "Value of the error\t" <<  expr << "\n";

   // std::cout << "value of Bessel function ->" << sum << "\n";

   
    return 0;
}

