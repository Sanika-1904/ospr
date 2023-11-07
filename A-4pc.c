                                                 
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/types.h>
#include<unistd.h>

void *consumer();
void *producer();

pthread_t p,c;
sem_t empty,full;
pthread_mutex_t mutex;
pthread_attr_t attr;
int counter=0;
int buffer[5];

void init()
{
 pthread_attr_init(&attr);
 sem_init(&full,0,0);
 sem_init(&empty,0,5);
 pthread_mutex_init(&mutex,NULL);
}

int main()
{
 int np,nc,i;
 init();
 printf("Enter number of producer\n");
 scanf("%d",&np);
 printf("Enter number of consumers\n");
 scanf("%d",&nc);
 
 for(i=0;i<np;i++)
 {
  pthread_create(&p,&attr,producer,NULL);
 }
 
 for(i=0;i<nc;i++)
 {
  pthread_create(&c,&attr,consumer,NULL);
 }
 
 for(i=0;i<np;i++)
  pthread_join(p,NULL);
  
 for(i=0;i<nc;i++)
  pthread_join(c,NULL);
  return 0;
}

void *producer()
{
 int item=rand()%100;
 if(counter>=5)
  printf("Buffer full..Error\t\n");
  
  sem_wait(&empty);
  pthread_mutex_lock(&mutex);
  
  if(counter<5)
  {
   buffer[counter]=item;
   counter++;
   printf("Producer produced %d\n",item);
  }
  pthread_mutex_unlock(&mutex);
  sem_post(&full);
 sleep(1);
 pthread_exit(0);
}

void *consumer()
{
 int item;
 if(counter==0)
 {
  printf("Buffer empty..Error\t \n");
  return 0;
 }
 sem_wait(&full);
 pthread_mutex_lock(&mutex);
 if(counter>0)
 {
  item=buffer[counter-1];
  counter--;
  printf("Consumer consumed %d\n",item);
 }
 
 pthread_mutex_unlock(&mutex);
 sem_post(&empty);
sleep(1);
pthread_exit(0);
}
 
 


/*OUTPUT:

pc-31@pc31-Veriton-M200-A58:~$ gcc pc.c
pc-31@pc31-Veriton-M200-A58:~$ ./a.out
Enter number of producer
4
Enter number of consumers
3
Producer produced 83
Producer produced 86
Producer produced 77
Producer produced 15
Consumer consumed 15
Consumer consumed 77
Consumer consumed 86

pc-31@pc31-Veriton-M200-A58:~$ gcc pc.c
pc-31@pc31-Veriton-M200-A58:~$ ./a.out
Enter number of producer
7
Enter number of consumers
3
Producer produced 83
Producer produced 86
Producer produced 77
Producer produced 15
Producer produced 93
Buffer full..Error	
Buffer full..Error	
Consumer consumed 93
Producer produced 35
Consumer consumed 35
Producer produced 86
Consumer consumed 86

pc-31@pc31-Veriton-M200-A58:~$ gcc pc.c
pc-31@pc31-Veriton-M200-A58:~$ ./a.out
Enter number of producer
3
Enter number of consumers
4
Producer produced 83
Producer produced 86
Producer produced 77
Consumer consumed 77
Consumer consumed 86
Consumer consumed 83
Buffer empty..Error

pc-31@pc31-Veriton-M200-A58:~$ gcc pc.c
pc-31@pc31-Veriton-M200-A58:~$ ./a.out
Enter number of producer
0
Enter number of consumers
4
Buffer empty..Error	
Buffer empty..Error	
Buffer empty..Error	
Buffer empty..Error	 	*/
