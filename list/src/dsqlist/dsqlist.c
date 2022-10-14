#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "dsqlist.h"

static bool IsFull(PDSQList ps);
static bool Inc(PDSQList ps);

//初始化
void InitDsqlist(PDSQList ps)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return;
    }

    ps->elem = (int*)malloc(sizeof(int) * INIT_SIZE);
    assert(NULL != ps->elem);
    ps->length = 0;
    ps->list_size = INIT_SIZE;
}

//插入数据，在ps顺序表的pos位置插入val
bool Insert(PDSQList ps, int pos, int val)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return false;
    }

    if (IsFull(ps))
    {
        Inc(ps);
    }

    // pos >= ps->length error
    if (pos < 0 || pos >= ps->list_size)
    {
        return false;
    }

    //将插入位置后面的数据移动到后面
    for (int i = ps->length - 2; i >= pos; i--)
    {
        ps->elem[i + 1] = ps->elem[i];
    }
    //插入数据
    ps->elem[pos] = val;
    //有效位数++
    ps->length++;

    return true;
}

//判满
static bool IsFull(PDSQList ps)
{
    return ps->length == ps->list_size;
}

//判空
bool IsEmpty(PDSQList ps)
{
    return ps->length == 0;
}

//扩容
static bool Inc(PDSQList ps)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return false;
    }

    ps->elem = (int*)realloc(ps->elem, sizeof(int) * ps->list_size * 2);
    assert(NULL != ps->elem);
    ps->list_size *= 2;

    return true;
}

//在ps中查找第一个val，找到并返回下标，未找到则返回-1
int Search(PDSQList ps, int val)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return false;
    }

    for (int i = 0; i < ps->length; i++)
    {
        if (val == ps->elem[i])
        {
            return i;
        }
    }

    return -1;
}

//删除pos位置的值
bool DelPos(PDSQList ps, int pos)
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

    for (int i = pos; i + 1 < ps->length; i++)
    {
        ps->elem[i] = ps->elem[i + 1];
    }
    ps->length--;

    return true;
}

//删除第一个val的值
bool DelVal(PDSQList ps, int val)
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
    } else
    {
        return DelPos(ps, pos);
    }
}

//返回val的前驱下标，如果不存在返回-1
int GetPrio(PDSQList ps, int val)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return -1;
    }

    int pos = Search(ps, val);
    if (pos <= 0)
    {
        return -1;
    } else
    {
        return pos - 1;
    }
}

//返回val的后继下标，如果不存在返回-1
int GetNext(PDSQList ps, int val)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return -1;
    }

    int pos = Search(ps, val);
    if (pos < 0 || pos == ps->length - 1)
    {
        return -1;
    } else
    {
        return pos + 1;
    }
}

//输出
void Show(PDSQList ps)
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
void Clear(PDSQList ps)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return;
    }
    ps->length = 0;
}

//销毁整个内存
void Destroy(PDSQList ps)
{
    assert(NULL != ps);
    if (NULL == ps)
    {
        return;
    }
    free(ps->elem);
    //预防重复调用
    ps->elem = NULL;
    ps->length = 0;
    ps->list_size = 0;
    // ps = NULL; //无效代码
}