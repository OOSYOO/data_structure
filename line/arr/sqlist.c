#include "sqlist.h"
#include <stdlib.h>

#define RETURN_IF_NULL(x) \
        if(NULL == x)     \
        return -1;

sqlist *sqlist_create()
{
    sqlist *me = malloc(sizeof(sqlist));
    if(NULL == me)
        return me;

    me->last = -1;

    return me;
}

void sqlist_create2(sqlist **ptr)
{
    *ptr = sqlist_create();
}

int sqlist_destory(sqlist *me)
{
    RETURN_IF_NULL(me);

    me->last = -1;
    free(me);

    return 0;
}

int sqlist_insert(sqlist *me, int i, datatype *data)
{
    RETURN_IF_NULL(me);
    RETURN_IF_NULL(data);

    //检查是否越界
    if(i >= me->last-1 && i>0)
        return -1;

    if(me->last >= DATASIZE)
        return -1;

    //插入
    for(int j=me->last; j>=i; j--)
    {
        me->data[j+1] = me->data[j];
//        printf("%d -> %d\n", j, j+1);
    }
//    printf("====\n");

    me->data[i] = *data;
    me->last++;
    return 0;
}

int sqlist_delete(sqlist *me, int i)
{
    RETURN_IF_NULL(me);

    if(i > me->last)
    {
        fprintf(stderr, "out of border!\n");
        return -1;
    }

    for(int j=i; j<me->last; j++)
    {
        me->data[j] = me->data[j+1];
    }
    me->last--;

    return 0;
}

int sqlist_find(sqlist *me, datatype *data)
{
    RETURN_IF_NULL(me);
    RETURN_IF_NULL(data);

    for(int i=0; i<=me->last; i++)
    {
        if(me->data[i] == *data)
            return i;
    }

    return -2;
}

int sqlist_isempty(sqlist *me)
{
    RETURN_IF_NULL(me);

    if(me->last < 0)
        return 1;

    return 0;
}

int sqlist_setempty(sqlist *me)
{
    RETURN_IF_NULL(me);

    me->last = -1;

    return 0;
}

int sqlist_union(sqlist *list1, sqlist *list2)
{
    RETURN_IF_NULL(list1);
    RETURN_IF_NULL(list2);

    int ret = 0;

    for(int i=0; i<=list2->last; i++)
    {
        if(sqlist_find(list1, &(list2->data[i])) < 0)
        {
            ret = sqlist_insert(list1, 0, &(list2->data[i]));
            if(ret < 0)
                break;
        }
    }

    return ret;
}

int sqlist_display(sqlist *me)
{
    RETURN_IF_NULL(me);

    for(int i=0; i<=me->last; i++)
    {
        printf("%d ", me->data[i]);
    }
    printf("\n");

    return 0;
}
