#include <stdbool.h>
#include <stdio.h>
#pragma once
#define INITSIZE 10
typedef int ElemType;

typedef struct
{
    ElemType* base;   //指向存放数据的指针
    ElemType* top;    //栈顶指针,指向当前可以存放数据的地址
    int stacksize;    //栈总容量
} SqStack, *PSqStack; // sizeof(SqStack) == 12;

//栈的初始化
void InitStack(PSqStack ps);

//入栈
bool Push(PSqStack ps, ElemType val);

//判空
bool IsEmpty(PSqStack ps);

//获取栈顶元素的值,但不删除栈顶元素
// rtval:是输出参数
bool GetTop(PSqStack ps, int* rtval);

//获取栈顶元素的值,且删除
bool Pop(PSqStack ps, int* rtval);

//销毁
void Destroy(PSqStack ps);