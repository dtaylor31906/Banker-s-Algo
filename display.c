#include "matrix.h"
#include <stdio.h>

/* display.c:  This source file implements the methods used to display
    the data that describes the simulated system's state. 
    Author: Jason Franklin. */

/* declare global data structures */
extern int NUMBER_OF_PROCESSES; 
extern int NUMBER_OF_RESOURCES; 
extern Vector AVAILABLE;
extern Matrix MAX; 
extern Matrix ALLOCATION; 
extern Matrix NEED;

/* display_allocation:  display the system's allocation matrix */
void display_allocation(void)
{
    /* print title */
    printf("ALLOCATION:\n"); 
    printf("===========\n"); 

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

/* display_need:  display the system's need request matrix */
void display_need(void)
{
    /* print title */
    printf("NEED:\n"); 
    printf("=====\n"); 

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
            printf("| %-3d ", NEED[i][j]); 
        }
        putchar('\n'); 
    }
}

/* display_available:  display the system's available vector */
void display_available(void)
{
    /* print title */
    printf("AVAILABLE:\n"); 
    printf("==========\n"); 

    /* loop control */
    int j; 

    /* print top row of our table */
    for (j = 0; j < NUMBER_OF_RESOURCES - 1; j++) 
        printf(" R%-2d |", j); 
    printf(" R%-2d ", j); 
    putchar('\n');

    /* print separator */
    for (j = 0; j < NUMBER_OF_RESOURCES; j++) 
        printf("------"); 
    putchar('\n'); 

    /* print table elements */
    for (j = 0; j < NUMBER_OF_RESOURCES - 1; j++) 
        printf("  %-2d |", AVAILABLE[j]); 
    printf("  %-2d ", AVAILABLE[j]); 
    putchar('\n');
}
