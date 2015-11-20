/* matrix.h:  Our project requires the management of matrix and vector 
    data structures. This header contains the declarations for utilities,
    implemented in matrix.c, which manage this work.
    Author: Jason Franklin. */

/* Matrix:  pointer to a 2-D array of int variables */
typedef int **Matrix; 

/* Vector: pointer to an array of int variables */
typedef int *Vector; 

/* matrix_create:  returns a pointer to a Matrix with r rows and c cols */
Matrix matrix_create(int r, int c);

/* vector_create:  returns a pointer to a Vector of length l */
Vector vector_create(int l); 

/* matrix_destroy:  de-allocate heap space occupied by m */
void matrix_destroy(Matrix m, int r);

/* vector_destroy:  de-allocate heap space occupied by v */
void vector_destroy(Vector v); 
