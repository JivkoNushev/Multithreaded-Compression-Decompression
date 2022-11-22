#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <err.h>
#include <errno.h>

#include "priority_queue.h"

int main(int argc, char const *argv[])
{
    char input_string[] = "TOBEORNOTTOBE";

    int exit_status = EXIT_SUCCESS;
    do
    {
        struct priority_queue_node *min_heap = createMinHeap(input_string);
        if(NULL == min_heap)
        {
            exit_status = EXIT_FAILURE;
            break;
        }

    } while (0);
    
    if(EXIT_SUCCESS == exit_status)
    {
        return 0;
    }
    err(exit_status, NULL);
    return 0;
}
