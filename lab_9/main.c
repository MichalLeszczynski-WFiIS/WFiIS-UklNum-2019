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


double f_1(double x)
{
    double alfa = ((double)rand() / ((double)RAND_MAX + 1.0) ) - 0.5;
   // double alfa = 0;
    return 2.0*sin(x) + sin(2.0*x) + 2.0*sin(3.0*x) + alfa;
}

double f_2(double x)
{
    return 2.0*sin(x) + sin(2.0*x) + 2.0*cos(x) + cos(2.0*x);
}

double f_3(double x)
{
    return 2*sin(1.1*x) + sin(2.1*x) + 2*sin(3.1 *x);
}



// ///////////////// KONIEC FUNKCJI ////////////////////////////////////



// //////////// POCZĄTEK INICJALIZACJI //////////////////////////////

int main()
{

    int N = 100;

    double M_s = 5.0;
    double M_c = 5.0;

    double* a = (double*)malloc((M_s+1)*sizeof(double));
    double* b = (double*)malloc((M_c+1)*sizeof(double));
    double* x = (double*)malloc((N+1)*sizeof(double));
    double* y = (double*)malloc((N+1)*sizeof(double));
    double* F = (double*)malloc((N+1)*sizeof(double));

      FILE *f2; 
      f2=fopen("funkcja_1_a_b(5,5).dat", "w");

      // FILE *f3; 
      // f3=fopen("funkcja_2_n5.dat", "w");



// /////////////////////// OBLICZENIA //////////////////////////


    double x_min = 0.0;
    double x_max = 2.0*3.1415;
    double delta_x = (x_max - x_min)/(N);

    for(int i=0;i < N; i ++)
    {
	    x[i] = delta_x * i + x_min;
	    y[i] = f_1(x[i]);
    }


double tmp_a = 0;
double tmp_b = 0;


for(int k = 1; k < M_s; k++)
{
    a[k] = 0.0;
    for(int i = 0; i < N; i++)
    {
        a[k] += y[i] * sin(k*x[i]) / (N/2.0);
    }
}

double cn;

if(M_c > 0)
{ 
    for(int j = 0; j <= M_c; j++)
    {
        b[j] = 0.0;
        if(j == 0)
        {
            cn = N;
        }
        else
        {
            cn = N/2;
        }
        for(int i = 0; i < N; i++)
        {
            b[j] += y[i] * cos(j*x[i]) / cn;
        }
    }
}

/// F(x)

for(int i = 0; i < N; i ++)
{
    double wynik = 0;
    for(int k = 1; k <= M_s; k ++)
    {
        wynik+= a[k] * sin(k*x[i]);
    }

    for(int j = 0; j <= M_c; j ++)
    {
        wynik+= b[j] * cos(j * x[i]);
    }
F[i] = wynik;
}




for(int i=1; i < N; i++)
{
 //   fprintf(f2, "%f %f %f \n", x[i], y[i], F[i]);
}
 
    printf("\n\n");


for(int i = 1; i <= M_c; i ++)
{
    fprintf(f2, "%d %f %f\n", i, a[i], b[i]);
}



// ////////////////////// KONIEC OBLICZEŃ ////////////////////////

fclose(f2);
// fclose(f3);

free(x);
free(y);
free(a);
free(b);
free(F);


 

return 0;
}
