#include <malloc.h>
#include <stdio.h>

#include "queue.h"

queue_t *init_node(int data)
{
    puts("ALo");
    queue_t *q = (queue_t*)malloc(sizeof(queue_t*));
    puts("ALo2");
    if(0 == q)
    {
        puts("Couldn't allocate a new queue_t");
        return NULL;
    }
    q->next = NULL;
    q->prev = NULL;
    q->data = data;

    q->push_back = push_back;

    return q;
}

queue_t* init_queue()
{
    queue_t *q = (queue_t*)malloc(sizeof(queue_t*));
    if(0 == q)
    {
        puts("Couldn't allocate a new queue_t");
        return NULL;
    }
    q->next = NULL;
    q->prev = NULL;
    q->data = 0;

    q->push_back = NULL;

    return q; 
}

int push_back(queue_t *q, int data)
{
    puts("Alo");
    queue_t *start = q;
    if(NULL != q->push_back)
    {
        for(; start != NULL; start++);
    }
    free(start);
    if(NULL == (start = init_node(data)))
        return -1;

    return 0;
}

int push_front(queue_t q, int data)
{
    return 0;
}

int pop_back(queue_t q, int data)
{
    return 0;
}

int pop_front(queue_t q, int data)
{
    return 0;
}