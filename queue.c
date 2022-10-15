#include "queue.h"

#ifndef NULL
#define NULL 0
#endif

queue init_queue(queue q)
{
    q.next = NULL;
    q.prev = NULL;
    q.data = 0;
    q.add = push_back;

    return q;
}

int push_back(queue q, int data)
{
    return 0;
}
