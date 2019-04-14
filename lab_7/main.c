#include <stdlib.h>
#include <cmath>
#include <stdio.h>


// ///////////////// POCZĄTEK FUNKCJI ////////////////////////////////////

double absol(double x)
{
    if(x < 0)
    return -x;
    else
    return x;
}

double f(double x)
{
    return exp(-x*x);
}

double interpoluj(double* X_w,double* Y_w,int n,double x)
{    
    double w_n = 0.0;
    for(int j = 0; j <= n; j++ )
    {

       double u = 1.0;
        for(int i = 0; i <= n ; i++ )
        {
            if(i != j)
            {
                u = u*(x-X_w[i])/((X_w[j] - X_w[i]));
            }
        }
        w_n = w_n + Y_w[j] * u;
    }
}
// ///////////////// KONIEC FUNKCJI ////////////////////////////////////



// /////////////// TEORIA //////////////////////////////
/*
Wzór lagrange'a

Wn(x) = suma ( j = 0 do n) (y_j * (x-x_0)..(x-x_j-1) * (x-x_j+1).(x-x_n) / (x_j-x_0) * ... * (x_j - x_n)


dane: x_0, x_1, ... x_n
      y_0, y_1, ... y_n

*/
// ///////////////////////////////////////////////////////////


// //////////// POCZĄTEK INICJALIZACJI //////////////////////////////

int main()
{

    int n = 20;
    int N = 500;
    double step = 10.0 / (double)n;

    double *W_n = (double*)malloc((N+1)*sizeof(double));
     double *X_n = (double*)malloc((N+1)*sizeof(double));
    double *X_w = (double*)malloc((n+1)*sizeof(double));
    double *Y_w = (double*)malloc((n+1)*sizeof(double));
    double x;
    double w_n; 
    double u;



   
    
    //  FILE *f2; 
    //  f2=fopen("Y_w[X_w].dat", "w");
     FILE *f3; 
     f3=fopen("n20c.dat", "w");

   

    for(int i=0; i <= n ; i ++)
    {

        X_w[i] = (1.0/2.0) * 10.0 * cos(M_PI*(2.0*i+1.0)/(2.0*n+2.0)); 
        //fprintf(f2 , "%f ", X_w[i]);

        Y_w[i] = f(X_w[i]);
      //  fprintf(f2 , "%f\n", Y_w[i]);

    }

    printf("\n\n");


//      FILE *f4; 
//      f4=fopen("siecznych_funkcja_wielomian.dat", "w");

// ////////////////// KONIEC INICJALIZACJI /////////////////////



// /////////////////////// OBLICZENIA //////////////////////////




for(int k = 0; k <= N; k ++)
{
    x = (k * 10.0 / (double)N) - 5.0;
    X_n[k] = x;
    
    
    W_n[k] = interpoluj(X_w, Y_w, n, x);
}

for(int i = 0; i <= N; i ++)
{
    fprintf(f3, "%f %f %f\n ", X_n[i], W_n[i], f(X_n[i]));
}


// ////////////////////// KONIEC OBLICZEŃ ////////////////////////

// fclose(f1);
// fclose(f2);
fclose(f3);
// fclose(f4);
free(W_n);
free(X_w);
free(Y_w);



return 0;
}
