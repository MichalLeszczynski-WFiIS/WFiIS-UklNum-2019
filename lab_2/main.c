#include <stdio.h>
#include <stdlib.h>


double wzor(double x)
{
    double wynik;
if(x > -0.5 && x < 0)
{
    wynik = 1;
}
else if(x > 0 && x < 0.5)
{
    wynik = -1;
}
else wynik = 0;

    return wynik;
}

double rozwiazanieDokladne(double x)
{
    double wynik;
if(x >= -2.0 && x <= -0.5)
{
    wynik = x/16.0 + 1.0/8.0 ;
}
else if(x > -0.5 && x <= 0.0)
{
    wynik = -1.0*x*x/2.0 - x*7.0/16.0;
}
else if(x > 0.0 && x <= 0.5)
{
    wynik = x*x/2.0 - x*7.0/16.0;
}
else wynik = x/16.0 - 1.0/8.0 ;

    return wynik;
}







int main()
{


int N = 50;
double *a,*b,*c,*d,*u,*l,*y,*v;
b = (double*)malloc((N+1)* sizeof(double));
a = (double*)malloc((N+1)* sizeof(double));
c = (double*)malloc((N+1)* sizeof(double));
d = (double*)malloc((N+1)* sizeof(double));
u = (double*)malloc((N+1)* sizeof(double));
l = (double*)malloc((N+1)* sizeof(double));
y = (double*)malloc((N+1)* sizeof(double));
v = (double*)malloc((N+1)* sizeof(double));



double h = 2*2.0 / (N-1); //odleglosc miedzy rownaniami
double x;
//b jako liczba = 2
//b przy ukladzie rownan to wektor wyrazow wolnych
//dla kazdego wezla jest rownanie
//dostajemy uklad rownan
//







for(int i=1;i<=N;i++)
{
    x = -2.0 + h*(i-1) ;
    b[i] =  -1 * wzor(x); 
    d[i] = -2.0 / h / h;
    a[i] = 1/h/h;
    c[i] = 1/h/h;
}

//Warunki brzegowe
d[1] = 1; //reszta to zera w wierszu
c[1] = 0;
b[1] = 0; //zerujemy żeby narzucic potencjal w punktach brzegowych
d[N] = 1; //reszta to zera w wierszu
a[N] = 0;
b[N] = 0;

    //LU -> wzory (6) - (7) - (8) 
    u[1] = d[1];
    for(int i=2;i<=N; i++)
    {
        l[i] = a[i]/u[i-1];   //a_i = 1/2 (7)

        u[i] = d[i] - l[i] * c[i-1] ;   //d_i =  (8) 
        
          }

//Ly = b
    y[1] = b[1];
    for(int i=2; i<=N ;i++)
    {
        y[i] = b[i] - l[i] * y[i-1];
    }

//U V = y
    v[N] = y[N] / u[N] ;
    for(int i=N-1; i>=1 ; i--)
    {
        v[i] = (y[i] - c[i] * v[i+1])/u[i];
    }


//wektor v do pliku i narysować

// FILE *fp; 
//     fp=fopen("wektror_v50.dat", "w");

//     for(int i=1; i<=N-1 ; i++)
//     {
//         x = -2.0 + h*(i-1);
//    fprintf (fp, "%f %f\n",x, v[i]); /* zapisz nasz łańcuch w pliku */
//     }

//    fclose (fp); /* zamknij plik */

FILE *fp; 
    fp=fopen("wektror_v50idealne.dat", "w");

    for(int i=1; i<=N-1 ; i++)
    {
        x = -2.0 + h*(i-1);
   fprintf (fp, "%f %f\n",x, rozwiazanieDokladne(x)); /* zapisz nasz łańcuch w pliku */
    }

   fclose (fp); /* zamknij plik */












free(a);
free(b);
free(c);
free(d);
free(u);
free(l);
free(y);
free(v);
    return 0;
}
