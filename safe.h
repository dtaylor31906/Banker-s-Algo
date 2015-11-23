/* safe.h:  A key sub-task within the Banker's Algorithm is
    determining if a system is in a safe state or an unsafe
    state. This "safety algorithm" is used to determine if resource
    allocation requests from processes or threads can be granted
    without resulting in an unsafe system state. This is the 
    essence of how the Banker's Algorithm achieves deadlock avoidance.
    Author: Jason Franklin. */

/* safe:  return 1 if system state is safe, 0 if system state is 
    unsafe */
int safe(void);
