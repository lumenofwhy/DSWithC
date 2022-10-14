#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hashLinkList.h"

//计算key的哈希值,哈希函数为H(key)=key%MAXHASHSIZE;
static int H(int key)
{
    return key % MAXHASHSIZE;
}

//初始化哈希表
void InitHashTable(HashTable ht)
{
    assert(ht != NULL);
    if (ht == NULL)
    {
        return;
    }
    for (int i = 0; i < MAXHASHSIZE; i++) //将所有的链表置为空链
    {
        ht[i].next = NULL;
    }
}

//在哈希表中查找key,找到返回节点地址,没有找到返回NULL
Node* Search(const HashTable ht, int key)
{
    //计算key的哈希值
    int hi = H(key);
    for (Node* p = ht[hi].next; p != NULL; p = p->next) //遍历哈希表中的链表
    {
        if (p->data.key == key)
        {
            return p;
        }
    }
    return NULL;
}

//将key插入到哈希表ht中,成功返回true,失败返回false;
bool Insert(HashTable ht, int key)
{
    int hi = H(key);
    //判断key是否已经在hash中,如果有则不插入,没有则插入
    if (Search(ht, key) != NULL) // key已经存在
    {
        return false;
    }
    //插入key
    //创建新的节点
    Node* p = (Node*)malloc(sizeof(Node));
    assert(p != NULL);
    p->data.key = key;
    //头插
    p->next = ht[hi].next;
    ht[hi].next = p;

    return true;
}

//从头到位输出ht的所有值
void Show(HashTable ht)
{
    for (int i = 0; i < MAXHASHSIZE; i++)
    {
        printf("哈希值为%d的有:", i);
        for (Node* p = ht[i].next; p != NULL; p = p->next) //遍历当前哈希值的链表
        {
            printf("%d,  ", p->data.key);
        }
        printf("\n");
    }
}