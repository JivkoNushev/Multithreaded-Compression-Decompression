#ifndef BIN_TREE
#define BIN_TREE

typedef struct binary_tree
{
    int count;
    char charr;
    struct binary_tree *left;
    struct binary_tree *right;
}node_t;

node_t *init_node(int count, char charr);
void print_node(const node_t * const node);
int compare_nodes(const node_t * const first, const node_t * const second);


#endif