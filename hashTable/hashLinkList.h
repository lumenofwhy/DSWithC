#pragma once
#include <stdbool.h>
#define MAXHASHSIZE 13 // MAXHASHSIZE个单链表,哈希表的长度

typedef struct _DataType
{
    int key; //关键字项
             // InfoType  otherinfo;//其他数据项
} DataType;  //数据类型

typedef struct _Node
{
    DataType data;      //数据域
    struct _Node* next; //指向下一个节点
} Node;                 //链式地址法中的链表节点

typedef struct
{
    Node* next;           //链表的地址
} HashTable[MAXHASHSIZE]; //哈希表

//初始化哈希表
void InitHashTable(HashTable ht);

//在哈希表中查找key,找到返回节点地址,没有找到返回NULL
Node* Search(const HashTable ht, int key);

//将key插入到哈希表ht中,成功返回true,失败返回false;
bool Insert(HashTable ht, int key);

//从头到位输出ht的所有值
void Show(HashTable ht);