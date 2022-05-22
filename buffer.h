#ifndef _BUFFER_H_
#define _BUFFER_H_

#include<bits/stdc++.h>
#include<pthread.h>
#include<semaphore.h>
using namespace std;

#define BUFFER_SIZE 10
#define MAX_NUMBER 10
#define MAX_RAND 10

typedef int buffer_item;

/*struct*/
typedef struct
{
    int queue[BUFFER_SIZE] , front = 0, rear = 0;
}buffer_queue;

typedef struct
{
    sem_t full;
    sem_t empty;
}semaphore;

int insert_item(buffer_queue *q , buffer_item buf);
int remove_item(buffer_queue *q);

#endif
