#pragma once
#include <stdbool.h>
#define MAXHASHSIZE 16 //哈希表的长度
#define HASHNUM 13     //除留余数法的除数,一般是比m小的最大素数,H(key)=key%HASHNUM
#define NONE -1        //当前哈希表为空

typedef struct Hash
{
    int key;
    // InfoType otherinfo;
} Hash, HashTable[MAXHASHSIZE];

//初始化哈希表,NONE 表示哈希表没有被使用
void InitHashTable(HashTable ht);

//将key插入到哈希表ht中,成功返回true,失败返回false;
bool Insert(HashTable ht, int key);

//在哈希表中查找key,找到返回下表,失败返回-1
int Search(const HashTable ht, int key);

//从头到尾输出ht的所有值
void Show(HashTable ht);