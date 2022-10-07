#pragma once

typedef struct _String
{
    char* data;     // 字符串中的数据
    int currLength; // 字符串的当前长度
    int maxLength;  // 字符串的总长度
} String;

// 字符串朴素匹配
int IndexSimpleMatch(String, String, int);
// 字符串KMP匹配
int IndexKMP(String, String, int);
// 打印自定义串
void PrintString(String);