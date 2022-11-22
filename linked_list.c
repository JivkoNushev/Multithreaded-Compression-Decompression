#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "string.h"

struct linked_list_t* createLinkedList(char *key, size_t value)
{
    struct linked_list_t *new_list_node = (struct linked_list_t *) malloc(sizeof(struct linked_list_t));
    if(NULL == new_list_node)
    {
        return NULL;
    }

    if(NULL == (new_list_node->key = strcpy_(new_list_node->key, key)))
    {
        return NULL;
    }
    new_list_node->value = value;
    new_list_node->next = NULL;

    return new_list_node;
}

int setToLinkedList(struct linked_list_t* it_container, size_t value)
{
    if(NULL == it_container)
    {
        puts("Container is NULL: Can't add\n");
        return -1;
    }

    return it_container->value = value;
}

void freeList(struct linked_list_t* list)
{
    if(NULL == list)
    {
        return;
    }
    freeList(list->next);
    
    free(list->key);
    free(list);
}
