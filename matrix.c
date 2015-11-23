#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

/* matrix.c:  Our project requires the management of matrix and vector 
    data structures. This source file provides the implementations of the
    necessary utilities, which are declared in matrix.h.
    Author: Jason Franklin. */

/* matrix_create:  returns a pointer to a Matrix with r rows and c cols */
Matrix matrix_create(int r, int c)
{
    Matrix result = (Matrix) malloc(r * sizeof(Vector)); 
    if (result == NULL) {
        printf("ERROR: Out of memory\n"); 
        exit(1); 
    }
    int i;
    for (i = 0; i < r; i++) {
        result[i] = (Vector) malloc(c * sizeof(int)); 
        if (result[i] == NULL) {
            printf("ERROR: Out of memory\n"); 
            exit(1); 
        }
    }
    return result; 
}

/* vector_create:  returns a pointer to a Vector of length l */
Vector vector_create(int l) 
{
    return (Vector) malloc(l * sizeof(int)); 
}

/* matrix_destroy:  de-allocate heap space occupied by m */
void matrix_destroy(Matrix m, int r)
{
    int i; 
    for (i = 0; i < r; i++) 
        free(m[i]); 
    free(m); 
}

/* vector_destroy:  de-allocate heap space occupied by v */
void vector_destroy(Vector v) 
{
    free(v); 
}

/* vector_lte:  return 1 if v1 <= v2, 0 if not */
int vector_lte(Vector a, Vector b, int len)
{
    int i; 
    for (i = 0; i < len; i++)
        if (a[i] > b[i]) break; 
    if (i == len)
        return 1; 
    else 
        return 0; 
}
