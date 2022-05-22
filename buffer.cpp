#include "buffer.h"

int insert_item(buffer_queue *q , buffer_item buf)
{
    if((q->rear+1)%BUFFER_SIZE == q->front) //queue is full
    {
        return -1;
    }
    else
    {
        q->queue[q->rear] = buf;
        q->rear = (q->rear+1)%BUFFER_SIZE;
        return 0;
    }
}

int remove_item(buffer_queue *q)
{
    if( q->front == q->rear ) //queue if empty
    return -1;
    else
    {
        q->front++;
        return 0;
    }
}