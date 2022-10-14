#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "sqqueue.h"

//队列初始化
void InitQueue(PSqQueue pq)
{
    assert(pq != NULL);
    if (pq == NULL)
    {
        return;
    }

    // pq->base; // 不需要处理
    pq->front = 0;
    pq->rear = 0;
}

static bool IsFull(PSqQueue pq)
{
    return (pq->rear + 1) % MAXSIZE == pq->front;
}

//入队
bool Push(PSqQueue pq, ElemType val)
{
    if (IsFull(pq))
    {
        return false;
    }
    pq->base[pq->rear] = val;
    // pq->rear++; //error,需要环形处理
    pq->rear = (pq->rear + 1) % MAXSIZE;

    return true;
}

//判空
bool IsEmpty(PSqQueue pq)
{
    return pq->front == pq->rear;
}

//获取队头元素,但不删除
bool GetHead(PSqQueue pq, ElemType* rtval)
{
    if (IsEmpty(pq))
    {
        return false;
    }
    *rtval = pq->base[pq->front];

    return true;
}

//出队,获取队头元素,且删除
bool DeQueue(PSqQueue pq, ElemType* rtval)
{
    if (IsEmpty(pq))
    {
        return false;
    }
    *rtval = pq->base[pq->front];
    pq->front = (pq->front + 1) % MAXSIZE; //环形处理

    return true;
}

//销毁
void Destroy(PSqQueue pq)
{
    return;
}
