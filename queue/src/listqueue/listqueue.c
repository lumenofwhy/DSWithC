#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "listqueue.h"

//队列初始化
void InitQueue(LinkQueue* pq)
{
    assert(pq != NULL);
    if (pq == NULL)
    {
        return;
    }
    pq->front = NULL;
    pq->rear = NULL;
}

//入队
bool Push(LinkQueue* pq, ElemType val)
{
    // O(1)
    QNode* p = (QNode*)malloc(sizeof(QNode));
    assert(p != NULL);
    if (p == NULL)
    {
        return false;
    }
    p->data = val;
    p->next = NULL;

    // 插入新节点
    if (!IsEmpty(pq)) // 不是第一次插入的情况
    {
        pq->rear->next = p;
        pq->rear = p;
    } else
    {
        pq->front = p;
        pq->rear = p;
    }

    return true;
}

//判空
bool IsEmpty(LinkQueue* pq)
{
    return pq->front == NULL;
}

//获取队头元素,但不删除
bool GetHead(LinkQueue* pq, ElemType* rtval)
{
    if (IsEmpty(pq))
    {
        return false;
    }
    *rtval = pq->front->data;

    return true;
}

//出队,获取队头元素,且删除
bool DeQueue(LinkQueue* pq, ElemType* rtval)
{
    if (IsEmpty(pq))
    {
        return false;
    }
    *rtval = pq->front->data;

    QNode* p = pq->front;
    // 剔除p
    pq->front = p->next;
    free(p);
    if (pq->front == NULL)
    {
        pq->rear = NULL;
    }

    return true;
}

//销毁
void Destroy(LinkQueue* pq)
{
    QNode* p;
    while (pq->front != NULL)
    {
        p = pq->front;
        pq->front = p->next;
        free(p);
    }
    pq->rear = NULL;
}