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
    return log(pow(x,5) + 3.0*x*x + x + 9.0);
}

double f_2(double x)
{
    return pow(x,6);
}



// ///////////////// KONIEC FUNKCJI ////////////////////////////////////



// //////////// POCZĄTEK INICJALIZACJI //////////////////////////////

int main()
{

    // int N = 100;

//       FILE *f2; 
//       f2=fopen("min_ln_lambda_3.dat", "w");

// double epsilon = pow(10,-6);

// double r = (sqrt(5.0) -1.0)/2.0;

// // double lambda_1 = r*r;
// // double lambda_2 = r;

// double lambda_1 = 1.0/3.0;
// double lambda_2 = 2.0/3.0;

// double x_a = -0.5;
// double x_b = 1.0;

// double x_1 = x_a;
// double x_2 = x_b;

// double x_min;

// double x_dokl = -0.1673198;

// int i=0;

// while(fabs(x_b - x_a) > epsilon)
// {

// x_1 = x_a + lambda_1*(x_b - x_a);
// x_2 = x_a + lambda_2*(x_b - x_a);

// if(f_1(x_1) < f_1(x_2))
//     {
//         x_b = x_2;
//     }
//     else
//     {
//         x_a = x_1;
//     }

// x_min = (x_a + x_b) /2.0;
// i++;
// printf("%f %f %d %f \n",x_a, x_b , i, x_min );
// fprintf(f2, "%d %f %f\n", i, x_min, fabs(x_min - x_dokl));
// }

// printf(" min = %f \n\n", x_min);

// fclose(f2);


      FILE *f2; 
      f2=fopen("min_wielomian_lambda_3.dat", "w");

double epsilon = pow(10,-6);

double r = (sqrt(5.0) -1.0)/2.0;

// double lambda_1 = r*r;
// double lambda_2 = r;

double lambda_1 = 1.0/3.0;
double lambda_2 = 2.0/3.0;

double x_a = -4.0;
double x_b = 1.0;

double x_1 = x_a;
double x_2 = x_b;

double x_min;

double x_dokl = 0.0;

int i=0;

while(fabs(x_b - x_a) > epsilon)
{

x_1 = x_a + lambda_1*(x_b - x_a);
x_2 = x_a + lambda_2*(x_b - x_a);

if(f_2(x_1) < f_2(x_2))
    {
        x_b = x_2;
    }
    else
    {
        x_a = x_1;
    }

x_min = (x_a + x_b) /2.0;
i++;
printf("%f %f %d %f \n",x_a, x_b , i, x_min );
fprintf(f2, "%d %f %f\n", i, x_min, fabs(x_min - x_dokl));
}

printf(" min = %f \n\n", x_min);


fclose(f2);

 

return 0;
}
