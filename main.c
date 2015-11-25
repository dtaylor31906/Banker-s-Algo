#include "allocate_random.h"
#include "display.h"
#include "init_state.h"
#include "matrix.h"
#include "safe.h"
#include <stdlib.h>
#include <stdio.h>

/* main.c: This is the main driver class for this program. 
    Its essential goal is to demonstrate the key function of 
    the Banker's Algorithm: the "safe()" function. The user is
    prompted for a system state and then is given the option
    of "running" the system as many times as desired. Using the
    display.c functions, this driver provides a user-friendly
    terminal interface. Author(s): David Taylor and Terrez Hall. */

/* define global data structures */
int NUMBER_OF_PROCESSES; 
int NUMBER_OF_RESOURCES; 
Vector AVAILABLE;
Matrix MAX; 
Matrix ALLOCATION; 
Matrix NEED;

int main(void)
{
    /* clear terminal screen */
    system("/usr/bin/clear"); 

    /* initialize system state from user input */
    init_state(); 

    /* notify user of status and wait for "O.K." to run the system */
    while (getchar() != '\n');
    printf("System initialized. To \"run\" the system, press ENTER.");
    getchar();

    /* main program loop */
    while (1) {

        /* clear screen */
        system("/usr/bin/clear"); 

        /* allocate resources and display */
        allocate_random(); 
        display_allocation(); putchar('\n'); 
        display_need(); putchar('\n'); 
        display_available(); putchar('\n');

        /* display result of "safe()" */
        if (safe())
            printf("System state: SAFE!\n"); 
        else
            printf("System state: UNSAFE!\n");

        /* prompt user to continue or quit */
        putchar('\n'); 
        printf("Press Ctrl-C to quit. To \"run\" again, press ENTER.");
        getchar();

        /* if continue, restore the system */
        restore();
    }

    /* free dynamically allocated memory, unnecessary here unless user
        interface is altered to allow the code to reach this point */
    vector_destroy(AVAILABLE); 
    matrix_destroy(MAX, NUMBER_OF_PROCESSES); 
    matrix_destroy(ALLOCATION, NUMBER_OF_PROCESSES); 
    matrix_destroy(NEED, NUMBER_OF_PROCESSES); 

    return 0; 
}
