#ifndef BIN_TREE
#define BIN_TREE

typedef struct binary_tree
{
    int count;
    char charr;
    struct binary_tree *left;
    struct binary_tree *right;
}node_t;

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


#endif