#include<bits/stdc++.h>
#include<pthread.h>
#include"buffer.h"
using namespace std;

pthread_mutex_t mutex1;
semaphore sem;
buffer_queue *q;


void *producer(void *param)
{
    
    int count = *(int*)param;//cycles
    buffer_item item;
    for(int i = 0;i<count;i++)
    {
        sem_wait(&sem.empty);


        sleep(1);//wait for one second
        item = rand()%MAX_RAND;
        if(insert_item(q,item)) printf("producer error condition\n");
        else printf("producer produced %d\n",item);

        sem_post(&sem.full);

    }

    
}

void *consumer(void *param)
{
    

    int count = *(int*)param;//cycles
    for(int i = 0;i<count;i++)
    {
        sem_wait(&sem.full);

        sleep(1);//wait for one second
        buffer_item item = q->queue[q->front];
        if(remove_item(q)) printf("consumer error condition\n");
        else printf("consumer consumed %d\n",item);

        sem_post(&sem.empty);
    }
    
}

int main(int argc , char *argv[])
{   
    q = (buffer_queue*)malloc(sizeof(buffer_queue));
    int sleep_time = atoi(argv[1]);
    int producer_number = atoi(argv[2]);
    int consumer_number = atoi(argv[3]);
    /*int sleep_time = 15;
    int producer_number = 5;
    int consumer_number = 5;*/
    pthread_t producer_tid , consumer_tid;
    //initialize lock

    //initialize semaphore and mutex 
    sem_init(&(sem.full),0,0);
    sem_init(&(sem.empty),0,BUFFER_SIZE);
    pthread_mutex_init(&mutex1, NULL);

    //creat threads
    pthread_create(&producer_tid,NULL,producer,(void*)(&producer_number));
    pthread_create(&consumer_tid,NULL,consumer,(void*)(&consumer_number));

    sleep(sleep_time);

    //free up space
    free(q);
    pthread_mutex_destroy(&mutex1);
    sem_destroy(&sem.empty);         //信号量的销毁
	sem_destroy(&sem.full);
    return 0;
}