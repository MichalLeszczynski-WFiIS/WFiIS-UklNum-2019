#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
double absol(double x)
{
    if(x < 0)
    return -x;
    else
    return x;
}
double max(double x, double y)
{
    if(x>y)
    return x;
    else 
    return y;
}
double min(double x, double y)
{
    if(x<y)
    return x;
    else 
    return y;
}
double iloczyn_skalarny(double* x, double* y, int n)
{
    double suma = 0.0;
    for(int i=0;i<n;i++)
    {
        suma+= x[i] * y[i];
    }
    return suma;
}
double norma(double* x,int n)
{
    return sqrt(iloczyn_skalarny(x,x,n));
}
void macierz_razy_wektor(double* y, double **A, double *x, int n, int m)
{
    int j_min;
    int j_max;
for(int i=0;i<n;i++)
    {
       j_min = max(0,i-m);
        j_max = min(i+m, n-1);
        y[i] = 0;
        for(int j = j_min ; j<= j_max ; j++)
        {
            y[i] += A[i][j] * x[j];
        }
    }
}



int main()
{

    // time t1, t2;
    // time(&t1);
    // time(&t2);

    int n = 1000;
    double m = 5;
    
    double *b = (double*)malloc(n*sizeof(double));
    for(int i=0;i<n;i++)
    {
        b[i] = (double)i;
    }

    double *r = (double*)malloc(n*sizeof(double));  
    double *x = (double*)malloc(n*sizeof(double));
    double *temp = (double*)malloc(n*sizeof(double));
    double *y = (double*)malloc(n*sizeof(double));
    double **A;
    A = (double**)malloc(n*sizeof(double*));
    for(int i=0;i<n;i++)
    {
        A[i] = (double*)malloc(n*sizeof(double));
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n; j++)
        {
            if(absol(i-j) <=5.0)
            {
                A[i][j] = 1.0/(1.0 +(double)absol(i -j));
            }
            else A[i][j] =0.0;
        }
    }

    for(int i=0;i<n;i++)
    {
        x[i] =0.0;
    }
    double norm_r;
    double norm_x;
    double alfa;
    int k=0;


FILE *fp; 
    fp=fopen("norma_x.dat", "w");
FILE *fd; 
    fd=fopen("norma_r.dat", "w");
FILE *fo; 
    fo=fopen("ogolne.dat", "w");


    do{
        macierz_razy_wektor(y, A, x, n, m);
        for(int i=0;i<n;i++)
        {
            r[i] = b[i] - y[i];
           // printf("r[%d] = %f\n", i, r[i]);
        }
        macierz_razy_wektor(temp, A, r, n, m);
        alfa = iloczyn_skalarny(r, r, n) / iloczyn_skalarny(r, temp, n);
        for(int i=0;i<n;i++)
        {
            x[i] = x[i] + alfa*r[i];
        } 
        k++;
    norm_r = norma(r,n);
    norm_x = norma(x, n);


   fprintf (fp, "%d %f\n",k, norm_x); 
    fprintf (fd, "%d %f\n",k, norm_r);

fprintf (fo, "%d \t%f\t %f\t %f  \n", k, alfa, norm_r, norm_x);


    }while(norm_r > 1e-6);


fclose (fp);
fclose (fd);
fclose (fo);

    


    

free(b);
free(temp);
free(x);
free(y);
free(r);
for(int i=0;i<n;i++)
    {
        free(A[i]);
    }
    free (A);


    return 0;
}