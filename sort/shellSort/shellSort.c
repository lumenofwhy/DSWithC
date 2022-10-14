#include <stdio.h>
#include "shellSort.h"
// gap:分组数
void Shell(int* arr, int len, int gap)
{
    int tmp; //保存当前需要处理的值
    int j;
    for (int i = gap; i < len; i++) //从"第二个"元素开始
    {
        tmp = arr[i];
        for (j = i - gap; j >= 0; j -= gap)
        {
            if (arr[j] > tmp)
                arr[j + gap] = arr[j];
            else
                break;
        }
        arr[j + gap] = tmp;
    }
}

void ShellSort(int* arr, int len) // O(n^1.3~n^1.5),O(1),不稳定
{
    int d[] = {5, 3, 1}; //分组组数,注意最后一定是1.缩小增量
    for (long long unsigned int i = 0; i < sizeof(d) / sizeof(d[0]); i++)
    {
        Shell(arr, len, d[i]);
    }
}
