#include <stdbool.h>
#pragma once

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode;

typedef struct LStack
{
    LNode* top; //栈顶指针
} LStack, *PLStack;

//栈的初始化
void InitStack(PLStack ps);

//入栈
bool Push(PLStack ps, ElemType val);

//判空
bool IsEmpty(PLStack ps);

//获取栈顶元素的值,但不删除栈顶元素
// rtval:是输出参数
bool GetTop(PLStack ps, int* rtval);

//获取栈顶元素的值,且删除
bool Pop(PLStack ps, int* rtval);

//销毁
void Destroy(PLStack ps);