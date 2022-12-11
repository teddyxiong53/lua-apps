#include "minheap.h"

minheap_t minheap_create(int32_t size,int8_t (*less)(struct heapele*l,struct heapele*r))
{
    minheap_t m = calloc(1, sizeof(*m));
    m->data = (struct heapele **)calloc(size, sizeof(struct heapele *));
    m->size = 0;
    m->max_size = size;
    m->less = less;
    return m;
}

void minheap_destroy(minheap_t *m)
{
    free(*m);
    *m = NULL;
}

void minheap_clear (minheap_t m, clear_func f)
{
    uint32_t i;
    for (i=1; i<=m->size; i++) {
        //为什么从1开始索引？
        if (f) {
            f(m->data[i]);//这个不是越界了吗？作者写lua写多了？
        }
        m->data[i]->index = 0;
    }
}