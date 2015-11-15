//David contribution = !@; Terez Contribution =;Jason Contribution=; think of theese as coment variables to mark our individual contribution for the prof. 
//!@ 
#include<stdlib.h>
#include<stdio.h>

int main ()
{
	int processes;//stores number of processes;
	int resourceType;//stores number of resource types
	printf("Enter the number of processes: ");
	scanf("%d", processes);
	printf("Enter the number of resource types");
	scanf("%d",resourceType);
	int numResources[resourceType];//array for number of resource for each type
	int i=0;//itterations
	while(i<resourceType)//fill aray with the user input
	{
		printf("Available resource for resource number %d \n", i+1)
		scanf("%d",&numResources[i]);
		
	}
}
