#include<stdio.h>
#include<stdlib.h>
void sstf()
{
	int ReadyQueue[100],i,n,TotalHeadMoment=0,initial,count=0;
	printf("Enter the no of request:");
	scanf("%d",&n);
	printf("Enter the sequence:");
	for(i=0;i<n;i++)
	scanf("%d",&ReadyQueue[i]);
	printf("Enter the initial head position:");
	scanf("%d",&initial);
	while(count!=n)
	{
		int min=1000,diff,index;
		for(i=0;i<n;i++)
		{
			diff=abs(ReadyQueue[i]-initial);
			if(min>diff)
			{
				min=diff;
				index=i;
			}
		}
		TotalHeadMoment=TotalHeadMoment+min;
		initial=ReadyQueue[index];
		ReadyQueue[index]=1000;
		count++;
	}
	printf("Total Head Movements are %d",TotalHeadMoment);
}

void scan(){
    int queue[20], n, head, i, j, k, seek = 0, max, diff, temp, queue1[20],
    queue2[20], temp1 = 0, temp2 = 0;

    float avg;
    printf("Enter the max range of disk\n");
    scanf("%d", &max);
    printf("Enter the initial head position\n");
    scanf("%d", &head);
    printf("Enter the size of request\n");
    scanf("%d", &n);
    printf("Enter the queue of disk positions to be read\n");

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        if (temp >= head)
        {
            queue1[temp1] = temp;
            temp1++;
        }
        else
        {
            queue2[temp2] = temp;
            temp2++;
        }
    }
    for (i = 0; i < temp1 - 1; i++)
    {
        for (j = i + 1; j < temp1; j++)
        {
            if (queue1[i] > queue1[j])
            {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }
    for (i = 0; i < temp2 - 1; i++)
    {
        for (j = i + 1; j < temp2; j++)
        {
            if (queue2[i] < queue2[j])
            {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }
    for (i = 1, j = 0; j < temp1; i++, j++)
        queue[i] = queue1[j];
        queue[i] = max;
    for (i = temp1 + 2, j = 0; j < temp2; i++, j++)
        queue[i] = queue2[j];
        queue[i] = 0;
        queue[0] = head;
    for (j = 0; j <= n ; j++)
    {
        diff = abs(queue[j + 1] - queue[j]);
        seek += diff;
        printf(" %d -> %d \n", queue[j],queue[j + 1]);
    }
    printf("Total seek time is %d\n", seek);


}
int main()
{
	int ch;
	int n;
	do
	{
		printf("1-SSTF\n2.Scan");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
		case 1:
			sstf();
			break;
			case 2:
			scan();
			break;
		}
		printf("\n Do you want to continue press y");
		scanf("%d",&n);
	}
	while(n==1);
	return 0;
}






