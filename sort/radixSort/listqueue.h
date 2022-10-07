/*
 * @Author: Lumen
 * @Date: 2022-01-18 22:18:04
 * @LastEditTime: 2022-02-27 21:20:05
 * @LastEditors: Lumen
 * @Description: 链式队列,队头在首元节点,队尾在尾节点
 * 👻👻👻👻👻👻👻👻
 */
#pragma once
#include <stdbool.h>

typedef int ElemType;
typedef struct QNode //数据节点
{
    ElemType data;
    struct QNode* next;
} QNode, *QueuePtr;

typedef struct
{
    QNode* front; //队头指针
    QNode* rear;  //队尾指针
} LinkQueue;      //头结点的定义

//队列初始化
void InitQueue(LinkQueue* pq);

//入队
bool Push(LinkQueue* pq, ElemType val);

//判空
bool IsEmpty(LinkQueue* pq);

//获取队头元素,但不删除
bool GetHead(LinkQueue* pq, ElemType* rtval);

//出队,获取队头元素,且删除
bool DeQueue(LinkQueue* pq, ElemType* rtval);

//销毁
void Destroy(LinkQueue* pq);