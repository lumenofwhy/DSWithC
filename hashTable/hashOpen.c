#include <stdio.h>
#include "hashOpen.h"

//计算key的哈希值,哈希函数为H(key)=key%HASHNUM;
static int H(int key)
{
    return key % HASHNUM;
}

//初始化哈希表,NONE 表示哈希表没有被使用
void InitHashTable(HashTable ht)
{
    for (int i = 0; i < MAXHASHSIZE; i++)
    {
        ht[i].key = NONE;
    }
}

//将key插入到哈希表ht中,成功返回true,失败返回false;
bool Insert(HashTable ht, int key)
{
    int hi = H(key); //得到key的哈希值
    if (ht[hi].key == NONE)
    {
        ht[hi].key = key;
        return true;
    } else //在其他位置找合适的位置
    {
        for (int d = 1; d < MAXHASHSIZE; d++)
        {
            int newHi = (hi + d) % MAXHASHSIZE; //新的位置
            if (ht[newHi].key == key)           // key已经存在,不再另外存储
            {
                return true;
            } else if (ht[newHi].key == NONE)
            {
                ht[newHi].key = key;
                return true;
            }
        }
        return false; //存满,没有空位
    }
}

//在哈希表中查找key,找到返回下表,失败返回-1
int Search(const HashTable ht, int key)
{
    int hi = H(key);
    for (int i = 0; i < MAXHASHSIZE; i++)
    {
        int newHi = (hi + i) % MAXHASHSIZE;
        if (ht[newHi].key == key)
        {
            return newHi;
        } else if (ht[newHi].key == NONE) //没有找到
        {
            break;
        }
    }
    return -1;
}

//从头到尾输出ht的所有值
void Show(HashTable ht)
{
    for (int i = 0; i < MAXHASHSIZE; i++)
    {
        printf("%d  ", ht[i].key);
    }
    printf("\n");
}