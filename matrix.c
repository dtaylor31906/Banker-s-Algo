#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>


/* matrix.c:  Our project requires the dynamic allocation and de-allocation
    of 2-D arrays which serve as matrix data structures. The functions
    in this source file manage the work of creating and destroying our
    2-D arrays. Author: Jason Franklin. */


/* matrix_create:  returns a pointer to a dynamically allocated 2-D array
    of int elements with r rows and c columns; note that the elements
    of the array are initially undefined */
int **matrix_create(int r, int c) 
{
    int **result = (int **) malloc(r * sizeof(int *)); 
    if (result == NULL) {
        printf("ERROR: Out of memory\n"); 
        exit(1); 
    }
    int i;
    for (i = 0; i < r; i++) {
        result[i] = (int *) malloc(c * sizeof(int)); 
        if (result[i] == NULL) {
            printf("ERROR: Out of memory\n"); 
            exit(1); 
        }
    }
    return result; 
}


/* matrix_destroy:  de-allocates the memory occupied by the 2-D array of 
    int elements referenced by pointer argument m which has rows r */
void matrix_destroy(int **m, int r)
{
    int i; 
    for (i = 0; i < r; i++) 
        free(m[i]); 
    free(m); 
}
