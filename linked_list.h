#ifndef LINKED_LIST
#define LINKED_LIST

struct linked_list_t
{
    char *key;
    size_t value;
    struct linked_list_t *next;
};

// CREATE a linked list node
struct linked_list_t* createLinkedList(char *key, size_t value);

// SET the value of the container to the new value
int setToLinkedList(struct linked_list_t* it_container, size_t value);

// DEALLOCATES the list
void freeList(struct linked_list_t* list);

#endif  