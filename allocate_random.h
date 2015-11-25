/* allocate_random.h:  After the user has entered the parameters 
    characterizing the system state, we must use that information to 
    randomly allocate resources to each process in the system. To 
    allow the user multiple opportunities to examine the function of 
    the Banker's Algorithm, a "restore()" method was added. 
    Author: Jason Franklin. */

/* allocate_random:  use system state information entered by the user
    to randomly allocate resources to each process */
void allocate_random(void); 

/* restore:  restore system state so that no processes possess any 
    resources */
void restore(void);
