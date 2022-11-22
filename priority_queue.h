#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

struct priority_queue_node
{
    //TODO: upgrade to multiple symbols
    char *symbol;
    size_t frequency;
    struct priority_queue_node *left;
    struct priority_queue_node *right;
};

// CREATE a priority queue node
struct priority_queue_node* createPriorityQueueNode(char *symbol, size_t frequency);

// ADD a new node to a priority queue node
// FIXME: needs to add to left and right (breadfirstsearch(bfs)); now adds only in the right node
struct priority_queue_node* addToPriorityQueue(struct priority_queue_node *pq, char *symbol, size_t frequency); 

// SWAP two nodes' values 
void swapNodes(struct priority_queue_node *first, struct priority_queue_node *second);

// REARRANGE the queue so to lowest frequency is at the top and the second layer is like binary tree
struct priority_queue_node* rearrangePriorityQueue(struct priority_queue_node *parent, struct priority_queue_node *child);

// CREATE a Min Heap priority queue
// FIXME: multiple symbols instead of one
struct priority_queue_node* createMinHeap(char *input_string);

// DEALLOCATE the priority queue
// TODO: When the option for multiple symbols is added, to add a free to the symbols variable
void freeQueue(struct priority_queue_node *pq);

// PRINT the Priority Queue 
void printPriorityQueue(struct priority_queue_node *pq);

#endif