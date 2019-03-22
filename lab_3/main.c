#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <stdio.h>
#include <math.h>
#include "/opt/NR/numerical_recipes.c/nrutil.h"
#include "/opt/NR/numerical_recipes.c/nrutil.c"
#include "/opt/NR/numerical_recipes.c/gaussj.c"
////////////////////////////////////////////////////////////////////
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



int najwiekszySpadek()
{

    
    int n = 10000;
    printf("n = %d", n);
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
        x[i] =1.0;
    }
    double norm_r;
    double norm_x;
    double alfa;
    int k=0;


// FILE *fp; 
//     fp=fopen("norma_x.dat", "w");
// FILE *fd; 
//     fd=fopen("norma_r.dat", "w");
// FILE *fo; 
//     fo=fopen("ogolne.dat", "w");

clock_t start;
  start = clock();
    

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


//    fprintf (fp, "%d %f\n",k, norm_x); 
//     fprintf (fd, "%d %f\n",k, norm_r);

// fprintf (fo, "%d \t%f\t %f\t %f  \n", k, alfa, norm_r, norm_x);


    }while(norm_r > 1e-6);

printf("\n\nk: %d\n\n", k);
printf("Time = %lu ticks\n", clock() - start);
printf("cps = %d\n", CLOCKS_PER_SEC);
printf("Time / cps = %f s\n", (clock() - start)/(double)CLOCKS_PER_SEC);
// fclose (fp);
// fclose (fd);
// fclose (fo);


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

//////////////////////////////////////////////////////////////////////////////////////////////////////



float absolf(float x)
{
    if(x < 0)
    return -x;
    else
    return x;
}
float maxf(float x, float y)
{
    if(x>y)
    return x;
    else 
    return y;
}
float minf(float x, float y)
{
    if(x<y)
    return x;
    else 
    return y;
}
float iloczyn_skalarnyf(float* x, float* y, int n)
{
    float suma = 0.0;
    for(int i=0;i<n;i++)
    {
        suma+= x[i] * y[i];
    }
    return suma;
}
float normaf(float* x,int n)
{
    return sqrt(iloczyn_skalarnyf(x,x,n));
}

void macierz_razy_wektorf(float* y, float **A, float *x, int n, int m)
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


int Zupelne()
{

    
    int n = 10000;
    
    printf("n = %d", n);
    float m = 5;
    
    float *b = (float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)
    {
        b[i] = (float)i;
    }

    float *r = (float*)malloc(n*sizeof(float));  
    float *x = (float*)malloc(n*sizeof(float));
    float *temp = (float*)malloc(n*sizeof(float));
    float *y = (float*)malloc(n*sizeof(float));
    float **A;
    A = (float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;i++)
    {
        A[i] = (float*)malloc(n*sizeof(float));
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n; j++)
        {
            if(absolf(i-j) <=5.0)
            {
                A[i][j] = 1.0/(1.0 +(float)absolf(i -j));
            }
            else A[i][j] =0.0;
        }
    }

    for(int i=0;i<n;i++)
    {
        x[i] =0.0;
    }
    float norm_r;
    float norm_x;
    float alfa;
    int k=0;


// FILE *fp; 
//     fp=fopen("norma_x.dat", "w");
// FILE *fd; 
//     fd=fopen("norma_r.dat", "w");
// FILE *fo; 
//     fo=fopen("ogolne.dat", "w");

clock_t start;
  start = clock();
    

    do{
        macierz_razy_wektorf(y, A, x, n, m);
        for(int i=0;i<n;i++)
        {
            r[i] = b[i] - y[i];
           // printf("r[%d] = %f\n", i, r[i]);
        }
        macierz_razy_wektorf(temp, A, r, n, m);
        alfa = iloczyn_skalarnyf(r, r, n) / iloczyn_skalarnyf(r, temp, n);
        for(int i=0;i<n;i++)
        {
            x[i] = x[i] + alfa*r[i];
        } 
        k++;
    norm_r = normaf(r,n);
    norm_x = normaf(x, n);


//    fprintf (fp, "%d %f\n",k, norm_x); 
//     fprintf (fd, "%d %f\n",k, norm_r);

// fprintf (fo, "%d \t%f\t %f\t %f  \n", k, alfa, norm_r, norm_x);


    }while(norm_r > 1e-3);

printf("\n\nk: %d\n\n", k);







printf("Time = %lu ticks\n", clock() - start);
printf("cps = %d\n", CLOCKS_PER_SEC);
printf("Time / cps = %f s\n", (clock() - start)/(float)CLOCKS_PER_SEC);
// fclose (fp);
// fclose (fd);
// fclose (fo);


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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






int gausem()
{

    
    int n = 1000;
    float m = 5;
    
    float **b;


    float *r = (float*)malloc(n*sizeof(float));  
    float *x = (float*)malloc(n*sizeof(float));
    float *temp = (float*)malloc(n*sizeof(float));
    float *y = (float*)malloc(n*sizeof(float));
    float **A;


A = matrix(1, n, 1, n);
    b = matrix(1, n, 1, 1);
    

    for(int i=1;i<=n;i++)
    {
         b[i][1] = (float)i;
        for(int j=1;j<=n; j++)
        {
            if(absolf(i-j) <=5.0)
            {
                A[i][j] = 1.0/(1.0 +(float)absolf(i -j));
            }
            else A[i][j] =0.0;
        }
    }


clock_t start;
  start = clock();
    

    gaussj(A,n,b,1);



printf("Time = %lu ticks\n", clock() - start);
printf("cps = %d\n", CLOCKS_PER_SEC);
printf("Time / cps = %f s\n\n\n", (clock() - start)/(float)CLOCKS_PER_SEC);


    free_matrix(A,1,n,1,n);
    free_matrix(b,1,n,1,1);

    return 0;
}















int main()
{
    najwiekszySpadek();
    Zupelne();
   // gausem();

    return 0;
}