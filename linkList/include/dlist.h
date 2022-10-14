#include <stdbool.h>
#include <stdio.h>
#pragma once

typedef int ElemType;
typedef struct DNode
{
    ElemType data;       //数据
    struct DNode* next;  //后继指针
    struct DNode* prior; //前驱指针
} DNode, *DList;

//初始化plist
void InitList(DList plist);

//往plist中头部插入数字val
bool Insert_head(DList plist, ElemType val);

//往plist中的尾部插入数字val
bool Insert_tail(DList plist, ElemType val);

//在plist中查找val值,找到返回该节点地址,失败返回NULL
DNode* Search(DList plist, ElemType val);

//删除plist中的第一个val
bool DeleteVal(DList plist, ElemType val);

//判断plist是否为空链表(没有数据节点)
bool IsEmpty(DList plist);

//获取plist长度,数据节点的个数
int GetLength(DList plist);

//获取plist链表的pos位置的值
bool GetElem(DList plist, int pos, int* rtval); // rtval:输出参数

//获取val的前驱
DNode* Prior(DList plist, ElemType val);

//获取val的后继
DNode* Next(DList plist, ElemType val);

//输出plist的所有数据
void Show(DList plist);

//清空数据
void Clear(DList plist);

//销毁
void Destroy(DList plist);