#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

queue_t *init_node(int data)
{
    queue_t *q = malloc(sizeof(queue_t));
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
    queue_t *q = malloc(sizeof(queue_t));
    if(0 == q)
    {
        puts("Couldn't allocate a new queue_t");
        return NULL;
    }
    q->next = NULL;
    q->prev = NULL;
    q->data = 0;

    q->push_back = push_back;

    return q; 
}

int push_back(queue_t *q, int data)
{
    queue_t *start = q;
    for(; start != NULL; start = start->next);
    if (start == q) free(start);
    
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