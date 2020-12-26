#pragma once
/*
 * 顺序存储线性表
 * 实现如下功能：
 *  1 创建
 *  2 销毁
 *  3 插入
 *  4 删除
 *  5 查询
 *  6 是否为空
 *  7 设置为空
 *  8 合并
 */

#include <stdio.h>

#define DATASIZE 1024
typedef int datatype;

typedef struct node_st
{
    datatype data[DATASIZE];
    int last;
}sqlist;


sqlist *sqlist_create();

void sqlist_create2(sqlist **ptr);

int sqlist_destory(sqlist *me);

int sqlist_insert(sqlist *me, int i, datatype *data);

int sqlist_delete(sqlist *me, int i);

int sqlist_find(sqlist *me, datatype *data);

int sqlist_isempty(sqlist *me);

int sqlist_setempty(sqlist *me);

int sqlist_union(sqlist *list1, sqlist *list2);

int sqlist_display(sqlist *me);

