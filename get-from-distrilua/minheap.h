#ifndef __MINHEAP_H__
#define __MINHEAP_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


struct heapele {
    int32_t index;
};

typedef struct minheap {
    int32_t size;
    int32_t max_size;
    int8_t (*less)(struct heapele *l, struct heapele *r);
    struct heapele **data;
} *minheap_t;

minheap_t minheap_create(int32_t size,
    int8_t (*)(struct heapele *l, struct heapele *r)
);

void minheadp_destroy(minheap_t *m);

typedef void (*clear_func)(struct heapele *h);

void minheap_clear(minheap_t m, clear_func cf);

static inline void minheap_swap(minheap_t m, int32_t idx1, int32_t idx2)
{
    struct heapele *ele = m->data[idx1];
    m->data[idx1] = m->data[idx2];
    m->data[idx2] = ele;
    m->data[idx1]->index = idx1;
    m->data[idx2]->index = idx2;
}

static inline int32_t parent(int32_t idx)
{
    return idx/2;
}

static inline int32_t left(int32_t idx)
{
    return idx*2;
}
static inline int32_t right(int32_t idx)
{
    return idx*2 + 1;
}

static inline void up(minheap_t m, int32_t idx)
{
    printf("up\n");
}
static inline void down(minheap_t m, int32_t idx)
{
    printf("down\n");
}

static inline void minheap_change(minheap_t m, struct heaplele *e)
{
    printf("change\n");
}

static inline void minheap_insert(minheap_t m, struct heapele *e)
{
    printf("insert\n");
}
static inline void minheap_remove(minheap_t m, struct heapele *e)
{
    printf("insert\n");
}

static inline struct heapele * minheap_min(minheap_t m)
{
    printf("min\n");
    return NULL;
}

static inline struct heapele * minheap_popmin( minheap_t m)
{
    printf("popmin\n");
    return NULL;
}
#endif // __MINHEAP_H__
