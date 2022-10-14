#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "poly.h"

//初始化带头结点多项式
void InitPoly(Poly po)
{
    assert(po != NULL);
    if (po == NULL)
    {
        return;
    }
    po->next = NULL;
}

static PNode* SearchPrior(Poly po, int expn)
{
    PNode* p;
    for (p = po; p->next != NULL; p = p->next)
    {
        if (p->next->data.expn == expn)
        {
            return p;
        } else if (p->next->data.expn > expn)
        {
            return p;
        }
    }

    return p;
}

//往po多项式插入数据val,按照指数升序
bool Insert(Poly po, ElemType val)
{
#define EPS 0.0000001
    if (-EPS <= val.coef && val.coef <= EPS)
    {
        return false;
    }

    PNode* p = SearchPrior(po, val.expn);
    PNode* q = p->next;
    if (q != NULL && q->data.expn == val.expn)
    {
        q->data.coef += val.coef;
        if (-EPS <= q->data.coef && q->data.coef <= EPS)
        {
            p->next = q->next;
            free(q);
        }
    } else // 增加新节点
    {
        q = (PNode*)malloc(sizeof(PNode));
        assert(q != NULL);
        if (q == NULL)
        {
            return false;
        }
        q->data = val;

        q->next = p->next;
        p->next = q;
    }

    return true;
}

// po1 = po1 + po2;
bool Add(Poly po1, Poly po2)
{
    for (PNode* p = po2->next; p != NULL;)
    {
        Insert(po1, p->data);
    }

    return true;
}

bool Sub(Poly po1, Poly po2);

//输出多项式
void Show(Poly po)
{
    for (PNode* p = po->next; p != NULL; p = p->next)
    {
        printf("%4.1fx^%d + ", p->data.coef, p->data.expn);
    }
    putchar('\n');
}

//销毁多项式po
void Destroy(Poly po);