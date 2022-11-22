#include "priority_queue.h"

// CREATE a priority queue node
struct priority_queue_node* createPriorityQueueNode(char *symbol, size_t frequency)
{
    struct priority_queue_node* new_node = (struct priority_queue_node*) malloc(sizeof(struct priority_queue_node));
    if(NULL == new_node)
    {
        return NULL;
    }
    new_node->symbol = symbol;
    new_node->frequency = frequency;
    new_node->left_node = new_node->right_node = NULL;

    return new_node;
}

// ADD a new node to a priority queue node
struct priority_queue_node* addToPriorityQueue(struct priority_queue_node *pq, char *symbol, size_t frequency)
{
    if(NULL == pq)
    {
        return NULL;
    }    
    if(NULL == pq->right)
    {
        pq->right = createPriorityQueueNode(symbol, frequency);
        if(NULL == new_node)
        {
            return NULL;
        }
        return pq->right;
    }
    if(NULL == pq->left)
    {
        pq->left = createPriorityQueueNode(symbol, frequency);
        if(NULL == new_node)
        {
            return NULL;
        }
        return pq->left;
    }

    if(NULL != addToPriorityQueue(pq->right, symbol, frequency))
    {
        return pq;
    }

    return NULL;
}

void swapNodes(struct priority_queue_node *first, struct priority_queue_node *second)
{
    size_t temp_frequency = first->frequency;
    first->frequency = second->frequency;
    second->frequency = temp_frequency;

    char *temp_symbol = first->symbol;
    first->symbol = second->symbol;
    second->symbol = temp_symbol;
}

// REARRANGE the queue so to lowest frequency is at the top and the second layer is like binary tree 
struct priority_queue_node* rearrangePriorityQueue(struct priority_queue_node *parent, struct priority_queue_node *child)
{
    if(NULL == parent || child == parent)
    {
        return NULL;
    }
    if(child->frequency < parent->frequency)
    {
        swapNodes(child, parent);
    }

    if(NULL != child->left)
    {
        if (NULL == rearrangePriorityQueue(child, child->left))
        {
            return NULL;
        }
    }
    
    if(NULL != child->right)
    {
        if (NULL == rearrangePriorityQueue(child, child->right))
        {
            return NULL;
        }
    }

    return parent;
}

struct priority_queue_node* createMinHeap(char *input_string)
{
    struct map_t *map = initMap();
    if(NULL == map)
    {
        return NULL;
    }

    for(size_t i = 0; '\0' != input_string[i]; i++)
    {
        if(-1 == addToMap(map, input_string[i]))
        {
            return NULL;
        }
    }

    char *keys = getKeysFromMap(map);
    if(NULL == keys)
    {
        return NULL;
    }

    struct priority_queue_node *pq = createPriorityQueueNode(keys[0], map[keys[0]]);
    if(NULL == pq)
    {
        return NULL;
    }
    char *start = keys;
    for(start; '\0' != start; start++);
    start++;

    while('\0' != start)
    {
        struct priority_queue_node *pq = addToPriorityQueue(pq, keys[0], map[keys[0]]);
        if(NULL == pq)
        {
            return NULL;
        }
        if(NULL == (pq = rearrangePriorityQueue(pq, pq)))
        {
            return NULL;
        }
        
        for(start; '\0' != start; start++);
        start++;
    }

    return pq;
}
