#include<stdlib.h>
#include<stdio.h>


/* array that stores the number of available instances of each resource */
int *available; 

/* a 2-D array to store the max resource demand of each process; the rows
    represent the processes and the columns represent the resource type */
int **max;

/* a 2-D array to store the number of instances of each resource allocated
    to each process; rows represent processes */
int **allocation; 

/* a 2-D array indicating the remaining resource need of each process; 
    rows represent processes; if need[i][j] == k, then process i may 
    need up to k more instances of resource j to finish */
int **need; 


int main ()
{
	int processes;
	int resourceType;
	printf("Enter the number of processes: ");
	scanf("%d", processes);
	printf("Enter the number of resource types");
	scanf("%d",resourceType);
	int available[resourceType];
	need[resourceType];
	int i = 0;
    int j = 0;
	
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

//function can be called to calcuate how many resources a process needs to finish and it will calculate that through the allocation matrix and the claim matirx. x is claim matrix and y is the allocation matrix. Need is calculate by claim - allocation. This was just an attempt at the calculation after watching various YouTube videos, so it can be scraped.
// Here i was thinking , have it randomly specify a process through the pointers. Since the CPU has to do this on its own, i was trying to code it to look at one process and its row of resources need at a time, then send the resulting matrix back to another function that will compare it to the available resources matrix. 
//Im still working on it tho. But if its too much ill scrap it.
int calculateNeed (int *x[][], int *y[][]){
	int i,j,k;
//trying to code a loop sequence that iterates it all correctly.

	for (i=0;i<processes;i++){
		for (j=0;j<resourceType;j++){	
			for (k=0;k<sizeof(need);k++){
			need [k] = x[i][j] - y[i][j];
			}
		}
	}
	
	return need;
}
