#include <stdio.h>
#include "insertSort.h"

void InsertSort(int* arr, int len)
{
    // O(n²)
    // 正序查找位置
    int tmp;
    int i;
    int j;
    for (i = 1; i < len; i++)
    {
        // 从第二个数开始处理
        tmp = arr[i];
        for (j = 0; j < i; j++)
        {
            // 找到合适的位置
            if (arr[j] > tmp)
            {
                break;
            }
        }
        // 把后面的数据往后移动
        for (int k = i - 1; k >= j; k--)
        {
            arr[k + 1] = arr[k];
        }
        arr[j] = tmp;
    }
}

void InsertSort2(int* arr, int len)
{
    // O(n²)，最好的情况：O(n)
    // 空间复杂度：O(1)
    int j;
    int tmp;
    for (int i = 1; i < len; i++)
    {
        // 从第二个数开始处理
        tmp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            // 找到合适的位置
            if (arr[j] > tmp) // 后移arr[j]
            {
                arr[j + 1] = arr[j];
            } else
            {
                break;
            }
        }
        arr[j + 1] = tmp;
    }
}
