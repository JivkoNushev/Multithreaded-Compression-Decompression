#include "binary_tree.h"
#include "print.h"

node_t *init_node(int count, char charr)
{
    node_t *new_node = malloc(sizeof(new_node));
    if(NULL == new_node)
    {
        puts("Couldn't malloc new_node");
        exit(-1);
    }
    new_node->charr = charr;
    new_node->count = count;
    new_node->left = new_node->right = NULL;

    return new_node;
}

void print_node(const node_t * const node);
{
    println("char = %c count = %d", node->charr, node->count);
}

int compare_nodes(const node_t * const first, const node_t * const second);
{
    return second->count - first->count;
}