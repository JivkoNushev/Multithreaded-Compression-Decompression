#ifndef LIST
#define LIST

typedef struct list
{
    void *data;
    struct list *next;
}list_t;

list_t* init_list_node(void* value);

// struct list_node_t* add_to_list(struct list_node_t* list, void* value);

// int has_in_list(struct list_node_t* list, void* value);

// struct list_node_t* remove_from_list(struct list_node_t* list, void* value);

#endif