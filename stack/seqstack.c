#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "seqstack.h"

//栈的初始化
void InitStack(PSqStack ps)
{
    assert(ps != NULL);
    if (ps == NULL)
    {
        return;
    }
    ps->base = (ElemType*)malloc(INITSIZE * sizeof(ElemType));
    ps->top = ps->base;
    ps->stacksize = INITSIZE;
}

static bool IsFull(PSqStack ps)
{
    return (ps->top - ps->base) == ps->stacksize;
}

static void Inc(PSqStack ps)
{
    ps->base = (ElemType*)realloc(ps->base, ps->stacksize * 2 * sizeof(ElemType));
    assert(ps->base != NULL);
    if (ps->base == NULL)
    {
        return;
    }

    ps->top = ps->base + ps->stacksize;
    ps->stacksize *= 2;
}

//入栈
bool Push(PSqStack ps, ElemType val)
{
    if (IsFull(ps))
    {
        Inc(ps);
    }
    *(ps->top) = val;
    ps->top++;

    return true;
}

//判空
bool IsEmpty(PSqStack ps)
{
    return ps->top == ps->base;
}

//获取栈顶元素的值,但不删除栈顶元素
// rtval:是输出参数
bool GetTop(PSqStack ps, int* rtval)
{
    if (IsEmpty(ps))
    {
        return false;
    }
    *rtval = *(ps->top - 1);
    return true;
}

//获取栈顶元素的值,且删除
bool Pop(PSqStack ps, int* rtval)
{
    if (IsEmpty(ps))
    {
        return false;
    }
    *rtval = *(--ps->top);

    return true;
}

//销毁
void Destroy(PSqStack ps)
{
    assert(ps != NULL);
    if (ps == NULL)
    {
        return;
    }

    free(ps->base);
    ps->base = NULL;
    ps->top = NULL;
    ps->stacksize = 0;
}