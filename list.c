#include "list.h"

list_t* init_list_node(void* value)
{
    list_t *new_list_node = malloc(sizeof(list_t));
    if(NULL == new_list_node)
    {
        puts("Can't malloc new_list_node");
        exit(-1);
    }
    new_list_node->data = value;
    new_list_node->next = NULL;

    return new_list_node;
}

list_t* add_to_list(list_t* list, void* value)
{
    list* new_list = init_list_node(value);
    new_list->next = list;

    return new_list;
}

int has_in_list(list_t* list, void* value)
{
    for(list *it = list; NULL != it; it = it->next)
    {
        if(it->data == value)
        {
            return 1;
        }
    }
    return 0;
}

list_t* remove_from_list(list_t* list, void* value)
{
    list *prev = list, *tmp;
    for(list *it = list; NULL != it; prev = it, it = it->next)
    {
        if(it->data == value)
        {
            tmp = prev->next = it->next;
            free(it);
            break;
        }
    }
    if(NULL == list)
        return tmp;
    return list;
}
