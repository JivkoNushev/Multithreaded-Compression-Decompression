#ifndef QUEUE
#define QUEUE

typedef struct queue
{
    int (*add)(struct queue, int);
    
    struct queue *next;
    struct queue *prev;
    int data;
}queue;

queue init_queue(queue q);
int push_back(queue q, int data);

#endif