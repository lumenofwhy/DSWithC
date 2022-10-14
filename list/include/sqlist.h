#pragma once
#include <stdbool.h>
#define SQLLEN 10

//定长顺序表
typedef struct sqlist
{
    int length;   //有效数据的位数
    int elem[10]; //存放数据，固定长度为10
} SQList, *PSQList;

//初始化
void InitSqlist(PSQList ps);

//插入数据，在ps顺序表的pos位置插入val
bool Insert(PSQList ps, int pos, int val);

//判空
bool IsEmpty(PSQList ps);

//在ps中查找第一个val，找到并返回下标，未找到则返回-1
int Search(PSQList ps, int val);

//删除pos位置的值
bool DelPos(PSQList ps, int pos);

//删除第一个val的值
bool DelVal(PSQList ps, int val);

//返回val的前驱下标，如果不存在返回-1
int GetPrio(PSQList ps, int val);

//返回val的后继下标，如果不存在返回-1
int GetNext(PSQList ps, int val);

//输出
void Show(PSQList ps);

//清空数据
void Clear(PSQList ps);

//销毁整个内存
void Destroy(PSQList ps);