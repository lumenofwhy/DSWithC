#include <stdio.h>
#include "quickSort.h"

int Partition(int* arr, int low, int high) // O(n),O(1)
{
    int tmp = arr[low]; //基准
    while (low < high)
    {
        //从后往前找比基准小的数字,往前移动
        while (low < high && arr[high] > tmp)
        {
            high--;
        }
        if (low < high)
        {
            arr[low] = arr[high];
        }
        //从前往后找比基准大的数据,往后移动
        while (low < high && arr[low] <= tmp)
        {
            low++;
        }
        if (low < high)
        {
            arr[high] = arr[low];
        }
    }
    arr[low] = tmp;
    return low;
}

void Quick(int* arr, int low, int high) // O(nlogn),O(logn),不稳定
{
    int par = Partition(arr, low, high);
    if (low < par - 1) //左边数据超过一个
    {
        Quick(arr, low, par - 1);
    }
    if (par + 1 < high)
    {
        Quick(arr, par + 1, high);
    }
}
void QuickSort(int* arr, int len)
{
    Quick(arr, 0, len - 1);
}
