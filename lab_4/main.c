#include <stdlib.h>
#include</usr/include/gsl/gsl_eigen.h>
#include </usr/include/gsl/gsl_math.h>
#include </usr/include/gsl/gsl_linalg.h>
#include <stdio.h>
#include "utilities.h"



//delta kroneckera
double del(int i,int j)
{
    double delta = 0.0;
    if(i==j) delta = 1.0;
    return delta; 
}



int main()
{

int L = 10;
int n = 200;
int N = 1;
double ro;
double x_i;
double deltax = (double)L / (double)(n+1);
double war;


gsl_matrix *A = gsl_matrix_calloc(n,n);
gsl_matrix *B = gsl_matrix_calloc(n,n);

gsl_matrix *evec = gsl_matrix_calloc(n,n);




gsl_vector *eval = gsl_vector_calloc(n);

gsl_eigen_gensymmv_workspace  *w = gsl_eigen_gensymmv_alloc(n);


//  FILE *fp; 
//      fp=fopen("ww_od_alfy.dat", "w");

    
    FILE *fd; 
     fd=fopen("wektory_dla_alfy0.dat", "w");
    FILE *fda; 
      fda=fopen("wektory_dla_alfy100.dat", "w");

double val;

for(int alfa = 0; alfa <=100; alfa +=2)
{

    for(int i =0;i<n;i++)
    {
        x_i = -(double)L/2.0 + deltax*(i + 1);
        ro = 1.0 + 4.0*(double)alfa*x_i*x_i;


        for(int j = 0;j< n ; j++)
        {
            war = (-del(i, j+1) + 2.0*del(i,j)- del(i, j-1))/ (deltax*deltax);
            gsl_matrix_set(A, i, j, war);

            war = (ro/(double)N) * del(i, j);
            gsl_matrix_set(B, i, j, war);
        }
    }



//diagonalizacja
gsl_eigen_gensymmv(A,B,eval,evec,w);

//sortowanie
gsl_eigen_gensymmv_sort(eval,evec, GSL_EIGEN_SORT_ABS_ASC);


// fprintf (fp, "%d ", alfa);
// for(int i=0;i<6;i++)
// {
//    // printf("alfa: %d ww[%d]: %f \n", alfa, i, gsl_vector_get(eval,i));
//     val = sqrt(gsl_vector_get(eval,i));
//     fprintf (fp, "%f ",val); 
// }
// fprintf (fp, "\n");

if(alfa == 0)
{
    for(int i=0;i<n;i++)
    {
         x_i = -(double)L/2.0 + deltax*(i + 1);
        fprintf(fd, "%f ", x_i);
        for(int j=0;j<6;j++)
        {
            fprintf(fd, "%f ", gsl_matrix_get(evec, i, j));
        }
        fprintf(fd, "\n");
    }
}

if(alfa == 100)
{
for(int i=0;i<n;i++)
    {
         x_i = -(double)L/2.0 + deltax*(i + 1);
        fprintf(fda, "%f ", x_i);
        for(int j=0;j<6;j++)
        {
            fprintf(fda, "%f ", gsl_matrix_get(evec, i, j));
        }
        fprintf(fda, "\n");
    }
}



}

fclose (fd);
fclose (fda);
// fclose (fp);

free(A);
free(B);
free(eval);
free(evec);
free(w);


return 0;
}