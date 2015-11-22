#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

/* init_state:  responsible for reading input from the user and 
    initializing our simulated system state */
void init_state(void)
{
    /* declare external, global data structures */
    extern int NUMBER_OF_PROCESSES; 
    extern int NUMBER_OF_RESOURCES; 
    extern Vector AVAILABLE;
    extern Matrix MAX; 
    extern Matrix ALLOCATION; 
    extern Matrix NEED;

    printf("Banker's Algorithm Simulator!\n"); 
    printf("=============================\n"); 
    printf("Please specify the initial system state.\n"); 

    /* get numbers of processes and resource types */
    printf("    General system-wide parameters...\n"); 
    printf("        No. of Processes > ");
    scanf("%d", &NUMBER_OF_PROCESSES); 
    printf("        No. of Resources > ");
    scanf("%d", &NUMBER_OF_RESOURCES); 

    /* allocate memory for shared data structures */
    AVAILABLE = vector_create(NUMBER_OF_RESOURCES); 
    MAX = matrix_create(NUMBER_OF_PROCESSES, NUMBER_OF_RESOURCES); 
    ALLOCATION = matrix_create(NUMBER_OF_PROCESSES, NUMBER_OF_RESOURCES);
    NEED = matrix_create(NUMBER_OF_PROCESSES, NUMBER_OF_RESOURCES); 

    /* initialize AVAILABLE, MAX, ALLOCATION, and NEED */
    int i, j; 
    printf("    Units available of each resource type...\n");
    for (i = 0; i < NUMBER_OF_RESOURCES; i++) {
        printf("        Resource type %d > ", i + 1);
        scanf("%d", &AVAILABLE[i]); 
    }
    printf("    Maximum resource needs for each process...\n");
    for (i = 0; i < NUMBER_OF_PROCESSES; i++) {
        for (j = 0; j < NUMBER_OF_RESOURCES; j++) {
            printf("        Proc. %d, res. %d > ", i + 1, j + 1);
            scanf("%d", &MAX[i][j]); 
            if (MAX[i][j] > AVAILABLE[j]) {
                printf("        ERROR: Invalid system state specified. ");
                printf("Exiting...\n");
                exit(1);
            }
            ALLOCATION[i][j] = 0; 
            NEED[i][j] = MAX[i][j];
        }
        if (i < NUMBER_OF_PROCESSES - 1)
            printf("        -------------------\n");
    }

    /* notify user of status and wait for the "O.K." to run the system */
    while (getchar() != '\n');
    printf("System initialized. To \"run\" the system, press ENTER.");
    getchar();
}
