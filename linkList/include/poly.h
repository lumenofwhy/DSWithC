#include <stdbool.h>
#include <stdio.h>
#pragma once

typedef struct
{
    float coef; //系数
    int expn;   //指数
} trem, ElemType;

typedef struct PNode
{
    ElemType data;      //数据 (系数+指数)
    struct PNode* next; //后继指针
} PNode, *Poly;

//初始化带头结点多项式
void InitPoly(Poly po);

//往po多项式插入数据val,按照指数升序
bool Insert(Poly po, ElemType val);

// po1 = po1 + po2;
bool Add(Poly po1, Poly po2);

bool Sub(Poly po1, Poly po2);

//输出多项式
void Show(Poly po);

//销毁多项式po
void Destroy(Poly po);