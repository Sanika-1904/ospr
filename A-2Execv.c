// program 1
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>    
#include <stdlib.h>    
#include <unistd.h>
 
void reversearray(int [10], int n);

void main(int argc, char *argv[], char *envp[]) {
	int i, n = 0;
	int a[10];
	
	for(i=1; argv[i]!=NULL; i++) {		
		a[i] = strtol(argv[i], NULL, 10);
		n++;
	}
	
	printf("\n");	
	printf("\nIn second child process. Process id is :  %d", getpid());
	printf("\nMy parent's process id is : %d", getppid());
	reversearray(a,n);
}

void reversearray(int a[10],int n) {
	int start = 1;
	int end = n-1;
	int temp;
	
	while(start < end) {
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		
		start++;
		end--;
	}
	int i;
	printf("\n Reverse of Array ");
	for(i = 0 ; i < n ; i++) {
		printf("\t %d" , a[i]);
	}
}


//***********************************************************************************************************************
 // Program 2
 
#include <sys/types.h>
#include <stdio.h>    
#include <stdlib.h>    
#include <unistd.h>

void bubblesort(int a[],int n);

pid_t id;

void main() {
	int a[10], n, i;
	char *argv[12];
	for(i=0; i<12; i++) {
		argv[i] = (char *) malloc(20);
	}
	printf("\n\nEnter the number of elements in the array: ");
	scanf("%d", &n);
	printf("Enter the elements: ");
   	for(i=0; i<n; i++) {
     	scanf("%d", &a[i]);
	}
	printf("\nIn Parent process.\nParent process id is : %d", getpid());	
	bubblesort(a,n);
	switch(id = fork()) {
		case -1: printf("\nError in fork.");
				 break;
				
		case 0: printf("\nIn child process.\nChild process id is : %d ", getpid());
				printf("\nParent process id of child process is : %d ", getppid());
				for(i=0; i<n; i++) {
					sprintf(argv[i+1], "%d", a[i]);
				}
				
				argv[0] = "Reverse";
        		argv[n+2] = NULL;
				printf("\n");	        
				execv("Reverse", argv);
				printf("Error");
				break;
				
		default: printf("\nSorted elements: ");
			 	for(i=0;i<n;i++) printf(" %d", a[i]);
			 	printf("\n");
			 	sleep(5);
			 	printf("\nEnd of parent process\n.");		
	}
}

void bubblesort(int a[],int n) {
	int i,j,temp;
	for(i=0; i<n; i++) {
		for(j=0; j<n-1; j++) {
		   if(a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
		   }
		}
	}
	printf("\n");
}
