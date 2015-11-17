/* matrix.h:  Our project requires the dynamic allocation and de-allocation
    of 2-D arrays which serve as matrix data structures. This header
    contains the prototypes for functions, implemented in matrix.c, which
    manage this work. Author: Jason Franklin. */


/* matrix_create:  returns a pointer to a dynamically allocated 2-D array
    of int elements with r rows and c columns; note that the elements
    of the array are initially undefined */
int **matrix_create(int r, int c);


/* matrix_destroy:  de-allocates the memory occupied by the matrix of int
    elements referenced by pointer argument m which has rows r and 
    columns c */
void matrix_destroy(int **m, int r, int c);
