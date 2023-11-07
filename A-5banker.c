#include <stdio.h>
#include <stdlib.h>
void final_output(int k[][10],int n,int p)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<p;j++)
		{
			printf("%d\t",k[i][j]);
		}
	}
}

void Banker(int A[][10],int N[][10],int M[10][10],int W[1][10],int *n,int*m)
{
	int i,j;
	printf("\nENTER TOTAL NUMBER OF PROCESSES:");
	scanf("%d",&*n);
	printf("\nENTER TOTAL NUMBER OF RESOURECS:");
	scanf("%d",&*m);
	for(i=0;i<*n;i++)
	{
		printf("\n PROCESS %d\n",i+1);
		for(j=0;j<*m;j++)
		{
			printf("ALLOCATION FOR RESOURCES%d:",j+1);
			scanf("%d",&A[i][j]);
			printf("MAXIMUM FOR RESOURCE%d:",j+1);
			scanf("%d",&M[i][j]);
		}
	}
	printf("\n AVAILABLE RESOURCES:\n");
	for(i=0;i<*m;i++)
	{
		printf("RESOURCE%d:",i+1);
		scanf("%d",&W[0][i]);
	}
	
	for(i=0;i<*n;i++)
	for(j=0;j<*m;j++)
	N[i][j]=M[i][j]-A[i][j];
	
	printf("\n********ALLOCATION MATRIX********");
	final_output(A,*n,*m);
	printf("\n********MAXIMUM REQUIREMENT MATRIX********");
	final_output(M,*n,*m);
	printf("\n********NEED MATRIX********");
	final_output(N,*n,*m);
}

int safety(int A[][10],int N[0][10],int B[1][10],int n,int m,int a[])
{
	int i,j,k,x=0,f1=0,f2=0;
	int F[10],W[1][10];
	for(i=0;i<n;i++)
	W[0][i]=B[0][i];
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			if(F[i]==0)
			{
				f2=0;
				for(j=0;j<m;j++)
				{
					if (N[i][j]>W[0][j])
					f2=1;
				}
				if(f2==0 && F[i]==0)
				{
					for(j=0;j<m;j++)
					W[0][j] += A[i][j];
					F[i]=1;
					f1++;
					a[x++]=i;
				}
			}
		}
		if(f1==n)
		return 1;
	}
	return 0;
}
void request(int A[10][10],int N[10][10],int B[10][10],int pid,int K)
{
	int rmat[1][10];
	int i;
	printf("\nENTER ADDITIONAL REQUEST:\n");
	for(i=0;i<K;i++)
	{
		printf("REQUEST THE RESOURCE %d : ", i + 1);
		scanf("%d", &rmat[0][i]);
	}
	for(i=0;i<K;i++)
	if(rmat[0][i]>N[pid][i])
	{
		printf("\n*******Error Encountered*******\n");
	exit(0);
	}
	for(i=0;i<K;i++)
	if(rmat[0][i]>B[0][i])
	{
		printf("\n*******RESOURCE UNAVAILABLE*******\n");
		exit(0);
	}
	
	for(i=0;i<K;i++)
	{
		B[0][i]-=rmat[0][i];
		A[pid][i]+=rmat[0][i];
		N[pid][i]-=rmat[0][i];
	}
}

int banker(int A[][10],int N[][10],int W[1][10],int n,int m)
{
	int i,j,a[10];
	j=safety(A,N,W,n,m,a);
	if(j!=0)
	{
		printf("\n\n");
		printf("\nA SAFETY SEQUENCE HAS BEEN DETECTED.\n");
		for(i=0;i<n;i++)
		printf("P%d",a[i]);
		printf("\n");
		return 1;
	}
	else
	{
		printf("\nDEADLOCK HAS OCCURED.\n");
		return 0;
	}
}

int main()
{
	int All[10][10],Max[10][10],Need[10][10],W[1][10];
	int n,m,pid,c,r;
	printf("\n******DEADLOCK AVOIDANCE USING BANKER'S ALGORITHM******\n");
	Banker(All,Need,Max,W,&n,&m);
	r=banker(All,Need,W,n,m);
	if (r != 0)
	{
	printf("\n Do you want make an additional"
	"request for any of the process ? (1=Yes|0=No)");
	scanf("%d", &c);
		if (c == 1)
		{
		printf("\n Enter process number : ");
		scanf("%d", &pid);
		request(All,Need,W,pid-1,m);
		r = banker(All, Need, W, n, m);
			if(r==0)
			{
				exit(0);
			}
		}
		else
		{
			exit(0);
			return 0;
		}
	}
}

