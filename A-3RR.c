#include<stdio.h>
#include<stdlib.h>
int main()
{
int i,j,n,bu[10],wa[10],tat[10],t,ct[10],max;
float awt=0,att=0,temp=0;
//clrscr();
printf("Enter the no of processes:");
scanf("%d",&n);
for (i=0;i<n;i++)
{
printf("\nEnter the Burst Time for process %d:",i+1);
scanf("%d",&bu[i]);
ct[i]=bu[i];
}
printf("\n Enter the size of time slice:");
scanf("%d",&t);
max=bu[0];
for (i=0;i<n;i++)
if(max<bu[i])
max=bu[i];
for(j=0;j<(max/t)+1;j++)
for(i=0;i<n;i++)
if(bu[i]!=0)
if(bu[i]<=t)
{
tat[i]=temp+bu[i];
temp=temp+bu[i];
bu[i]=0;
}
else
{
bu[i]=bu[i]-t;
temp=temp+t;
}
for (i=0;i<n;i++)
{
wa[i]=tat[i]-ct[i];
att+=tat[i];
awt+=wa[i];
}
printf("\n The Average Turn Around Time is:%f",att/n);
printf("\nThe Average Waiting Time is:%f",awt/n);
printf("\n \tPROCESS\tBURST TIME\t WAITING TIME\tTURN AROUNDTIIME\n");
for(i=0;i<n;i++)
printf("\t%d\t%d\t\t%d\t\t%d\n",i+1,ct[i],wa[i],tat[i]);
//getch();
}



/*pc-12@pc12-OptiPlex-3090:~$ gcc A-3RR.c
pc-12@pc12-OptiPlex-3090:~$ ./a.out
Enter the no of processes:5

Enter the Burst Time for process 1:7

Enter the Burst Time for process 2:15

Enter the Burst Time for process 3:12

Enter the Burst Time for process 4:8

Enter the Burst Time for process 5:10

 Enter the size of time slice:4

 The Average Turn Around Time is:41.200001
The Average Waiting Time is:30.799999
 	PROCESS	BURST TIME	 WAITING TIME	TURN AROUNDTIIME
	1	7		16		23
	2	15		37		52
	3	12		35		47
	4	8		27		35
	5	10		39		49
pc-12@pc12-OptiPlex-3090:~$ 

*/
