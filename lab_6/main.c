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


double f(double x)
{
    return pow(log(x) - x,6) - 1;
}

double f_prim(double x)
{
    return 6*pow(log(x) - x,5) * (1/x - 1);
}

double g(double x)
{
    return pow(x,3) + 2 *pow(x,2) - 3*x + 4;
}

double g_prim(double x)
{
    return 3*pow(x,2) + 4*x -3;
}

double oblicz_p(double i, double ii, double iii)
{
    return (log(ii/iii))/(log(i/ii));
}

///////////////// KONIEC FUNKCJI ////////////////////////////////////



/////////////// TEORIA //////////////////////////////
/*
metoda newtona:
x_i+1 = x_i - f(x_i)/fprim(x_i)

koniec: x_i - x_i-1 < epsilon


metoda siecznych (dwupunktowa):
x_i+1 = x_i - f(x_i) * (x_i - x_i-1) / (f(x_i) - f(x_i-1))

koniec:



*/
///////////////////////////////////////////////////////////



int main()
{


//////////// POCZĄTEK INICJALIZACJI //////////////////////////////

    int n = 500;

    double *x = (double*)malloc(n*sizeof(double));
    double *e = (double*)malloc(n*sizeof(double));
    double *p = (double*)malloc(n*sizeof(double));
    double x_d; 

   
     FILE *f1; 
     f1=fopen("newton_funkcja_log.dat", "w");
     FILE *f2; 
     f2=fopen("newton_funkcja_wielomian.dat", "w");
     FILE *f3; 
     f3=fopen("siecznych_funkcja_log.dat", "w");
     FILE *f4; 
     f4=fopen("siecznych_funkcja_wielomian.dat", "w");

////////////////// KONIEC INICJALIZACJI /////////////////////



/////////////////////// OBLICZENIA //////////////////////////

/////// METODA NEWTONA //////

x_d = 1.0;
x[0] = 3.0;
p[0] = p[19] = 0;
    for(int i=0; i <= 20 ; i++)
    {
        x[i+1] = x[i] - (f(x[i])/f_prim(x[i]));
        e[i+1] = absol(x[i+1] - x_d);
        if(i > 1)
        {
            p[i] = oblicz_p(e[i-1], e[i], e[i+1]);
        }
    printf("%d %20.15f %20.15f %20.15f %20.15f\n", i, f(x[i]), x[i], e[i], p[i]);
    fprintf(f1,"%d %20.15f %20.15f %20.15f %20.15f\n", i, f(x[i]), x[i], e[i], p[i]);
    }

printf("\n\n");


    x[0] = -20.0;
    p[0] = p[19] = 0;
    x_d = -3.284277537306950;
    for(int i=0; i <= 20 ; i++)
    {
        x[i+1] = x[i] - (g(x[i])/g_prim(x[i]));
        e[i+1] = absol(x[i+1] - x_d);
        if(i > 1)
        {
            p[i] = oblicz_p(e[i-1], e[i], e[i+1]);
        }
    printf("%d %20.15f %20.15f %20.15f %20.15f\n", i, g(x[i]), x[i], e[i], p[i]);
    fprintf(f2,"%d %20.15f %20.15f %20.15f %20.15f\n", i, g(x[i]), x[i], e[i], p[i]);
    }

    printf("\n\n");

////////////////// METODA SIECZNYCH /////////////

x[0] = 3.1;
x[1] = 3.0;
p[0] = p[20] = 0;
x_d = 1.0;
    for(int i=1; i < 21 ; i++)
    {
        x[i+1] = x[i] - ((f(x[i]) * (x[i] - x[i-1]) )/(f(x[i]) - f(x[i-1])));
        e[i+1] = absol(x[i+1] - x_d);
        if(i > 1)
        {
            p[i] = oblicz_p(e[i-1], e[i], e[i+1]);
        }
    printf("%d %20.15f %20.15f %20.15f %20.15f\n", i, f(x[i]), x[i], e[i], p[i]);
    fprintf(f3,"%d %20.15f %20.15f %20.15f %20.15f\n", i, f(x[i]), x[i], e[i], p[i]);
    }

printf("\n\n");


    x[0] = -20.1;
    x[1] = -20.0;
    p[0] = p[20] = 0;
    x_d = -3.284277537306950;
    for(int i=1; i <= 21 ; i++)
    {
        x[i+1] = x[i] - ((g(x[i]) * (x[i] - x[i-1]) )/(g(x[i]) - g(x[i-1])));
        e[i+1] = absol(x[i+1] - x_d);
        if(i > 1)
        {
            p[i] = oblicz_p(e[i-1], e[i], e[i+1]);
        }
    printf("%d %20.15f %20.15f %20.15f %20.15f\n", i, g(x[i]), x[i], e[i], p[i]);
    fprintf(f4,"%d %20.15f %20.15f %20.15f %20.15f\n", i, g(x[i]), x[i], e[i], p[i]);
    }


printf("\n\n");
printf("\n\n");





////////////////////// KONIEC OBLICZEŃ ////////////////////////

fclose(f1);
fclose(f2);
fclose(f3);
fclose(f4);
free(x);
free(e);
free(p);



return 0;
}
