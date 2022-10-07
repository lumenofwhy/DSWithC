#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "linkedlist.h"

//初始化plist
void InitList(NodeList plist)
{
    assert(plist != NULL);
    plist->next = NULL;
}

//往plist头部插入数字val
bool Insert_head(NodeList plist, ElemType val)
{
    assert(plist != NULL);
    //创建一个新节点
    Node* p = (Node*)malloc(sizeof(Node));
    assert(p != NULL);
    if (p == NULL)
    {
        return false;
    }
    //将新数据存放在新创建的节点
    p->data = val;
    //将新节点插入到头节点的后面
    p->next = plist->next;
    plist->next = p;

    return true;
}

//往plist中的尾部插入数字val
bool Insert_tail(NodeList plist, ElemType val)
{
    assert(plist != NULL);
    //创建一个新节点
    Node* p = (Node*)malloc(sizeof(Node));
    assert(p != NULL);
    if (p == NULL)
    {
        return false;
    }
    p->data = val;
    //创建一个Node指针，指向尾节点
    Node* q;
    for (q = plist; q->next != NULL; q = q->next)
        ;
    //将新节点插入到尾节点的后面，把p插入到q的后面
    p->next = q->next;
    q->next = p;

    return true;
}

//在plist中查找val值,找到返回该节点地址,失败返回NULL
Node* Search(NodeList plist, ElemType val)
{
    for (Node* p = plist->next; p != NULL; p = p->next)
    {
        //遍历链表，寻找待查找节点
        if (p->data == val)
        {
            return p;
        }
    }

    return NULL;
}

//删除plist中的第一个val
bool DeleteVal(NodeList plist, ElemType val)
{
    //找到要删除节点的先驱节点
    Node* p = Prior(plist, val);
    if (p == NULL)
    {
        return false;
    }
    //创建一个指针指向要删除节点（先驱节点的next节点）
    Node* q = p->next;
    //让先驱节点指向要删除节点的下一个节点
    p->next = q->next;
    //释放被删除节点的内存，完成节点的删除
    free(q);

    return true;
}

//判断plist是否为空链表(没有数据节点)
bool IsEmpty(NodeList plist)
{
    return plist->next == NULL;

    /* if (plist->next == NULL)
    {
        return true;
    } else
    {
        return false;
    } */
}

//获取plist长度,数据节点的个数
int GetLength(NodeList plist)
{
    int node_count = 0;
    for (Node* p = plist; p != NULL; p = p->next)
    {
        node_count++;
    }

    return node_count;
}

//获取plist链表的pos位置的值
bool GetElem(NodeList plist, int pos, int* rtval)
{
    if (pos < 0 || pos >= GetLength(plist))
    {
        return false;
    }

    Node* p = plist;
    for (int i = 0; i < pos; i++, p = p->next)
    {
        if (p->next == NULL)
        {
            return false;
        }
    }

    *rtval = p->data;
    return true;
}

//获取val的前驱
Node* Prior(NodeList plist, ElemType val)
{
    for (Node* p = plist; p != NULL; p = p->next)
    {
        if (p->next->data == val)
        {
            return p;
        }
    }

    return NULL;
}

//获取val的后继
Node* Next(NodeList plist, ElemType val)
{
    // val不在链表中则后继为NULL，最后一个节点后继也为NULL
    for (Node* p = plist; p != NULL; p = p->next)
    {
        if (p->data == val)
        {
            return p->next;
        }
    }

    return NULL;
}

//输出plist的所有数据
void Show(NodeList plist)
{
    for (Node* p = plist->next; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    putchar('\n');
}

//清空数据
void Clear(NodeList plist)
{
    Destroy(plist);
}

//销毁
void Destroy(NodeList plist)
{
    if (plist == NULL || plist->next == NULL)
    {
        return;
    }

    Node* q;
    for (Node* p = plist->next; p != NULL;)
    {
        q = p;
        p = p->next;
        free(q);
    }
}