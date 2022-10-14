#pragma once
#include <stdbool.h>
#include <stdio.h>

typedef int ElemType;
typedef struct CNode
{
    ElemType data;
    struct CNode* next;
} CNode, *CList;

//初始化plist
void InitList(CList plist);

//往plist中头部插入数字val
bool Insert_head(CList plist, ElemType val);

//往plist中的尾部插入数字val
bool Insert_tail(CList plist, ElemType val);

//在plist中查找val值,找到返回该节点地址,失败返回NULL
CNode* Search(CList plist, ElemType val);

//删除plist中的第一个val
bool DeleteVal(CList plist, ElemType val);

//判断plist是否为空链表(没有数据节点)
bool IsEmpty(CList plist);

//获取plist长度,数据节点的个数
int GetLength(CList plist);

//获取plist链表的pos位置的值
// int GetElem(CList plist, int pos); //设计有误：无法清晰表示出错
bool GetElem(CList plist, int pos, int* rtval);

//获取val的前驱
CNode* Prior(CList plist, ElemType val);

//获取val的后继
CNode* Next(CList plist, ElemType val);

//输出plist的所有数据
void Show(CList plist);

//清空数据
void Clear(CList plist);

//销毁
void Destroy(CList plist);