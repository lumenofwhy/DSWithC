#pragma once
#include <stdbool.h>
#define INIT_SIZE 10

typedef struct dsqlist
{
    int* elem;     //动态内存的地址
    int length;    //有效数据的个数
    int list_size; //总容量
} DSQList, *PDSQList;

//初始化
void InitDsqlist(PDSQList ps);

//插入数据，在ps顺序表的pos位置插入val
bool Insert(PDSQList ps, int pos, int val);

//判空
bool IsEmpty(PDSQList ps);

//在ps中查找第一个val，找到并返回下标，未找到则返回-1
int Search(PDSQList ps, int val);

//删除pos位置的值
bool DelPos(PDSQList ps, int pos);

//删除第一个val的值
bool DelVal(PDSQList ps, int val);

//返回val的前驱下标，如果不存在返回-1
int GetPrio(PDSQList ps, int val);

//返回val的后继下标，如果不存在返回-1
int GetNext(PDSQList ps, int val);

//输出
void Show(PDSQList ps);

//清空数据
void Clear(PDSQList ps);

//销毁整个内存
void Destroy(PDSQList ps);