#include <stdint.h>
#include "max_size_block.h"

uint64_t findMaxBlock(list *head)
{
    size_t size_max = 0;
    uint64_t addr_max = (uint64_t)NULL;

    for(list* p = head; p != NULL; p = p->next){
        if(p->size > size_max){
            size_max = p->size;
            addr_max = p->address;
        }
    }

    return addr_max;
}