#include <unistd.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "print.h"

int main(int argc, char const *argv[])
{
    queue_t *q = init_queue();
    q->push_back(q, 5);
    q->push_back(q, 6);
    q->push_back(q, 15);
    float test = 65.36;
   
    q->print(q);

    if( -1 == println("Queue data is: %d", q->data)) exit(-1);
    if( -1 == println("Queue data is: %f", test)) exit(-1);

    if(-1 == q->push_back(q, 6))
    {
        puts("Couldn't add to queue");
        exit(-1);
    }
    

    exit(0);
}
