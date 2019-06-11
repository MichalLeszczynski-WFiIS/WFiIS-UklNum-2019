#include <stdlib.h>
#include <cmath>
#include <stdio.h>


// ///////////////// POCZĄTEK FUNKCJI ////////////////////////////////////


double f(double x)
{
    if(x==0) x+= 0.0000001;
    return sin(x) / (x);
}

double f_2(double x)
{
    if(x ==0) x += 0.0000001;
    return ( cos(x) - exp(x) ) / sin(x);
}

double f_3(double x)
{
    // if(x==0) x+= 0.0000001;
    return exp(-1.0 / (x + 0.0000001))* (1/(x+0.000001));
}
// ///////////////// KONIEC FUNKCJI ////////////////////////////////////



// //////////// POCZĄTEK INICJALIZACJI //////////////////////////////

int main()
{

    FILE *f1; 
    f1=fopen("cosx-ex.dat", "w");



// /////////////////////// OBLICZENIA //////////////////////////




double n = 15;
double a = -1.0;
double b = 1.0;

double** D = (double**)malloc(n*sizeof(double*));
    for(int i=0;i<n;i++)
    {
        D[i] = (double*)malloc(n*sizeof(double));
    }
  

D[0][0] = (0.5 * f_2(a) + 0.5 * f_2(b)) * (b - a);

double sum = 0.0;
double h_n;





for(int i = 1; i < n; i ++)
{
    h_n = (b - a) / pow(2,i);

    sum = 0.0;

    for(int j=1; j <= pow(2, i-1); j++)
    {
        sum+= f_2(a + (2*j -1) * h_n);
    }

    D[i][0] = 0.5 * D[i-1][0] + h_n * sum;
}

for(int i = 1; i < n; i ++)
{
    for(int k = 1; k <= i; k ++)
    {
        D[i][k] = (pow(4,k) * D[i][k-1] - D[i-1][k-1]) / (pow(4,k) -1) ;
    }
}

for(int i = 0; i < n; i ++)
{
    for(int k = 0; k <= i; k ++)
    {
        fprintf(f1, "%f ",D[i][k]);
    }
    fprintf(f1, "\n");
}






for(int i=0;i<n;i++)
    {
        free(D[i]);
    }
    free(D);


// ////////////////////// KONIEC OBLICZEŃ ////////////////////////

fclose(f1);



 

return 0;
}
