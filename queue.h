#ifndef QUEUE
#define QUEUE

#ifndef NULL
#define NULL 0
#endif

typedef struct queue_t
{
    int (*push_back)(struct queue_t*, int);
    
    struct queue_t *next;
    struct queue_t *prev;
    int data;
}queue_t;

queue_t* init_queue();
int push_back(queue_t *q, int data);
queue_t *init_node(int data);

#endif