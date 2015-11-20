//David contribution = !@; Terez Contribution = *TH;Jason Contribution=; think of theese as coment variables to mark our individual contribution for the prof. 
//!@ 
#include<stdlib.h>
#include<stdio.h>

int need []; // Globally allocated so it can be sized with users input of number of resource types;


int main ()
{
	int processes;//stores number of processes;
	int resourceType;//stores number of resource types
	printf("Enter the number of processes: ");
	scanf("%d", processes);
	printf("Enter the number of resource types");
	scanf("%d",resourceType);
	int available[resourceType];//array for number of resource for each type
	need[resourceType];//just added this allocation in for the function.
	int i=0;int j=0;//itterations
	
	while(i<resourceType)//fill aray with the user input
	{
		printf("Available resource for resource number %d \n", i+1)
		scanf("%d",&available[i]);
	}
	int maxNum[processes][resourceType];//stores the maximum number of resources for each resource
	for(i=0;i<processes;i++)
	{
		

		for(j=0;j<resourceType;j++)
		{
			printf("Enter max number of resource %d for  Process%d",j+1,i+1);
			scanf("%d",maxNum[i][j]);
		}
	}


//*TH

	int allocation[processes][resourceType];//this matrix will store the users input of the resources to be already allocated to the each process.
	for (i=0;i<processes;i++){
		for(j=0;j<resourceType;j++){
			printf("Enter the number of resource %d for Process %d : ", j, i);
			scanf("%d", allocation[i][j]);
		}

	}

	int claim[processes][resourceType]; //This matrix will be used in calculating how many more instances of each resource is needed to complete each individual process. It will hold the number of resources that each process will request for completetion. This input will be supplied by the user.
	
	for (i=0;i<processes;i++){
		for(j=0;j<resourceType;j++){
			printf("Enter the number of resource %d for Process %d   to complete : ", j, i);
			scanf("%d", claim[i][j]);
		}

	}
}

void int calculateNeed (int *x[][], int *y[][]){
	int i,j;
//For loop below will calculate the amount of each resource a need process needs to finish.

	for (i=0;i<processes;i++){
		for (j=0;j<resourceType;j++){	
			for (k=0;k<sizeof(need);k++){
			need [i][j] = x[i][j] - y[i][j];
			}
		}
	}
/*For loop will check the entire need matrix and if the condition in the if statement is true, the system is currently
in an unsafe state. If the condition is not met then the system is in a safe state and execute a process.
*/
	for (i=0;i<processes;i++){
		for (j=0;j<resourceType;j++){
			if (need[i][j] > available [j]){
				printf("The system is in an unsafe state.");
			} else {
				printf("The system is in a safe state. Process %d is executing...");
				//Code for process execution goes here or in another function
				//Currently working on that
			}
		}
	
	}
}

