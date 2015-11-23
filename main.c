#include "init_state.h"
#include "matrix.h"
#include "safe.h"
#include <stdlib.h>
#include <stdio.h>

/* TODO: Put descriptive comment here! */

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

    /* TEST to see if safe() runs as expected; no 
        resources have been allocated or requested yet, so 
        safe should return 1 */
    if (safe())
        printf("System state is safe!\n"); 
    else
        printf("System state is unsafe!\n");

    /* free dynamically allocated memory */
    vector_destroy(AVAILABLE); 
    matrix_destroy(MAX, NUMBER_OF_PROCESSES); 
    matrix_destroy(ALLOCATION, NUMBER_OF_PROCESSES); 
    matrix_destroy(NEED, NUMBER_OF_PROCESSES); 

    return 0; 
}
