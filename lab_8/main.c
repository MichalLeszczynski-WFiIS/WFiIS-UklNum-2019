#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include "utilities.h"

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
    return 1.0 / (1.0 + x*x);
}

double f_2(double x)
{
    return cos(2.0*x);
}

void wyznaczM(double* X_w, double* Y_w, double* m, int n, double alfa, double beta)
{

}

double wyznacz_s_x(double x, double* X_w, double* Y_w,int n, gsl_vector* m, double* h)
{
    double a;
    double b;
    int in = -1;
    int i=1;
	do{
		//printf("x = %f, X_w[i] = %f\n", x, X_w[i]);
    	if(x >= X_w[i-1] && x <= X_w[i])
    	{
        	a = ((Y_w[i] - Y_w[i-1])/h[i]) - (h[i]/6.0) * (gsl_vector_get(m,i) - gsl_vector_get(m,i-1));
        	b = Y_w[i-1] - gsl_vector_get(m,i-1) * h[i]*h[i] /6.0;
        	in = i;	
    	}
    	i++;
    //printf("i = %d,x =  %f, X_w[i] =  %f\n", i, x, X_w[i]);
}while(in==-1);
	printf("%d\n", in);
	double s = gsl_vector_get(m,in-1) * pow(X_w[in] - x, 3)/(6.0*h[in]) + gsl_vector_get(m,in) * pow(x - X_w[in-1], 3)/(6.0*h[in]) + a * (x - X_w[in-1]) + b;
	return s;
}

double druga_pochodna_f_1(double x, double delta_x)
{
	double tmp = f_1(x - delta_x) - 2.0*f_1(x) + f_1(x+delta_x);
	return tmp/(delta_x*delta_x);
}


// ///////////////// KONIEC FUNKCJI ////////////////////////////////////



// //////////// POCZĄTEK INICJALIZACJI //////////////////////////////

int main()
{

    int n = 21;
    int N = 500;
    double *X_w = (double*)malloc((n+1)*sizeof(double));
    double *X_n = (double*)malloc((N+1)*sizeof(double));
    double *Y_w = (double*)malloc((n+1)*sizeof(double));
    double *h = (double*)malloc((n+1)*sizeof(double));
    double war;



    gsl_matrix *A = gsl_matrix_calloc(n,n);
    gsl_vector *d = gsl_vector_calloc(n);
    gsl_vector *u = gsl_vector_calloc(n);
    gsl_vector *m = gsl_vector_calloc(n);
    gsl_vector *lambda = gsl_vector_calloc(n);

      FILE *f2; 
      f2=fopen("funkcja_1_n21.dat", "w");

      // FILE *f3; 
      // f3=fopen("funkcja_2_n5.dat", "w");



// /////////////////////// OBLICZENIA //////////////////////////


    double x_min = -5.0;
    double x_max = 5.0;
    double delta_x = (x_max - x_min)/(n-1);

    for(int i=0;i < n; i ++)
    {
	    X_w[i] = delta_x * i + x_min;
	    Y_w[i] = f_1(X_w[i]);
    }
    delta_x = (x_max - x_min)/(N-1);
    for(int i=0;i < N; i ++)
        {
        X_n[i] = delta_x * i + x_min;
        }

        double h2 = X_w[4] - X_w[3];


    for(int i = 1; i < n-1; i ++)
    {
        h[i] = h2;
        h[i-1] = h2;
        war = 0.5; 
        printf("%f\n", war);
        gsl_vector_set(lambda,i,war);
        war = 1.0 -  gsl_vector_get(lambda,i);
        gsl_vector_set(u,i,war);
        war = (6.0/(h2 + h2)) * (((Y_w[i+1] - Y_w[i])/h2) - ((Y_w[i] - Y_w[i-1])/h2));
        gsl_vector_set(d,i,war);
    }




    printf("d= %f\n",gsl_vector_get(d,n-1));
    gsl_vector_set(d,0,0.0);
    gsl_vector_set(d,n-1,0.0);
    printf("d= %f\n",gsl_vector_get(d,n-1));

    for(int i=0; i < n; i ++ )
    {
        if(i == 0)
        {
            gsl_matrix_set(A, i, i, 1.0);
            gsl_matrix_set(A, i, i+1, 0.0);
        }
        if(i == n-1)
        {
            gsl_matrix_set(A, i, i, 1.0);
            gsl_matrix_set(A, i, i-1, 0.0);

        }
        if(i < n-1 && i > 0)
        {
            // gsl_matrix_set(A, i, i+1, gsl_vector_get(lambda,i));
            // gsl_matrix_set(A, i, i-1, gsl_vector_get(u,i));
       		 gsl_matrix_set(A, i, i+1, 0.5);
           	 gsl_matrix_set(A, i, i-1, 0.5);
           gsl_matrix_set(A, i, i, 2.0);
        }
    }

    int s;

    gsl_permutation * p = gsl_permutation_alloc (n);
    gsl_linalg_LU_decomp (A, p, &s);
    gsl_linalg_LU_solve (A, p, d, m);
for(int i=0; i < n; i ++)
{
   // fprintf(f2, "%f %f %f \n", X_w[i] ,gsl_vector_get(m, i),druga_pochodna_f_1(X_w[i], 0.01) );
}

for(int i=1; i < N; i++)
{
  //  printf(" %f \n", wyznacz_s_x(X_n[i],X_w,Y_w,n,m,h));
    fprintf(f2, "%f %f %f \n", X_n[i] ,wyznacz_s_x(X_n[i],X_w,Y_w,n,m,h), f_1(X_n[i]));
}
 
    printf("\n\n");






// ////////////////////// KONIEC OBLICZEŃ ////////////////////////

fclose(f2);
// fclose(f3);

free(X_w);
free(X_n);
free(Y_w);
free(m);
free(h);
free(A);
free(d);
free(u);
free(lambda);

 

return 0;
}
