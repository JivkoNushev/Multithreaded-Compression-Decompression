#ifndef MAP
#define MAP

#include "linked_list.h"

struct map_t
{
    size_t size;
    struct linked_list_t **container;
};

// CREATE a hashed value from a string index
int hash(char *index);

// CREATE a map
struct map_t* initMap(size_t size);

// DEALLOCATE the map
void freeMap(struct map_t *map);

// SET the value of an index to a new value
int setToMap(struct map_t *map, char *index, size_t value);

// GET the value from an index of the map
int getFromMap(struct map_t *map, char *index);

// GET all keys in the map
char* getKeysFromMap(struct map_t *map);

#endif

