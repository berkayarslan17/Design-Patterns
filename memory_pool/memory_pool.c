#include "memory_pool.h"

#define ELEMENT_SIZE 255
#define MAX_ELEMENTS 10

typedef struct
{
    bool is_occupied;
    char memory[ELEMENT_SIZE];
} memory_pool_element_t;

static memory_pool_element_t memory_pool[MAX_ELEMENTS];

void *pool_take(size_t size)
{
    if (size <= ELEMENT_SIZE)
    {
        for (int i = 0; i < MAX_ELEMENTS; i++)
        {
            if (memory_pool[i].is_occupied == false)
            {
                memory_pool[i].is_occupied == true;
                return &(memory_pool[i].memory);
            }
        }
    }
    /// @todo should implement error handling
    return NULL;
}

void pool_release(void *p_args)
{
    for (int i = 0; i < MAX_ELEMENTS; i++)
    {
        if (&(memory_pool[i].memory) == p_args)
        {
            memory_pool[i].is_occupied = false;
            return;
        }
    }
}