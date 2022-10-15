#include <unistd.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "print.h"

int main(int argc, char const *argv[])
{
    queue q = init_queue(q);
    q.add(q,5);
    float test = 65.36;
    if( -1 == println("Queue data is: %d", q.data)) exit(-1);
    if( -1 == println("Queue data is: %f", test)) exit(-1);

    if(-1 == q.add(q, 6))
    {
        printf("Couldn't add to queue");
        exit(-1);
    }

    exit(0);
}
