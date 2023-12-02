#ifndef __MEMORY_POOL_H__
#define __MEMORY_POOL_H__

void *pool_take(size_t size);
void pool_release(void *p_args);

#endif