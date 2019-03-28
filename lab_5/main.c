#include <stdlib.h>
#include <cmath>
#include <stdio.h>


///////////////// POCZĄTEK FUNKCJI ////////////////////////////////////

double absol(double x)
{
    if(x < 0)
    return -x;
    else
    return x;
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

void macierz_razy_wektor(double* y, double **A, double *x, int n)
{

for(int i=0;i<n;i++)
    {
        y[i] = 0;
        for(int j = 0 ; j< n ; j++)
        {
            y[i] += A[i][j] * x[j];
        }
    }
}


void aktualizacja_W(double **W, double* x_s, int n, double lambda)
{
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < n; j++)
        {
            W[i][j] = W[i][j] - lambda * x_s[i] * x_s[j];
        }
    }
}


void wyplenijWektorWartoscia(double* x,double val, int n)
{
     for(int i=0;i<n;i++)
        {
            x[i] = val;
        }
}


void macierz_razy_macierz(double ** Wynik, double ** A, double ** B, int n)
{
     for(int i = 0; i < n;i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            Wynik[i][j] = 0.0;
            for(int s = 0; s < n ; s ++)
            {
                Wynik[i][j] += A[i][s] * B[s][j]; 
            }
        }
    }

}

void wypisz_macierz(double ** A,int n)
{
    printf("\n");
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j < n; j++)
        {
            printf("%g\t\t ", A[i][j]);
        }
        printf("\n");
    }
}


void transponuj(double **Tmp,double **A, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j < n; j++)
        {
            Tmp[i][j] = A[j][i];
        }
    }
}


///////////////// KONIEC FUNKCJI ////////////////////////////////////


int main()
{


//////////// POCZĄTEK INICJALIZACJI //////////////////////////////
int n = 7;
int K_val = n;
int IT_MAX = 12;

double l;
double m;
double lambda;

double **A;
double **W;
double **X;
double **Wynik;
double **Tmp;
double **Tmp2;
    A = (double**)malloc(n*sizeof(double*));
    W = (double**)malloc(n*sizeof(double*));
    X = (double**)malloc(n*sizeof(double*));
     Tmp = (double**)malloc(n*sizeof(double*));
     Tmp2 = (double**)malloc(n*sizeof(double*));
    Wynik = (double**)malloc(n*sizeof(double*));
    for(int i=0;i<n;i++)
    {
        A[i] = (double*)malloc(n*sizeof(double));
        W[i] = (double*)malloc(n*sizeof(double));
        X[i] = (double*)malloc(n*sizeof(double));
        Wynik[i] = (double*)malloc(n*sizeof(double));
        Tmp[i] = (double*)malloc(n*sizeof(double));
        Tmp2[i] = (double*)malloc(n*sizeof(double));
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n; j++)
        {
             A[i][j] = 1.0/sqrt(2.0 +(double)absol(i*1.0 -j*1.0));
             W[i][j] = 1.0/sqrt(2.0 +(double)absol(i*1.0 -j*1.0));
        }
    }


    double *x_s = (double*)malloc(n*sizeof(double));
    double *x_n = (double*)malloc(n*sizeof(double));



    FILE *fd; 
     fd=fopen("macierz_d.dat", "w");
     FILE *fp; 
     fp=fopen("lambdy.dat", "w");

////////////////// KONIEC INICJALIZACJI /////////////////////



/////////////////////// OBLICZENIA //////////////////////////

    for(int k = 0; k < K_val; k++)
    {
        wyplenijWektorWartoscia(x_s,1.0, n);
        for(int i = 1; i <= IT_MAX; i++)
        {
            //x_n = Wx_s
            macierz_razy_wektor(x_n, W, x_s, n);
            //l = x_n^T * x_s
            l = iloczyn_skalarny(x_n, x_s, n);
            //m = x_s^T * x_s
            m = iloczyn_skalarny(x_s, x_s, n);
            //
            lambda = l/m;
            //x_s = x_n / ||x_n||
            for(int j=0;j<n;j++)
            {
                x_s[j] = x_n[j] / norma(x_n, n);
            }
            fprintf(fp, " %g", lambda);
        }
        for(int j=0;j<n;j++)
            {
                X[k][j] = x_s[j];
            }
        //W = W - lambda * x_s * x_s^T
        aktualizacja_W(W, x_s, n, lambda);
        fprintf(fp, "\n");


    }

wypisz_macierz(X, n);

transponuj(Tmp2, X, n);


macierz_razy_macierz(Tmp,X, A ,n);
macierz_razy_macierz(Wynik, Tmp, Tmp2, n);

wypisz_macierz(Wynik, n);

    
///////////////// zapisanie macierrzy w do pliku ///////////////
for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            fprintf(fd, "%g ", Wynik[i][j]);
        }
        fprintf(fd, "\n");
    }


////////////////////// KONIEC OBLICZEŃ ////////////////////////



free(x_s);
free(x_n);
for(int i=0;i<n;i++)
    {
        free(A[i]);
        free(W[i]);
        free(X[i]);
        free(Wynik[i]);
        free(Tmp[i]);
    }
    free (A);
    free(W);
    free(X);
    free(Wynik);
    free(Tmp);
    free(Tmp2);


return 0;
}
