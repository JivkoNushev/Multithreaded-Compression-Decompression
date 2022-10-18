#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#include "queue.h"
#include "print.h"

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
    q->print = print;
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
    q->print = print;

    return q; 
}

int push_back(queue_t *q, int data)
{
    queue_t *start = q;
    for(; start != NULL; start = start->next);
    if (start == q) free(q);
    
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

void print(queue_t *q)
{
    for(queue_t *it = q; NULL != it; it = q->next)
    {
        if(-1 == println("Item %d: %d", it - q, it->data))
        {
            puts("Couldn't print queue");
            exit(-1);
        }
    }
}