#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "Lstack.h"

//栈的初始化
void InitStack(PLStack ps)
{
    assert(ps != NULL);
    if (ps == NULL)
    {
        return;
    }
    ps->top = NULL; // 不带头节点
}

//入栈
bool Push(PLStack ps, ElemType val)
{
    LNode* p = (LNode*)malloc(sizeof(LNode));
    assert(p != NULL);
    if (p == NULL)
    {
        return false;
    }
    p->data = val;

    // 把top插入到p的后面
    p->next = ps->top;
    // top指向新的节点
    ps->top = p;

    return true;
}

//判空
bool IsEmpty(PLStack ps)
{
    return ps->top == NULL;
}

//获取栈顶元素的值,但不删除栈顶元素
// rtval:是输出参数
bool GetTop(PLStack ps, int* rtval);

//获取栈顶元素的值,且删除
bool Pop(PLStack ps, int* rtval)
{
    assert(ps != NULL);
    if (ps == NULL)
    {
        return false;
    }
    if (IsEmpty(ps))
    {
        return false;
    }

    // 获取栈顶值
    *rtval = ps->top->data;
    // 保存需要删除的节点地址
    LNode* p = ps->top;
    // top指向新的栈顶
    ps->top = p->next;
    // 删除旧的栈顶
    free(p);

    return true;
}

//销毁
void Destroy(PLStack ps);