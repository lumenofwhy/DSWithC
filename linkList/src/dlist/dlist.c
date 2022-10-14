#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "dlist.h"

//初始化plist
void InitList(DList plist)
{
    assert(plist != NULL);
    if (plist != NULL)
    {
        return;
    }

    plist->next = NULL;
    plist->prior = NULL;
}

//往plist中头部插入数字val
bool Insert_head(DList plist, ElemType val)
{
    //创建新节点
    DNode* p = (DNode*)malloc(sizeof(DNode));
    assert(p != NULL);
    if (p == NULL)
    {
        return false;
    }
    p->data = val;
    //将p插入到plist的后面
    p->next = plist->next;
    plist->next = p;
    p->prior = plist;

    //第一次插入
    if (p->next != NULL)
    {
        p->next->prior = p;
    }

    return true;
}

//往plist中的尾部插入数字val
bool Insert_tail(DList plist, ElemType val)
{
    DNode* p = (DNode*)malloc(sizeof(DNode));
    assert(p != NULL);
    if (p == NULL)
    {
        return false;
    }
    p->data = val;

    DNode* q;
    for (q = plist; q->next != NULL; q = q->next)
    {
        ;
    }

    //将p插入到q的后面
    p->next = q->next;
    q->next = p;
    p->prior = q;

    return true;
}

//在plist中查找val值,找到返回该节点地址,失败返回NULL
DNode* Search(DList plist, ElemType val)
{
    for (DNode* p = plist->next; p != NULL; p = p->next)
    {
        if (p->data == val)
        {
            return p;
        }
    }
    return NULL;
}

//删除plist中的第一个val
bool DeleteVal(DList plist, ElemType val)
{
    DNode* p = Search(plist, val);
    if (p == NULL)
    {
        return false;
    }

    p->prior->next = p->next;
    if (p->next != NULL)
    {
        p->next->prior = p->prior;
    }

    free(p);

    return true;
}

//判断plist是否为空链表(没有数据节点)
bool IsEmpty(DList plist)
{
    return plist->next == NULL;
}

//获取plist长度,数据节点的个数
int GetLength(DList plist)
{
    int node_count = 0;
    for (DNode* p = plist->next; p != NULL; p = p->next)
    {
        node_count++;
    }

    return node_count;
}

//获取plist链表的pos位置的值
bool GetElem(DList plist, int pos, int* rtval) // rtval:输出参数
{
    if (pos < 0 || pos >= GetLength(plist))
    {
        return false;
    }

    DNode* p = plist->next;
    for (int i = 0; i < pos; p = p->next, i++)
    {
        ;
    }
    *rtval = p->data;

    return true;
}

//获取val的前驱
DNode* Prior(DList plist, ElemType val)
{
    DNode* p = Search(plist, val);
    if (p == NULL)
    {
        return NULL;
    }

    return p->prior;
}

//获取val的后继
DNode* Next(DList plist, ElemType val)
{
    DNode* p = Search(plist, val);
    if (p == NULL)
    {
        return NULL;
    }

    return p->next;
}

//输出plist的所有数据
void Show(DList plist)
{
    for (DNode* p = plist->next; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }

    putchar('\n');
}

//清空数据
void Clear(DList plist)
{
    Destroy(plist);
}

//销毁
void Destroy(DList plist)
{
    DNode* p;
    while (plist->next != NULL)
    {
        p = plist->next;
        plist->next = p->next;
        free(p);
    }
}