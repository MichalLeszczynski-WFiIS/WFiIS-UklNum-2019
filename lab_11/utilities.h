#pragma once
#include <math.h>
#include <iostream>
#include <cstdlib>
#include </usr/include/gsl/gsl_errno.h>
#include </usr/include/gsl/gsl_math.h>
#include </usr/include/gsl/gsl_linalg.h>
#include </usr/include/gsl/gsl_fft_complex.h>
void printGSLMatrix(gsl_matrix *M, const char* format = "%.4f ") 
{
   
    for (int i = 0; i < M->size1; i++)
     {
        for (int j = 0; j < M->size2; j++)
        {
            printf(format, gsl_matrix_get(M, i, j));
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}


gsl_matrix* multiplyGSLMatricies(gsl_matrix *A, gsl_matrix *B)
 {

    gsl_matrix *R = gsl_matrix_calloc(A->size1, B->size2);
    if(A->size2 != B->size1) return R;

    const int iMax = A->size1;
    const int jMax = B->size2;
    
    const int kMax = A->size2; // = B->size1; it's the same thing

    double val;

    for(int i = 0; i < iMax; i++) 
    {
        for(int j = 0; j < iMax; j++) 
        {
            val = 0;
            for(int k = 0; k < kMax; k++)
             {
                val += gsl_matrix_get(A, i, k) * gsl_matrix_get(B, k, j);
                gsl_matrix_set(R, i, j, val);
            }

        }
    }

    return R;
}

void saveGSLMatrixToFile(gsl_matrix *A, const char* file_name = "matrix.txt", const char* format = "%.4f ")
 {

    FILE *fp;

    fp = fopen(file_name, "w+");

    for(int i = 0; i < A->size1; i++) 
    {
        for(int j = 0; j < A->size2; j++)
         {
            fprintf(fp, format, gsl_matrix_get(A, i, j));
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");

    fclose(fp);
}

double detOfTriangularMatrix(gsl_matrix *A)
 {

    if(A->size1 != A->size2) return 0.0;

    const int n = A->size1;
    double det = 1;

    for(int i = 0; i < n; i++) det *= gsl_matrix_get(A, i, i);
    return det;
}

double maxElementGSLMatrix(gsl_matrix *M)
 {
   
   double max = gsl_matrix_get(M, 0, 0);
    for (int i = 0; i < M->size1; i++) 
    {
        for (int j = 0; j < M->size2; j++)
         {
        	if(gsl_matrix_get(M, i, j) > max)
        	{
        		max = gsl_matrix_get(M, i, j);
        	} 
        }
    }
	return max;
}