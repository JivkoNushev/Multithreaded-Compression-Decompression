#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "linked_list.h"
#include "string.h"

int hash(char *index)
{
    int hashed_value = 0;
    for(size_t i = 0; '\0' != index[i]; i++)
    {
        hashed_value += index[i];
    }

    return hashed_value;
}

struct map_t* initMap(size_t size)
{
    struct map_t *new_map = (struct map_t *) malloc(sizeof(struct map_t));
    if(NULL == new_map)
    {
        return NULL;
    }

    new_map->size = size;
    new_map->container = (struct linked_list_t**) malloc(sizeof(struct linked_list_t *) * size);
    if(NULL == new_map->container)
    {
        return NULL;
    }

    return new_map;
}

void freeMap(struct map_t *map)
{

    for (size_t i = 0; i < map->size; i++)
    {
        struct linked_list_t *it_container = map->container[i];
        freeList(it_container);
    }
}

int setToMap(struct map_t *map, char *index, size_t value)
{
    size_t index_i = hash(index) % map->size;
    if(NULL == map->container[index_i])
    {
        map->container[index_i] = createLinkedList(index, value);
        if (NULL == map->container[index_i])
        {
            return -1;
        }

        return value;
    }

    struct linked_list_t* it_container = map->container[index_i];
    while(it_container->key != index)
    {
        if(NULL == it_container->next)
        {
            it_container->next = createLinkedList(index, value);
            if (NULL == it_container->next)
            {
                return -1;
            }
            return value;
        }
        it_container = it_container->next;
    }

    if(-1 == setToLinkedList(it_container, value))
    {
        return -1;
    }

    return value;
}

int getFromMap(struct map_t *map, char *index)
{
    struct linked_list_t *it_container = map->container[hash(index) % map->size];
    if(NULL == it_container)
    {
        printf("The key '%s' doesn't exist in the container\n", index);
        return -1;
    }

    while(it_container->key != index)
    {
        if(NULL == it_container->next)
        {
            printf("The key '%s' doesn't exist in the container\n", index);
            return -1;
        }
        it_container = it_container->next;
    }

    return it_container->value;
}

char* getKeysFromMap(struct map_t *map)
{
    char *keys = 0;

    for(size_t i = 0; i < map->size; i++)
    {
        struct linked_list_t *it_container = map->container[i];
        while (NULL != it_container)
        {
            if(NULL == (keys = strcat_(keys, it_container->key)))
            {
                return NULL;
            }
            it_container = it_container->next;
        }
    }

    if(NULL == (keys = strcat_(keys, "\0")))
    {
        return NULL;
    }
    return keys;
}