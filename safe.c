#include "matrix.h"

/* safe.c:  A key sub-task within the Banker's Algorithm is
    determining if a system is in a safe state or an unsafe
    state. This "safety algorithm" is used to determine if resource
    allocation requests from processes or threads can be granted
    without resulting in an unsafe system state. This is the 
    essence of how the Banker's Algorithm achieves deadlock avoidance.
    Author: Jason Franklin. */

/* declare external, global data structures */
extern int NUMBER_OF_PROCESSES; 
extern int NUMBER_OF_RESOURCES; 
extern Vector AVAILABLE;
extern Matrix MAX; 
extern Matrix ALLOCATION; 
extern Matrix NEED;

/* prototypes for helper functions */
Vector finish(void); 
Vector work(void);

/* safe:  return 1 if system state is safe, 0 if system state is 
    unsafe */
int safe(void)
{
    int result = 1; 

    /* create and initialize WORK and FINISH */
    Vector WORK = work();
    Vector FINISH = finish();

    /* establish the existence of a safe sequence */
    int i, j; 
    for (i = 0; i < NUMBER_OF_PROCESSES; i++)
        if (FINISH[i] == 0 && vector_lte(NEED[i], WORK, NUMBER_OF_RESOURCES)) {
            for (j = 0; j < NUMBER_OF_RESOURCES; j++)
                WORK[j] += ALLOCATION[i][j]; 
            FINISH[i] = 1; 
            i = -1; /* after one process "finishes" search for another */
        }
    for (i = 0; i < NUMBER_OF_PROCESSES; i++)
        if (!FINISH[i]) {
            result = 0; /* no safe sequence! */
            break; 
        }

    /* de-allocate heap memory space */
    vector_destroy(WORK);
    vector_destroy(FINISH);

    return result;
}

/* finish:  helper function to create and initialize FINISH vector */
Vector finish(void)
{
    Vector FINISH = vector_create(NUMBER_OF_PROCESSES);
    int i; 
    for (i = 0; i < NUMBER_OF_PROCESSES; i++)
        FINISH[i] = 0; /* 0 represents "false" */
    return FINISH;
}

/* work:  helper function to create and initialize WORK vector */
Vector work(void) 
{
    Vector WORK = vector_create(NUMBER_OF_RESOURCES); 
    int i; 
    for (i = 0; i < NUMBER_OF_RESOURCES; i++)
        WORK[i] = AVAILABLE[i]; 
    return WORK; 
}
