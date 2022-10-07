#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "clist.h"

//初始化plist
void InitList(CList plist)
{
    assert(plist != NULL);
    if (plist == NULL)
    {
        return;
    }
    plist->next = plist;
}

//往plist中头部插入数字val
bool Insert_head(CList plist, ElemType val)
{
    CNode* p = (CNode*)malloc(sizeof(CNode));
    assert(p != NULL);
    if (p == NULL)
    {
        return false;
    }
    // 把数据存放进新节点
    p->data = val;
    // 把新节点插入到头节点后面
    p->next = plist->next;
    plist->next = p;

    return true;
}

//往plist中的尾部插入数字val
bool Insert_tail(CList plist, ElemType val)
{
    CNode* p = (CNode*)malloc(sizeof(CNode));
    assert(p != NULL);
    if (p == NULL)
    {
        return false;
    }
    p->data = val;

    //找到尾节点
    CNode* q;
    for (q = plist; q->next != plist; q = q->next)
    {
        ;
    }

    p->next = q->next;
    q->next = p;

    return true;
}

//在plist中查找val值,找到返回该节点地址,失败返回NULL
CNode* Search(CList plist, ElemType val)
{
    for (CNode* p = plist->next; p != plist; p = p->next)
    {
        if (p->data == val)
        {
            return p;
        }
    }
    return NULL;
}

//删除plist中的第一个val
bool DeleteVal(CList plist, ElemType val)
{
    CNode* p = Prior(plist, val);
    if (p == NULL)
    {
        return false;
    }

    CNode* q = p->next;
    p->next = q->next;
    free(q);

    return true;
}

//判断plist是否为空链表(没有数据节点)
bool IsEmpty(CList plist)
{
    return plist->next == plist;
}

//获取plist长度,数据节点的个数
int GetLength(CList plist)
{
    int node_count = 0;
    for (CNode* p = plist->next; p != plist; p = p->next)
    {
        node_count++;
    }

    return node_count;
}

//获取plist链表的pos位置的值
// int GetElem(CList plist, int pos); //设计有误：无法清晰表示出错
bool GetElem(CList plist, int pos, int* rtval)
{
    if (pos < 0 || pos >= GetLength(plist))
    {
        return false;
    }

    CNode* p = plist->next;
    for (int i = 0; i < pos; i++)
    {
        p = p->next;
    }

    *rtval = p->data;

    return true;
}

//获取val的前驱
CNode* Prior(CList plist, ElemType val)
{
    for (CNode* p = plist; p->next != plist; p = p->next)
    {
        if (p->next->data == val)
        {
            return p;
        }
    }

    return NULL;
}

//获取val的后继
CNode* Next(CList plist, ElemType val)
{
    CNode* p = Search(plist, val);
    if (p == NULL)
    {
        return NULL;
    }

    return p->next;
}

//输出plist的所有数据
void Show(CList plist)
{
    for (CNode* p = plist->next; p != plist; p = p->next)
    {
        printf("%d ", p->data);
    }
    putchar('\n');
}

//清空数据
void Clear(CList plist)
{
    Destroy(plist);
}

//销毁
void Destroy(CList plist)
{
    CNode* p;
    while (plist->next != plist)
    {
        p = plist->next;
        plist->next = p->next;
        free(p);
    }
}