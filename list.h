#ifndef LIST
#define LIST

typedef struct list
{
    void *data;
    struct list *next;
}list_t;

list_t* init_list_node(void* value);

list_t* add_to_list(list_t* list, void* value);

int has_in_list(list_t* list, void* value);

list_t* remove_from_list(list_t* list, void* value);

#endif