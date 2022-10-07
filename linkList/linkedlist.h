#include <stdbool.h>
#pragma once

typedef int ElemType;

typedef struct Node
{
    ElemType data;     //数据
    struct Node* next; //后继指针
} Node, *NodeList;

//初始化plist
void InitList(NodeList plist);

//往plist中头部插入数字val
bool Insert_head(NodeList plist, ElemType val);

//往plist中的尾部插入数字val
bool Insert_tail(NodeList plist, ElemType val);

//在plist中查找val值,找到返回该节点地址,失败返回NULL
Node* Search(NodeList plist, ElemType val);

//删除plist中的第一个val
bool DeleteVal(NodeList plist, ElemType val);

//判断plist是否为空链表(没有数据节点)
bool IsEmpty(NodeList plist);

//获取plist长度,数据节点的个数
int GetLength(NodeList plist);

//获取plist链表的pos位置的值
// int GetElem(NodeList plist, int pos); //设计有误：无法清晰表示出错
bool GetElem(NodeList plist, int pos, int* rtval);

//获取val的前驱
Node* Prior(NodeList plist, ElemType val);

//获取val的后继
Node* Next(NodeList plist, ElemType val);

//输出plist的所有数据
void Show(NodeList plist);

//清空数据
void Clear(NodeList plist);

//销毁
void Destroy(NodeList plist);