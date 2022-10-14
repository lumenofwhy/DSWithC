#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "sqlist.h"

//初始化
void InitSqlist(PSQList ps)
{
    assert(ps != NULL);
    if (NULL == ps)
    {
        return;
    }

    ps->length = 0;
}

static bool IsFull(PSQList ps)
{
    return ps->length == SQLLEN;
}

//插入数据，在ps顺序表的pos位置插入val
bool Insert(PSQList ps, int pos, int val)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return false;
    }

    if (pos < 0 || pos >= SQLLEN || IsFull(ps))
    {
        return false;
    }
    //将插入位置后面的数据移动到后面
    for (int i = ps->length - 1; i >= pos; i--)
    {
        ps->elem[i + 1] = ps->elem[i];
    }
    //插入数据
    ps->elem[pos] = val;
    //有效位数++
    ps->length++;

    return true;
}

//判空
bool IsEmpty(PSQList ps)
{
    return ps->length == 0;
}

//在ps中查找第一个val，找到并返回下标，未找到则返回-1
int Search(PSQList ps, int val)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return -1;
    }

    for (int i = 0; i < ps->length; i++)
    {
        if (ps->elem[i] == val)
        {
            return i;
        }
    }

    return -1;
}

//删除pos位置的值
bool DelPos(PSQList ps, int pos)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return false;
    }

    if (pos < 0 || pos >= ps->length || IsEmpty(ps))
    {
        return false;
    }

    //从pos位置依次覆盖前面的数据
    for (int i = pos; i + 1 < ps->length; i++)
    {
        ps->elem[i] = ps->elem[i + 1];
    }
    //有效位数--
    ps->length--;

    return true;
}

//删除第一个val的值
bool DelVal(PSQList ps, int val)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return false;
    }

    int pos = Search(ps, val);

    if (pos < 0)
    {
        return false;
    }

    return DelPos(ps, pos);
}

//返回val的前驱下标，如果不存在返回-1
int GetPrio(PSQList ps, int val)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return false;
    }

    int pos = Search(ps, val);

    if (pos <= 0) //头没有前驱
    {
        return -1;
    } else
    {
        return pos - 1;
    }
}

//返回val的后继下标，如果不存在返回-1
int GetNext(PSQList ps, int val)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return false;
    }

    int pos = Search(ps, val);

    if (pos < 0 || pos == ps->length - 1) //尾没有后继
    {
        return -1;
    } else
    {
        return pos + 1;
    }
}

//输出
void Show(PSQList ps)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return;
    }

    for (int i = 0; i < ps->length; i++)
    {
        printf("%d ", ps->elem[i]);
    }
    putchar('\n');
}

//清空数据
void Clear(PSQList ps)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return;
    }

    ps->length = 0;
}

//销毁整个内存
void Destroy(PSQList ps)
{
    Clear(ps);
}