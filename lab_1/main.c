#include </usr/include/gsl/gsl_math.h>
#include </usr/include/gsl/gsl_linalg.h>
#include <stdio.h>

int main()
{



printf("Hello\n");

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
        double war = 1.0/(i+j+2.0);
        gsl_matrix_set(A, i, j, war);
        gsl_matrix_set(A_cpy, i, j, war);
    }
}
gsl_linalg_LU_decomp(A,p,&signum);


for(int k=0;k<n;k++)
{
    for(int i=0;i<n;i++) gsl_vector_set(b,i,0.0);
    gsl_vector_set(b,k,1.0);

    gsl_linalg_LU_solve(A,p,b,x);
    for(int i=0;i<n;i++)
    gsl_matrix_set(B,i,k,gsl_vector_get(x,i));
}



for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        printf("%7.f\t\t",  gsl_matrix_get(B, i, j));
     }printf("\n");
}


for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        printf("%7.f\t\t\t",  gsl_matrix_get(A_cpy, i, j));
     }printf("\n");
}

fo r ( i =0; i<=n ; i ++){
fo r ( j =0; j<=n ; j ++){
A_cpy[ i ] [ j ] = 0 . ; // z e r u j e m y komorke w k t o r e j z a p i s z e m y w a r t o s c
for ( k=0;k<=n ; k++) gsl_matrix_set(C,i,j,gsl_matrix_get(C, i, j)+=gsl_matrix_get(A_cpy, i, k) ∗ gsl_matrix_get(B, k, j); // i l o c z y n s k a l a r n y
}
}

for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        printf("%7.f\t\t\t",  gsl_matrix_get(A_cpy, i, j));
     }printf("\n");
}









    return 0;
}