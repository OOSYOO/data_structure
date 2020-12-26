#include <stdio.h>
#include "sqlist.h"

int main()
{
    printf("hello!\n");

    sqlist *list = sqlist_create();
    if(NULL == list)
    {
     fprintf(stderr, "sqlist_create failed!\n");
     return  -1;
    }

    datatype a1[] = {1, 2, 3, 4, 5};
    datatype a2[] = {8, 7, 6, 5, 4};

    for(int i=0; i<sizeof(a1) / sizeof(*a1); i++)
    {
         if(0 != sqlist_insert(list, 0, &(a1[i])))
         {
             fprintf(stderr, "list insert failed!");
             break;
         }
    }

    sqlist *list2 = sqlist_create();
    if(NULL == list2)
    {
        fprintf(stderr, "sqlist_create failed!\n");
        return  -1;
    }
    for(int i=0; i<sizeof(a2) / sizeof(*a2); i++)
    {
         if(0 != sqlist_insert(list2, 0, &(a2[i])))
         {
             fprintf(stderr, "list insert failed!");
             break;
         }
    }

    sqlist_display(list);
    sqlist_delete(list, 2);
    sqlist_display(list);

    datatype idx_data = 4;
    int idx = sqlist_find(list, &idx_data);
    printf("data 4 idx is : %d\n", idx);


    sqlist_display(list);
    sqlist_display(list2);

    sqlist_union(list, list2);
    sqlist_display(list);


    sqlist_destory(list);
    sqlist_destory(list2);

return 0;
}