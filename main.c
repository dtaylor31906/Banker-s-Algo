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
    /* initialize system state */
    init_state(); 
    return 0; 
}
