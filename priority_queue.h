#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

struct priority_queue_node
{
    //TODO: upgrade to multiple symbols
    char *symbol;
    size_t frequency;
    struct priority_queue_node *left_node;
    struct priority_queue_node *right_node;
};

struct priority_queue_node* createPriorityQueue(char *symbol, size_t frequency);

struct priority_queue_node* addToPriorityQueue(struct priority_queue_node *pq, char *symbol, size_t frequency); 

void swapNodes(struct priority_queue_node *first, struct priority_queue_node *second);

struct priority_queue_node* rearrangePriorityQueue(struct priority_queue_node *parent, struct priority_queue_node *child);

struct priority_queue_node* createMinHeap(char *input_string);

#endif