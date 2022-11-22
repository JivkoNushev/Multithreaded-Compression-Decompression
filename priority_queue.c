#include <stdlib.h>

#include "priority_queue.h"
#include "map.h"

struct priority_queue_node* createPriorityQueueNode(char *symbol, size_t frequency)
{
    struct priority_queue_node* new_node = (struct priority_queue_node*) malloc(sizeof(struct priority_queue_node));
    if(NULL == new_node)
    {
        return NULL;
    }
    new_node->symbol = symbol;
    new_node->frequency = frequency;
    new_node->left = new_node->right = NULL;

    return new_node;
}

struct priority_queue_node* addToPriorityQueue(struct priority_queue_node *pq, char *symbol, size_t frequency)
{
    if(NULL == pq)
    {
        return NULL;
    }    
    if(NULL == pq->right)
    {
        pq->right = createPriorityQueueNode(symbol, frequency);
        if(NULL == pq->right)
        {
            return NULL;
        }
        return pq->right;
    }
    if(NULL == pq->left)
    {
        pq->left = createPriorityQueueNode(symbol, frequency);
        if(NULL == pq->left)
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

struct priority_queue_node* rearrangePriorityQueue(struct priority_queue_node *parent, struct priority_queue_node *child)
{
    if(NULL == parent || NULL == child)
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
    struct map_t *map = NULL;
    struct priority_queue_node *pq = NULL;

    int exit_status = 0;
    do
    {
        map = initMap(100);
        if(NULL == map)
        {
            return NULL;
        }

        for(size_t i = 0; '\0' != input_string[i]; i++)
        {
            char symb[2] = {input_string[i], '\0'};

            int symbol_count = getFromMap(map, symb);
            if(-1 == symbol_count)
            {
                exit_status = 1;
                break;
            }
            if(-1 == setToMap(map, symb, symbol_count + 1))
            {
                exit_status = 1;
                break;
            }
        }

        char *keys = getKeysFromMap(map);
        if(NULL == keys)
        {
            exit_status = 1;
            break;
        }
        
        char *it_keys = keys;
        char symb[2] = {*it_keys, '\0'};
        int key_value = getFromMap(map, symb);
        if(-1 == key_value)
        {
            exit_status = 1;
            break;
        }

        pq = createPriorityQueueNode(symb, key_value);
        if(NULL == pq)
        {
            freeMap(map);
            return NULL;
        }
        
        while ('\0' != *it_keys)
        {
            it_keys++;
        }
        it_keys++;

        while('\0' != *it_keys)
        {
            char symb[2] = {*it_keys, '\0'};
            key_value = getFromMap(map, symb);
            if(-1 == key_value)
            {
                exit_status = 1;
                break;
            }
            struct priority_queue_node *pq = addToPriorityQueue(pq, symb, key_value);
            if(NULL == pq)
            {
                exit_status = 1;
                break;
            }
            if(NULL == (pq = rearrangePriorityQueue(pq, pq)))
            {
                exit_status = 1;
                break;
            }
            
            // FIXME: This returns a warning that says: statement with no effect
            // for(it_keys; '\0' != *it_keys; it_keys++);
            // it_keys++;
            while ('\0' != *it_keys)
            {
                it_keys++;
            }
            it_keys++;

        }
    } while (0);

    freeMap(map);

    if(1 == exit_status)
    {
        return NULL;
    }
    return pq;
}

void freeQueue(struct priority_queue_node *pq)
{
    if(NULL == pq)
    {
        return;
    }

    freeQueue(pq->left);
    freeQueue(pq->right);

    free(pq);
}
