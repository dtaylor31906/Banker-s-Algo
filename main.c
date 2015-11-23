#include "init_state.h"
#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

/* define global data structures */
int NUMBER_OF_PROCESSES; 
int NUMBER_OF_RESOURCES; 
Vector AVAILABLE;
Matrix MAX; 
Matrix ALLOCATION; 
Matrix NEED;

int main(void)
{
    /* initialize system state from user input */
    init_state(); 

    /* free dynamically allocated memory */
    vector_destroy(AVAILABLE); 
    matrix_destroy(MAX, NUMBER_OF_PROCESSES); 
    matrix_destroy(ALLOCATION, NUMBER_OF_PROCESSES); 
    matrix_destroy(NEED, NUMBER_OF_PROCESSES); 

    return 0; 
}
