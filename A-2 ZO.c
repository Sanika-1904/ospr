#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void bubblesort(int a[],int n);

int main()
{
  int a[10],n,i;
  pid_t id;
  printf("Enter the number of elements : ");
  scanf("%d",&n);
  printf("\nEnter the elements : ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  id = fork();
  printf("%d",id);
  switch(id)
  {
   case -1 : printf("\nError in Fork");
   break;
   case 0 : printf("\nChild process ID :%d",getpid());
   	printf("\nMy Parent Process ID :%d",getppid());
        bubblesort(a,n);
        printf("\nI am Zombie...");
            break;
   default : printf("\nParent process ID :%d",getpid());
   	bubblesort(a,n);
   	printf("\n");
   	sleep(3);
   while(1)
   {
   
   
   }
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
 printf("\nAscending order : ");
 for(i=0;i<n;i++)
 {
  printf("%d ",a[i]);
 }

}


