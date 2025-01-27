#include <stdint.h>
#include "sum_mem.h"

size_t totalMemoryUsage(list *head)
{
    uint64_t size_sum = 0;

    for(list* p = head; p != NULL; p = p->next){
        size_sum += p->size;
    }

    return size_sum ;
}