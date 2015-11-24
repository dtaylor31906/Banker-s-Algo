#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* allocate_random.c:  After the user has entered the parameters 
    characterizing the system state, we must use that information to 
    randomly allocate resources to each process in the system. The 
    purpose of this is to give us a fully specified "snapshot" of the 
    system at runtime on which we can run the "safe()" algorithm, which
    is the essence of the Banker's Algorithm. This demonstrates the 
    mechanism by which the Banker's Algorithm successfully avoids
    deadlock. Author: Jason Franklin. */

/* declare external, global data structures */
extern int NUMBER_OF_PROCESSES; 
extern int NUMBER_OF_RESOURCES; 
extern Vector AVAILABLE;
extern Matrix MAX; 
extern Matrix ALLOCATION; 
extern Matrix NEED;

/* allocate_random:  use system state information entered by the user
    to randomly allocate resources to each process */
void allocate_random(void)
{
    /* seed the random number generator */
    srand(time(NULL)); 

    /* declare control variables */
    int i, j; 

    /* find total number of available resource instances */
    int total_available = 0; 
    for (i = 0; i < NUMBER_OF_RESOURCES; i++) {
        total_available += AVAILABLE[i];
    }

    /* find the total max need of all processes */
    int total_max = 0; 
    for (j = 0; j < NUMBER_OF_PROCESSES; j++) { 
        for (i = 0; i < NUMBER_OF_RESOURCES; i++)
            total_max += MAX[i][j];
    }

    /* choose a random number of resource instances to allocate */
    int limit = (total_available < total_max) ? total_available : total_max; 
    int to_allocate = rand() % (limit + 1);

    /* TODO: Figure out why program sometimes hangs here. */

    /* randomly allocate resource instances to processes; use the 
        "darts at a dartboard" approach */
    while (to_allocate > 0) {
        i = rand() % NUMBER_OF_PROCESSES;
        j = rand() % NUMBER_OF_RESOURCES; 
        if (AVAILABLE[j] > 0 && NEED[i][j] > 0) {
            --AVAILABLE[j]; 
            ++ALLOCATION[i][j]; 
            --NEED[i][j]; 
            --to_allocate;
        }
    }
}

/* restore:  restore system state so that no processes possess any 
    resources */
void restore(void) 
{
    /* STUB */
}

/* display_allocation:  display the system's allocation matrix */
void display_allocation(void)
{
    int i, j; 

    /* print top row of our table */
    printf("     "); 
    for (i = 0; i < NUMBER_OF_RESOURCES; i++) 
        printf("| R%-2d ", i); 
    putchar('\n'); 

    /* print separator */
    printf("------");
    for (i = 0; i < NUMBER_OF_RESOURCES; i++) 
        printf("------"); 
    putchar('\n'); 

    /* print rows */
    for (i = 0; i < NUMBER_OF_PROCESSES; i++) {
        printf("Pr%-2d ", i); 
        for (j = 0; j < NUMBER_OF_RESOURCES; j++) {
            printf("| %-3d ", ALLOCATION[i][j]); 
        }
        putchar('\n'); 
    }
}
