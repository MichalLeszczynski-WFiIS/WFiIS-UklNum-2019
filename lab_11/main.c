#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include "utilities.h"


// ///////////////// POCZĄTEK FUNKCJI ////////////////////////////////////


double f_0(double t, double omega)
{
    return sin(omega*t) + sin(2.0* omega * t) + sin(3.0* omega*t);
}



double delta()
{
    return rand()/(RAND_MAX + 1.0) - 0.5;
}

double f(double t,double omega)
{
    return f_0(t, omega) + delta();
}

double g(double t, double sigma)
{
    double A = 1.0/(sigma*sqrt(2.0*M_PI));
    double ex = exp((-1.0*t*t )/ (2.0*sigma*sigma));
    return A*ex;
}

// ///////////////// KONIEC FUNKCJI ////////////////////////////////////



// //////////// POCZĄTEK INICJALIZACJI //////////////////////////////

int main()
{

    FILE *f1; 
    f1=fopen("k8.dat", "w");

    FILE *f2; 
    f2=fopen("k10.dat", "w");

    FILE *f3; 
    f3=fopen("k12.dat", "w");



// /////////////////////// OBLICZENIA //////////////////////////

    double a1;
    double a2;
    double b1;
    double b2;



    double N;
    double T = 1.0;
    double t_max = 3*T;
    double dt = t_max/N;
    double sigma = T/20.0;
    double omega = 2.0 * M_PI / T;

    for(int k = 8; k <= 12 ; k+=2)
    {
        double N = pow(2, k);
        double dt = t_max/N;
        

        double* t = (double*)malloc(N*sizeof(double));
        for(int i=0; i < N; i ++)
        {
            t[i] = i*dt;
        }

        double* Af0 = (double*)malloc(2*N*sizeof(double));
        double* Af = (double*)malloc(2*N*sizeof(double));
        double* Ag1 = (double*)malloc(2*N*sizeof(double));
        double* Ag2 = (double*)malloc(2*N*sizeof(double));
        double* splot = (double*)malloc(2*N*sizeof(double));


        for(int i=0; i < N; i++)
        {
            Af0[2*i] = f_0(t[i], omega);
            Af[2*i] = f(t[i], omega);
            Ag1[2*i] = g(t[i], omega);
            Ag2[2*i] = g(t[i], omega);
        }

        for(int i=1; i < 2*N; i+=2 )
        {
            Af0[i] = 0.0;
            Af[i] = 0.0;
            Ag1[i] = 0.0;
            Ag2[i] = 0.0;
        }

        gsl_fft_complex_radix2_forward(Af, 1, N);
        gsl_fft_complex_radix2_forward(Ag1, 1, N);
        gsl_fft_complex_radix2_backward(Ag2, 1, N);


        for(int i=0; i < N; i ++)
        {
            a1 = Af[2*i];
            b1 = Af[2*i + 1];
            a2 = Ag1[2*i] + Ag2[2*i];
            b2 = Ag1[2*i] + Ag2[2*i];
            splot[2*i] = a1*a2 - b1*b2;
            splot[2*i + 1] = a1*b2 + a2*b1;

            
        }

        gsl_fft_complex_radix2_backward(splot, 1, N);

        double fmax = 0.0;
        for(int i=0; i < N; i ++)
        {
            if(fabs(splot[2*i]) > fmax)
            {
                fmax = splot[2*i];
            }
        }



         for(int i=0; i < N; i++)
        {
            switch(k)
            {
                case 8:
                {
                    fprintf(f1, "%f %f %f %f \n", t[i], Af[2*i], Af0[2*i], splot[2*i] * 2.5 / fmax);
                    break;
                }
                case 10:
                {
                    fprintf(f2, "%f %f %f %f\n", t[i], Af[2*i], Af0[2*i], splot[2*i] * 2.5 / fmax);
                    break;
                }

                case 12:
                {
                    fprintf(f3, "%f %f %f %f\n", t[i], Af[2*i], Af0[2*i], splot[2*i] * 2.5 / fmax);
                    break;
                }
            }
        }


        free(Af0);
        free(Af);
        free(Ag1);
        free(Ag2);
        free(splot);

    }



// ////////////////////// KONIEC OBLICZEŃ ////////////////////////

fclose(f1);
fclose(f2);
fclose(f3);


 

return 0;
}
