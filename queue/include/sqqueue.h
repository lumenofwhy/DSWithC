#pragma once
#include <stdbool.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct SqQueue
{
    ElemType base[MAXSIZE];
    int front; //队头指针,实际是下标
    int rear;  //队尾指针,实际是下标,当前可以存放数据的下标
} SqQueue, *PSqQueue;

//队列初始化
void InitQueue(PSqQueue pq);

//入队
bool Push(PSqQueue pq, ElemType val);

//判空
bool IsEmpty(PSqQueue pq);

//获取队头元素,但不删除
bool GetHead(PSqQueue pq, ElemType* rtval);

//出队,获取队头元素,且删除
bool DeQueue(PSqQueue pq, ElemType* rtval);

//销毁
void Destroy(PSqQueue pq);
