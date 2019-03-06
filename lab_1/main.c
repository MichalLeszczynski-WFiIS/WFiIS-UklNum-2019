#include </usr/include/gsl/gsl_math.h>
#include </usr/include/gsl/gsl_linalg.h>
#include <stdio.h>
#include "utilities.h"


int main()
{




int n = 4;
int signum;
gsl_matrix *A = gsl_matrix_calloc(n,n);
gsl_matrix *A_cpy = gsl_matrix_calloc(n,n);
gsl_matrix *C = gsl_matrix_calloc(n,n);

gsl_matrix *B = gsl_matrix_calloc(n,n);
gsl_vector *b = gsl_vector_calloc(n);
gsl_vector *x = gsl_vector_calloc(n);
gsl_permutation *p = gsl_permutation_calloc(n);


//wypelnia macierz a
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        double war = 1.0/((double)i+(double)j+2.0);
        gsl_matrix_set(A, i, j, war);
        gsl_matrix_set(A_cpy, i, j, war);
    }
}
printf("\n A \n ");
printGSLMatrix(A, "%7.7f\t");


gsl_linalg_LU_decomp(A,p,&signum);


printf("\n A \n ");
printGSLMatrix(A, "%7.7f\t");


printf("det(U) = %g",detOfTriangularMatrix(A));

printf("\n A_cpy \n ");
printGSLMatrix(A_cpy, "%7.7f\t");


for(int k=0;k<n;k++)
{
    for(int i=0;i<n;i++) gsl_vector_set(b,i,0.0);
    gsl_vector_set(b,k,1.0);

    gsl_linalg_LU_solve(A,p,b,x);
    for(int i=0;i<n;i++)
    gsl_matrix_set(B,i,k,gsl_vector_get(x,i));
}


printf("\n B \n ");
printGSLMatrix(B, "%9.f\t");
C =  multiplyGSLMatricies(A_cpy, B);

printf("\n C \n "); 
printGSLMatrix(C, "%10.g\t");

printf("\n\nKappa = %f \n\n", maxElementGSLMatrix(A_cpy) * maxElementGSLMatrix(B));






    return 0;
}
