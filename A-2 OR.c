#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void bubblesort(int a[],int n);
void selectionsort(int a[],int n);
int main()
{
int a[10],n,i;
pid_t id;
printf("Enter the number of elements :");
scanf("%d",&n);
printf("\n Enter the elements :");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
id=fork();
printf("%d",id);
switch(id)
{
case -1:printf("\n Error in fork");

break;
case 0:printf("\n Child process id:%d",getpid());
printf("\n My parent process id:%d",getppid());
bubblesort(a,n);
printf("\n I am Orphan..");
break;
default:printf("\n Parent process id:%d",getpid());
bubblesort(a,n);
printf("\n");
sleep(3);
break;
}
return 0;
}
void bubblesort(int a[],int n)
{
int i,j,temp;
for(i=0;i<n;i++)
{
for(j=0;j<n-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
printf("\nAscending order:");
for (i=0;i<n;i++)
{
printf("%d",a[i]);
}
}


