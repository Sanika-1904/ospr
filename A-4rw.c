#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
pthread_mutex_t x,wsem;
pthread_t r,w;
int readcount;
int writecount;

void intialize()
{
 pthread_mutex_init(&x,NULL);
 pthread_mutex_init(&wsem,NULL);
 readcount=0;
 writecount=0;
}

void * reader(void * param)
{
 int waittime;
 waittime=rand() % 5;
 printf("\nReader is trying to enter");
 pthread_mutex_lock(&x);
 readcount++;
 if(readcount==1)
  pthread_mutex_lock(&wsem);
 printf("\n\t%d Reader is inside..",readcount);
 pthread_mutex_unlock(&x);
 sleep(waittime);
 pthread_mutex_lock(&x);
 readcount--;
 if(readcount==0)
  pthread_mutex_unlock(&wsem);
 pthread_mutex_unlock(&x);
 printf("\n\t\t%d Reader is Leaving..",readcount+1);
}


void * writer(void * param)
{
 int waittime;
 waittime=rand() % 3;
 printf("\n Writer is trying to enter..");
 writecount++;
 pthread_mutex_lock(&wsem);
 printf("\n%d Writer has entered",writecount);
  sleep(waittime);
  pthread_mutex_unlock(&wsem);
 writecount--;
 printf("\n\t%d Writer is leaving..",writecount+1);
sleep(5);
exit(0);
}

int main()
{
 int n1,n2,i;
 printf("\n Reader/Writer Problem");
 printf("\nEnter the no of readers: ");
 scanf("%d",&n1);
 printf("\nEnter the no of writers: ");
 scanf("%d",&n2);
 for(i=0;i<n1;i++)
  pthread_create(&r,NULL,reader,NULL);
 for(i=0;i<n2;i++)
  pthread_create(&w,NULL,writer,NULL);
 for(i=0;i<n1;i++)
  pthread_join(r,NULL);
 for(i=0;i<n2;i++)
  pthread_join(w,NULL);
 exit(0);
}
 
/*
pc-12@pc12-OptiPlex-3090:~$ gcc A-4rw.c
pc-12@pc12-OptiPlex-3090:~$ ./a.out

 Reader/Writer Problem
Enter the no of readers: 3

Enter the no of writers: 4

Reader is trying to enter
	1 Reader is inside..
Reader is trying to enter
	2 Reader is inside..
Reader is trying to enter
	3 Reader is inside..
 Writer is trying to enter..
 Writer is trying to enter..
 Writer is trying to enter..
 Writer is trying to enter..
		3 Reader is Leaving..
		2 Reader is Leaving..
		1 Reader is Leaving..
4 Writer has entered
	4 Writer is leaving..
3 Writer has entered
	3 Writer is leaving..
2 Writer has entered
	2 Writer is leaving..
1 Writer has entered
	1 Writer is leaving..*/
